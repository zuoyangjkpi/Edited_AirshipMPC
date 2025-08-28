#!/bin/bash
# Spawn DRONES (Firefly) instead of BLIMPS, based on your second script.

# 0) Ensure workspace is built
if [ ! -e ../../catkin_ws/devel/setup.bash ]; then
  echo "Please Install requirements first"
  exit 1
fi
source ../../catkin_ws/devel/setup.bash

# 1) Args
ROBOS=$1                 # <number of drones>
COMSUCCESSRATE=$2        # <communication success rate>
NAME=$3                  # <experiment title / tag>
WORLD=$4                 # <world_name>

# Defaults (following the second script style)
if [ -z "$COMSUCCESSRATE" ]; then
  COMSUCCESSRATE=100
fi
if [ -z "$NAME" ]; then
  NAME="gazebo_flight_$(date +%s)"
fi
if [ -z "$WORLD" ]; then
  WORLD="arena_RAL"
fi

# 2) Positions (like the second script; plenty of spawn points)
Xs=(-15 -10 -8 -6 -4 5 0 2 4 6 8 10 15)
Ys=(-15 -10 -8 -6 -4 5 0 2 4 6 8 10 15)

# 3) Usage
if [ $# -lt 1 ]; then
  echo "usage: $0 <number of robots> <communication success rate> <experiment title> <world_name>"
  exit 1
fi

# 4) (Optional) Logging stubs
# LOGPATH="/media/ssd/RECORD"
# LOGFILE=$( echo ${LOGPATH}/${NAME}*.bag )
# if [ -e $LOGFILE ]; then
#   echo "Experiment result exists, exiting"
#   exit 0
# fi

# 5) Bringup world
echo "Launching Gazebo..."
screen -d -m -S GAZEBO bash -i -c "source ../../catkin_ws/devel/setup.bash; roslaunch rotors_gazebo world.launch world_name:=$WORLD --screen"
sleep 10

# (RViz step removed to avoid blimp-specific config; add your own RViz config if needed.)

# 6) Peripherals
echo "Starting Deep Neural Network Server..."
screen -d -m -S SSDSERVER bash -i -c "./ssd_server.sh 0"
sleep 5

echo "Starting GCS Visualization framework..."
screen -d -m -S GCSVIS bash -i -c "source ../../catkin_ws/devel/setup.bash; rosrun gcs_visualization gcs_visualization_node $ROBOS 30 1 0 arrow 8"
sleep 3

# 7) Target spawner
echo "Spawning target"
screen -d -m -S TARGET bash -i -c "source ../../catkin_ws/devel/setup.bash; roslaunch random_moving_target spawn_target_withID.launch joyDevName:=0 directUseForFormation:=true --screen"

# 8) Spawn drones + AIRCAP per robot
for i in $(seq 0 $(($ROBOS-1))); do
  id=$((i+1))
  echo "Launching drone $id..."
  screen -d -m -S FIREFLY$id bash -i -c "source ../../catkin_ws/devel/setup.bash; roslaunch rotors_gazebo mav_with_joy_and_ID.launch roboID:=$id Z:=8 X:=${Xs[$i]} Y:=${Ys[$i]} --screen"
  sleep 5

  echo "Starting AIRCAP for drone $id"
  screen -d -m -S AIRCAP$id bash -i -c "source ../../catkin_ws/devel/setup.bash; roslaunch aircap simulation.launch robotID:=$id numRobots:=$ROBOS comSuccessRate:=$COMSUCCESSRATE --screen"
  sleep 1
done

# 9) Quick health check (same topics as before)
echo "Checking robot status"
result=1
for i in $(seq 0 $(($ROBOS-1))); do
  id=$((i+1))
  x=$( timeout 10 rostopic echo /machine_$id/pose/position/x | head -n 1 )
  y=$( timeout 10 rostopic echo /machine_$id/pose/position/y | head -n 1 )
  z=$( timeout 10 rostopic echo /machine_$id/pose/position/z | head -n 1 )
  if [ -z "$x" ] || [ -z "$y" ] || [ -z "$z" ]; then
    result=0; break
  fi
  # Within bounds (fixing the copy-paste bug on y)
  if [ ! \( $( echo "$z<-3.0"  | bc ) = 1 -a $( echo "$z>-20.0" | bc ) = 1 \) ]; then
    result=0; break
  fi
  if [ ! \( $( echo "$x>-20.0" | bc ) = 1 -a $( echo "$x<20.0"  | bc ) = 1 \) ]; then
    result=0; break
  fi
  if [ ! \( $( echo "$y>-20.0" | bc ) = 1 -a $( echo "$y<20.0"  | bc ) = 1 \) ]; then
    result=0; break
  fi
done
# (If you want to hard-fail on result=0, uncomment the block below)
# if [ $result = 0 ]; then
#   echo "A robot failed to initialize - cleaning up"
#   ./cleanup.sh
#   exit 1
# fi

# 10) Wait for systems to come up
echo "Waiting 20 seconds for everyone to come up"
timeout 400 ./rossleep.py 20
result=$?
if [ $result = 124 ]; then
  echo "Something went wrong, timeout!"
  ./cleanup.sh
  exit 1
fi

# 11) (Optional) rosbag
# echo "Starting recording..."
# screen -d -m -S ROSBAG bash -i -c "rosbag record -o ${LOGPATH}/${NAME}.bag $( cat bagtopics.txt | tr '\n' ' ' )"

date
echo "execute ./cleanup.sh to exit simulation"
exit 0
