#!/bin/bash

# Fixed drone simulation script with RViz and proper tracking
# Addresses: 1) RViz not launching 2) Drone not tracking person

# Check if workspace is built
if [ ! -e ../../catkin_ws/devel/setup.bash ]; then
    echo "Please Install requirements first"
    exit 1
fi

source ../../catkin_ws/devel/setup.bash

# Parse arguments
ROBOS=$1                 # number of drones
COMSUCCESSRATE=$2        # communication success rate
NAME=$3                  # experiment title
WORLD=$4                 # world name

# Set defaults
if [ -z "$COMSUCCESSRATE" ]; then
    COMSUCCESSRATE=100
fi

if [ -z "$NAME" ]; then
    NAME="drone_flight_$(date +%s)"
fi

if [ -z "$WORLD" ]; then
    WORLD="arena_RAL"
fi

# Spawn positions (same as setup_mavocap_gazebo.sh)
Xs=(-15 -10 -8 -6 -4 5 0 2 4 6 8 10 15)
Ys=(-15 -10 -8 -6 -4 5 0 2 4 6 8 10 15)

# Usage check
if [ $# -lt 1 ]; then
    echo "usage: $0 <number of drones> [communication success rate] [experiment title] [world_name]"
    echo "example: $0 1"
    echo "example: $0 3 100 test_flight arena_RAL"
    exit 1
fi

echo "Starting drone simulation with $ROBOS drone(s)..."

# 1. Launch Gazebo world
echo "Step 1: Launching Gazebo world: $WORLD..."
screen -d -m -S GAZEBO bash -i -c "source ../../catkin_ws/devel/setup.bash; roslaunch rotors_gazebo world.launch world_name:=$WORLD --screen"
sleep 12

# 2. Launch RViz with appropriate config
echo "Step 2: Launching RViz..."
if [ -f "../../submodules/AirCap/packages/optional/gcs_visualization/config/2machines.rviz" ]; then
    RVIZ_CONFIG="../../submodules/AirCap/packages/optional/gcs_visualization/config/2machines.rviz"
elif [ -f "../../submodules/AirCap/packages/3rdparty/airship_simulation/blimp_description/rviz/3_blimp_nmpc.rviz" ]; then
    RVIZ_CONFIG="../../submodules/AirCap/packages/3rdparty/airship_simulation/blimp_description/rviz/3_blimp_nmpc.rviz"
else
    RVIZ_CONFIG=""
fi

if [ -n "$RVIZ_CONFIG" ]; then
    screen -d -m -S RVIZ bash -i -c "source ../../catkin_ws/devel/setup.bash; rviz -d $RVIZ_CONFIG"
    echo "RViz launched with config: $RVIZ_CONFIG"
else
    screen -d -m -S RVIZ bash -i -c "source ../../catkin_ws/devel/setup.bash; rviz"
    echo "RViz launched with default config"
fi
sleep 5

# 3. Start Deep Neural Network Server for person detection
echo "Step 3: Starting Deep Neural Network Server..."
screen -d -m -S SSDSERVER bash -i -c "source ../../catkin_ws/devel/setup.bash; cd ../../submodules/AirCap/scripts/simulation/; ./ssd_server.sh 0"
sleep 8

# 4. Start GCS Visualization framework
echo "Step 4: Starting GCS Visualization framework..."
screen -d -m -S GCSVIS bash -i -c "source ../../catkin_ws/devel/setup.bash; rosrun gcs_visualization gcs_visualization_node $ROBOS 30 1 0 arrow 8"
sleep 3

# 5. Spawn target (person to track)
echo "Step 5: Spawning target person..."
screen -d -m -S TARGET bash -i -c "source ../../catkin_ws/devel/setup.bash; roslaunch random_moving_target spawn_target_withID.launch joyDevName:=0 directUseForFormation:=true --screen"
sleep 5

# 6. Spawn drones and start AirCap for each
for i in $(seq 0 $(($ROBOS-1))); do
    id=$((i+1))
    
    echo "Step 6.$i: Launching drone $id at position (${Xs[$i]}, ${Ys[$i]}, 8)..."
    screen -d -m -S FIREFLY$id bash -i -c "source ../../catkin_ws/devel/setup.bash; roslaunch rotors_gazebo mav_with_joy_and_ID.launch roboID:=$id Z:=8 X:=${Xs[$i]} Y:=${Ys[$i]} --screen"
    sleep 8

    echo "Step 6.$i: Starting AirCap tracking for drone $id..."
    screen -d -m -S AIRCAP$id bash -i -c "source ../../catkin_ws/devel/setup.bash; roslaunch aircap simulation.launch robotID:=$id numRobots:=$ROBOS comSuccessRate:=$COMSUCCESSRATE --screen"
    sleep 3
done

# 7. Wait for systems to initialize
echo "Step 7: Waiting for complete system initialization..."
sleep 15

# 8. Check system status
echo "Step 8: Checking system status..."

# Check if ROS master is running
if ! rostopic list >/dev/null 2>&1; then
    echo "ERROR: ROS master not running!"
    exit 1
fi

# Check if target is spawned
if rostopic list | grep -q "target"; then
    echo "✓ Target topics found"
else
    echo "⚠ Warning: Target topics not found"
fi

# Check drone status
result=1
for i in $(seq 0 $(($ROBOS-1))); do
    id=$((i+1))
    echo "Checking drone $id..."
    
    # Check if drone topics exist
    if rostopic list | grep -q "/machine_$id"; then
        echo "✓ Drone $id topics found"
    else
        echo "⚠ Warning: Drone $id topics not found"
        result=0
    fi
    
    # Check if tracking topics exist
    if rostopic list | grep -q "/machine_$id/target_tracker"; then
        echo "✓ Drone $id tracking topics found"
    else
        echo "⚠ Warning: Drone $id tracking topics not found"
    fi
done

# 9. Show important topics for debugging
echo ""
echo "Step 9: Important topics for monitoring:"
echo "Target topics:"
rostopic list | grep target | head -5
echo ""
echo "Machine topics:"
rostopic list | grep machine | head -10
echo ""
echo "Detection topics:"
rostopic list | grep detection | head -5

# 10. Final status
echo ""
echo "=========================================="
echo "Drone simulation setup complete!"
echo "=========================================="
echo "Number of drones: $ROBOS"
echo "World: $WORLD"
echo "Communication success rate: $COMSUCCESSRATE%"
echo ""
echo "RViz should be open for visualization"
echo "Gazebo shows the simulation world"
echo ""
echo "To monitor tracking:"
echo "  rostopic echo /machine_1/target_tracker/pose"
echo "  rostopic echo /machine_1/command"
echo ""
echo "To stop simulation:"
echo "  ./cleanup.sh"
echo ""
echo "Active screen sessions:"
screen -ls
echo ""

date
exit 0


