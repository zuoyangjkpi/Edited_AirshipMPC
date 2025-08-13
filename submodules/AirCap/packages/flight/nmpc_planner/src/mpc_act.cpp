#include "../include/mpc_planner_act.h"

void Planner::storeLatestTargetGTPose(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg) // Fused Target Pose
{
 if(!targetEstimationIsActive)   // when it is active, the callback storeLatestTargetEstimatedPose is used.
    targetObjectGTPose = *msg; // GT anyway comes in NED
 else
 {
     //printf("Not using the GT\n");
   if(useGTforTarget)
       targetObjectGTPose = *msg;
 }
}

void Planner::storeLatestTargetGTVelocity(const geometry_msgs::TwistWithCovarianceStamped::ConstPtr& msg) // Fused Target Velocity
{
  if(!targetEstimationIsActive)   // when it is active, the callback storeLatestTargetEstimatedPose is used.
     targetObjectGTVelocity = *msg; // GT anyway comes in NED
  else
  {
      //printf("Not using the GT\n");
    if(useGTforTarget)
        targetObjectGTVelocity = *msg;
  }
}

void Planner::storeLatestTargetEstimatedPose(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg) // Self Target Velocity
{
  if(!targetEstimationIsActive)   // when it is active, the callback storeLatestTargetEstimatedPose is used.
     targetObjectEstimatedPose = *msg; // GT anyway comes in NED
  else
  {
      //printf("Not using the GT\n");
    if(useGTforTarget)
        targetObjectEstimatedPose = *msg;
  }
}

void Planner::storeLatestTargetEstimatedVelocity(const geometry_msgs::TwistWithCovarianceStamped::ConstPtr& msg) // Self Target Velocity
{
  if(!targetEstimationIsActive)   // when it is active, the callback storeLatestTargetEstimatedPose is used.
     targetObjectEstimatedVelocity = *msg; // GT anyway comes in NED
  else
  {
      //printf("Not using the GT\n");
    if(useGTforTarget)
        targetObjectEstimatedVelocity = *msg;
  }
}

void Planner::targetPosCov(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg)
{
  targetDetectionMsg = *msg;
  targetDetected = true;
  int ptr = 0;
  for (int row=0;row<2;row++)
  {
    for (int col=0;col<2;col++)
    {
      selfCovariance(row,col) = targetDetectionMsg.pose.covariance[ptr];
      ptr+=1;
    }
  }

}

double Planner::getPotential(double d, double threshold, double tPotFuncInfD, double tPotFuncGain) const {
        //tPotFuncZeroD = threshold;
  double z;
  if (d < tPotFuncInfD)
      z = (M_PI/2.0)*0.1/ (threshold - tPotFuncInfD);
  else
      z = (M_PI/2.0) *((d - tPotFuncInfD)/ (threshold - tPotFuncInfD));
  double cot_z = cos(z)/sin(z);
  double retValue = (M_PI/2.0) * (1.0 / (threshold - tPotFuncInfD)) *
      (cot_z + z - (M_PI/2.0));
  if (d < threshold)
     return tPotFuncGain * retValue;
  else
     return 0;
}
double Planner::getAttPotential(double d, double threshold, double tPotFuncZeroD, double tPotFuncGain) const {
  double z;
  if (d>tPotFuncZeroD)
    z = 100; //double check this value
  else
    z = (M_PI/2.0) *((threshold - d)/ (threshold - tPotFuncZeroD));
  double cot_z = cos(z)/sin(z);
  double retValue = (M_PI/2.0) * (1.0 / (threshold - tPotFuncZeroD)) *
      (cot_z + z - (M_PI/2.0));
  //      pow((cot_z + z - (M_PI/2.0)),tPotFuncGain);
  if (d >= threshold)
    return tPotFuncGain * retValue;
  else
    return 0;
}
double Planner::getExpPotential(double d, double threshold, double tPotFuncGain)
{
  double f_repel = exp(d)-0.7;
  double retValue = tPotFuncGain*pow(((1/f_repel)-(1/threshold)),1)*(d/f_repel);
  // double retValue = 3*cos(0.05*d);
  if (d < threshold)
    return 0;
  else if (retValue < 0)
    return 0;
  return retValue;
}


Eigen::Vector3d Planner::force_clamping(Eigen::Vector3d force)
{
  if (force.norm() > FORCE_LIMIT) {
     force = (FORCE_LIMIT/(double)force.norm()) * force;
  }
  return force;
}

void Planner::avoidTeamMates_byComputingExtForce()
{
  selfPoseTraj.poses.clear();
  geometry_msgs::Pose tmpPose;
  float xT =  targetObjectGTPose.pose.pose.position.x;
  float yT =  targetObjectGTPose.pose.pose.position.y;
  float x_obs=0,y_obs=0,z_obs=0;
  for(int t=0;t<16;t++)
  {
    bool atLeastOneMatePresent = false;
    Position3D tCurrentSelfPosition(selfPose.pose.pose.position.x,selfPose.pose.pose.position.y,selfPose.pose.pose.position.z);
    if(t==0)
    {
        tCurrentSelfPosition(0) = selfPose.pose.pose.position.x;
        tCurrentSelfPosition(1) = selfPose.pose.pose.position.y;
        tCurrentSelfPosition(2) = selfPose.pose.pose.position.z;
    }
    else
    {
        tCurrentSelfPosition(0) = StateInput(0,t);
        tCurrentSelfPosition(1) = StateInput(2,t);
        tCurrentSelfPosition(2) = StateInput(4,t);

        tmpPose.position.x = StateInput(0,t);
        tmpPose.position.y = StateInput(2,t);
        tmpPose.position.z = StateInput(4,t);
        selfPoseTraj.poses.push_back(tmpPose);
    }
    Position3D virtualPoint = tCurrentSelfPosition;
    Eigen::Vector3d totalForce = Velocity3D::Zero();
    double potentialForce_repulsive ;
    double potentialForce_angular ;
    double attraction_Force ;
    double covariance_radius = 2*sqrt(pow(selfPose.pose.covariance[0] + selfOffset.pose.covariance[0],2)+pow(selfPose.pose.covariance[1] + selfOffset.pose.covariance[1],2));
    Position3D posDiffT (tCurrentSelfPosition(0) - xT,tCurrentSelfPosition(1) - yT,0); // vector away from target
    double targetDist = posDiffT.norm();
    Position3D posDiffTUnit = posDiffT.normalized();
    potentialForce_repulsive = getPotential(targetDist,distanceThresholdToTarget,targetGuaranteeThreshold,50); // away from target
    totalForce += force_clamping((potentialForce_repulsive) * posDiffTUnit);
    double thetaMate;
    double theta;
    double thetaDiff;
    for(int j=0; j<=numRobots_-1; j++)
    {
      if(heardFromMates[j])
      {
        atLeastOneMatePresent = true;
        Position3D matePosition(matesPoses[j].pose.position.x,matesPoses[j].pose.position.y,matesPoses[j].pose.position.z);

        if(t!=0 && heardFromMateTrajs[j])
        {
            matePosition(0) = matesPoseTrajs[j].poses[t-1].position.x;
            matePosition(1) = matesPoseTrajs[j].poses[t-1].position.y;
            matePosition(2) = matesPoseTrajs[j].poses[t-1].position.z;
        }
        else
        {
            matePosition(0) = matesPoses[j].pose.position.x;
            matePosition(1) = matesPoses[j].pose.position.y;
            matePosition(2) = matesPoses[j].pose.position.z;
        }

        // Repulsive Field
        Position3D posDiff = virtualPoint - matePosition;
        posDiff(2) = 0; //@HACK : 2-D distance only
        double neighborDist = posDiff.norm();
        Position3D posDiffUnit = posDiff.normalized();

        double comm_failure_time_secs = (ros::Time::now() - matesPoses[j].header.stamp).toSec();
        double comm_failure_dilation = copterVelocityLimitX*comm_failure_time_secs*deltaT;
        double obstacleAvoidanceThreshold = maxOffsetUncertaintyRadius + covariance_radius + comm_failure_dilation;
        // ROS_INFO("obstacleAvoidanceThreshold : %f", obstacleAvoidanceThreshold);
        potentialForce_repulsive = getPotential(neighborDist,obstacleAvoidanceThreshold,neighborGuaranteeThreshold,50); //away from neighbor
        totalForce +=  force_clamping((potentialForce_repulsive) * posDiffUnit);


        // // Angular Field
         Vector2D mate2target(matePosition(0)-xT,matePosition(1)-yT);
         Vector2D self2target(tCurrentSelfPosition(0)-xT,tCurrentSelfPosition(1)-yT);

         thetaMate = atan2(mate2target(1),mate2target(0));
         theta = atan2(self2target(1),self2target(0));

         thetaMate = thetaMate ? thetaMate : 2*PI + thetaMate;
         theta = theta ? theta : 2*PI + theta;

         thetaDiff = abs(theta-thetaMate);

        if (thetaDiff > PI)
          {
            thetaDiff = pow(2*PI - thetaDiff,2);
          }

        else
        {
          thetaDiff = pow(thetaDiff,2);
        }
        // ROS_INFO("thetaDiff: %f, mateID:%d", temp*180/PI,j);
        if (numRobots_ == 2) 
          {
            potentialForce_angular = getPotential(thetaDiff,pow((PI/(numRobots_)),2),pow(activeGuaranteeThreshold,2),50);
            attraction_Force = getAttPotential(thetaDiff, (PI+2,2), pow((PI/(numRobots_)),2), 50);
           } 
        else 
        {
            potentialForce_angular = getPotential(thetaDiff,pow((2*PI/numRobots_),2),pow(activeGuaranteeThreshold,2),50);
         }
        
        Position3D tangent(-posDiffT(1),posDiffT(0),0);
        Position3D tangentNeg(posDiffT(1),-posDiffT(0),0);
        Position3D tangentUnit = tangent.normalized();
        Position3D tangentUnitNeg = tangentNeg.normalized();
        double c = 1; //small constant for non-zero surface active tracking force
        
        if (posDiffUnit.dot(tangentUnit) > posDiffUnit.dot(tangentUnitNeg))
          {
          totalForce += force_clamping((potentialForce_angular) * tangentUnit *  (abs(targetDist - r)+c) );
          if (numRobots_== 2)
            {totalForce += force_clamping((attraction_Force) * tangentUnitNeg *  1/(abs(targetDist - r)+c) );}
          }
          // totalForce += (potentialForce_angular) * tangentUnit *  0;
        else
          {
          totalForce += force_clamping((potentialForce_angular) * tangentUnitNeg *  (abs(targetDist - r)+c)) ;
          if (numRobots_ == 2)
            {totalForce += force_clamping((attraction_Force) * tangentUnit *  1/(abs(targetDist - r)+c) );}
          }
          // totalForce += (potentialForce_angular) * tangentUnitNeg *  0  ;
      }
    }
    // ROS_INFO("");

    //Emulated Point Cloud
    // if (obstaclesFromRobots.poses.size()>0)
    // {
    //   for (int i=0; i < obstaclesFromRobots.poses.size(); i++)
    //   {
    //       x_obs = obstaclesFromRobots.poses[i].position.x;
    //       y_obs = -obstaclesFromRobots.poses[i].position.y;
    //       z_obs = -obstaclesFromRobots.poses[i].position.z;
    //
    //       Position3D matePosition(x_obs,y_obs,z_obs);
    //       // Repulsive Field
    //       Position3D posDiff = virtualPoint - matePosition;
    //       posDiff(2) = 0; //@HACK : 2-D distance only
    //       double neighborDist = posDiff.norm();
    //       Position3D posDiffUnit = posDiff.normalized();
    //
    //       double potentialForce_repulsive = 0.0;
    //
    //       //total repulsive force
    //       potentialForce_repulsive = getPotential(neighborDist,3,0.4,50);
    //       totalForce += force_clamping((potentialForce_repulsive) * posDiffUnit * 0.1);
    //       if (neighborDist < 3)
    //       {
    //         double thetaMate = atan2(matePosition(1)-yT,matePosition(0)-xT) ? atan2(matePosition(1)-yT,matePosition(0)-xT) : 2*PI + atan2(matePosition(1)-yT,matePosition(0)-xT);
    //         double theta = atan2(tCurrentSelfPosition(1)-yT,tCurrentSelfPosition(0)-xT) ? atan2(tCurrentSelfPosition(1)-yT,tCurrentSelfPosition(0)-xT) : 2*PI + atan2(tCurrentSelfPosition(1)-yT,tCurrentSelfPosition(0)-xT);
    //
    //         double thetaDiff = abs(theta-thetaMate);
    //        // double temp = thetaDiff;
    //
    //        if (thetaDiff > PI)
    //        {
    //          thetaDiff = pow(2*PI - thetaDiff,2);
    //          // temp = 2*PI - temp;
    //        }
    //
    //        else
    //        {
    //          thetaDiff = pow(thetaDiff,2);
    //        }
    //        // ROS_INFO("thetaDiff: %f, mateID:%d", temp*180/PI,j);
    //        potentialForce_angular = getPotential(thetaDiff,pow(0.5,2),0,1);
    //
    //        Position3D tangent(-posDiffT(1),posDiffT(0),0);
    //        Position3D tangentUnit = tangent.normalized();
    //        totalForce += force_clamping((potentialForce_angular) * tangentUnit * 0.1 );
    //      }
    //       // ROS_INFO("neighborDist: %f", neighborDist);
    //   }
    // }

    if  (POINT_OBSTACLES)
    {

      for (int i=0; i < obstacles_length; i++)
      {
        x_obs = obstacles_y[i];
        y_obs = obstacles_x[i];
        z_obs = 0;
        Position3D matePosition(x_obs,y_obs,z_obs);
        Position3D posDiff = virtualPoint - matePosition;
        posDiff(2) = 0; //@HACK : 2-D distance only
        double neighborDist = posDiff.norm();
        Position3D posDiffUnit = posDiff.normalized();
        potentialForce_repulsive = getPotential(neighborDist,neighborDistThreshold+covariance_radius,obstacleGuaranteeThreshold,50);
        totalForce += force_clamping((potentialForce_repulsive) * posDiffUnit );
        // if (neighborDist <= 3)
        {
          double thetaMate = atan2(matePosition(1)-yT,matePosition(0)-xT) ? atan2(matePosition(1)-yT,matePosition(0)-xT) : 2*PI + atan2(matePosition(1)-yT,matePosition(0)-xT);
          double theta = atan2(tCurrentSelfPosition(1)-yT,tCurrentSelfPosition(0)-xT) ? atan2(tCurrentSelfPosition(1)-yT,tCurrentSelfPosition(0)-xT) : 2*PI + atan2(tCurrentSelfPosition(1)-yT,tCurrentSelfPosition(0)-xT);

          double thetaDiff = abs(theta-thetaMate);
         // double temp = thetaDiff;

         if (thetaDiff > PI)
           {
             thetaDiff = pow(2*PI - thetaDiff,2);
             // temp = 2*PI - temp;
           }

         else
         {
           thetaDiff = pow(thetaDiff,2);
         }
         // ROS_INFO("thetaDiff: %f, mateID:%d", temp*180/PI,j);
         potentialForce_angular = getPotential(thetaDiff,pow(approachAngleThreshold,2),pow(activeGuaranteeThreshold,2),50);

         Position3D tangent(-posDiffT(1),posDiffT(0),0);
         Position3D tangentUnit = tangent.normalized();
         totalForce += force_clamping((potentialForce_angular) * tangentUnit);
       }
        // ROS_INFO("neighborDist: %f", neighborDist);
      }
    }

    if(std::isfinite(totalForce.norm()))
    {
      obstacle_force(0,t) = totalForce(0);
      obstacle_force(1,t) = totalForce(1);
      obstacle_force(2,t) = 0;
      // ROS_INFO("total force x:%f, y:%f",totalForce(0),totalForce(1));
    }
    else
    {
      obstacle_force(0,t) = 0;
      obstacle_force(1,t) = 0;
      obstacle_force(2,t) = 0;
    }
  }
}

void Planner::updateObstaclesCallback(const geometry_msgs::PoseArray::ConstPtr& msg, int robID)
{
  obstaclesFromRobots = *msg;
}

void Planner::selfOffsetCallback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg, int robID)
{
  selfOffset = *msg;
}

void Planner::matePoseCallback(const geometry_msgs::PoseStamped::ConstPtr& msg, int robID)
{
  //note that robID follows the 1-base, not zero base
  matePose = *msg;
  matesPoses[robID-1] = *msg;
  Position3D tCurrentSelfPosition(selfPose.pose.pose.position.x,selfPose.pose.pose.position.y,selfPose.pose.pose.position.z);
  Position3D tCurrentMatePosition(matePose.pose.position.x,matePose.pose.position.y,matePose.pose.position.z);


  // HACK TO SIMULATE COMMUNICATION RADIUS
  // if ((tCurrentSelfPosition - tCurrentMatePosition).norm() <= neighborDistThreshold )
  // {
    heardFromMate=true;
    heardFromMates[robID-1] = true;
    // ROS_INFO(" mateID:%d",robID-1);
  // }
  // else
  // {
  //   heardFromMate=false;
  //   heardFromMates[robID-1] = false;
  // }

}

void Planner::matePoseTrajectoryCallback(const geometry_msgs::PoseArray::ConstPtr& msg, int robID)
{
  matesPoseTrajs[robID-1] = *msg;
  heardFromMateTrajs[robID-1] = true;
}

double Planner::quat2eul(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& queryPose)
{
    geometry_msgs::PoseWithCovarianceStamped queryPose_ = *queryPose;
    tf::Quaternion q(
        queryPose_.pose.pose.orientation.x,
        queryPose_.pose.pose.orientation.y,
        queryPose_.pose.pose.orientation.z,
        queryPose_.pose.pose.orientation.w);
    tf::Matrix3x3 m(q);
    double selfRoll, selfPitch, selfYaw;
    m.getRPY(selfRoll, selfPitch, selfYaw);
    return selfYaw;
}

void Planner::selfPoseCallback(const uav_msgs::uav_pose::ConstPtr& msg, int robID) //most important -- self nmpc
{
    outPoseModifiedToRviz.header = msg->header;
    outPoseModifiedToRviz.header.frame_id = "world";
    outPoseToRviz.header = msg->header;
    outPoseToRviz.header.frame_id = "world";

    selfPose.header = msg->header;
    selfPose.pose.pose.position = msg->position;
    selfPose.pose.pose.orientation = msg->orientation;
    ///@HACK change NED to NWU ... this is a hack... make more elegant
    // selfPose.pose.pose.position.y = -selfPose.pose.pose.position.y;
    // selfPose.pose.pose.position.z = -selfPose.pose.pose.position.z;

    r = distanceThresholdToTarget; // keep 2 m fro the target

    // Initialization of fused mean and self mean for a horizon
    for(int k=0;k<16;k++)
    {
      targetFusedState(0,k) = targetObjectGTPose.pose.pose.position.x + 0*targetObjectGTVelocity.twist.twist.linear.x * INTERNAL_SUB_STEP;
      targetFusedState(1,k) = (targetObjectGTPose.pose.pose.position.y + 0*targetObjectGTVelocity.twist.twist.linear.y * INTERNAL_SUB_STEP );

      targetEstimatedState(0,k) = targetObjectEstimatedPose.pose.pose.position.x + 0*targetObjectEstimatedVelocity.twist.twist.linear.x * INTERNAL_SUB_STEP;
      targetEstimatedState(1,k) = (targetObjectEstimatedPose.pose.pose.position.y + 0*targetObjectEstimatedVelocity.twist.twist.linear.y * INTERNAL_SUB_STEP);

      targetFusedState(3,k) = targetObjectGTVelocity.twist.twist.linear.x;
      targetFusedState(4,k) = targetObjectGTVelocity.twist.twist.linear.y;

      targetMeanDiffSquared(k) = activeTrackingWeight + (targetFusedState(0,k) - targetEstimatedState(0,k))*(targetFusedState(0,k) - targetEstimatedState(0,k)) +
                                 (targetFusedState(1,k) - targetEstimatedState(1,k))*(targetFusedState(1,k) - targetEstimatedState(1,k));
      // ROS_INFO("targetMeanDiffSquared: %f",targetMeanDiffSquared(k));
    }

    x1 = selfPose.pose.pose.position.x;
    y1 = selfPose.pose.pose.position.y;


    if(useZeroAsFixedTarget)
    {
        x3 = 0.0;
        y3 = 0.0;
    }
    else
    {
      x3 =  targetObjectGTPose.pose.pose.position.x+0*targetObjectGTVelocity.twist.twist.linear.x*INTERNAL_SUB_STEP;
      y3 =  targetObjectGTPose.pose.pose.position.y+0*targetObjectGTVelocity.twist.twist.linear.y*INTERNAL_SUB_STEP;
    }

    //////////////////////////////////////////////////////////////////////////////

    // filling the current state
    cur_state(0) = selfPose.pose.pose.position.x;
    cur_state(1) = 0; //********* Fill the right velocity fill the velocity later with another data type.. for now it is 0
    cur_state(2) = selfPose.pose.pose.position.y;
    cur_state(3) = 0; // fill the velocity later with another data type.. for now it is 0
    cur_state(4) = selfPose.pose.pose.position.z;
    cur_state(5) = 0; // fill the velocity later with another data type.. for now it is 0

      state_limits(0,0) = -copterPositionLimitX;        state_limits(0,1) = copterPositionLimitX;
      state_limits(1,0) = -copterVelocityLimitX;        state_limits(1,1) = copterVelocityLimitX;
      state_limits(2,0) = -copterPositionLimitY;        state_limits(2,1) = copterPositionLimitY;
      state_limits(3,0) = -copterVelocityLimitY;        state_limits(3,1) = copterVelocityLimitY;
      state_limits(4,0) = copterPositionLowerLimitZ;    state_limits(4,1) = copterPositionUpperLimitZ;
      state_limits(5,0) = -copterVelocityLimitZ;        state_limits(5,1) = copterVelocityLimitZ;

      input_limits(0,0) = -copterAccelarationLimitX;    input_limits(0,1) = copterAccelarationLimitX;
      input_limits(1,0) = -copterAccelarationLimitY;    input_limits(1,1) = copterAccelarationLimitY;
      input_limits(2,0) = -copterAccelarationLimitZ;    input_limits(2,1) = copterAccelarationLimitZ;

    theta = atan2(y1-y3,x1-x3);
    x4 = x3+ r*cos(theta);
    y4 = y3+ r*sin(theta);
    z4 = targetObjectGTPose.pose.pose.position.z+copterDesiredHeightinNED; // fixed heightin NWU
    vx4 = targetObjectGTVelocity.twist.twist.linear.x;
    vy4 = targetObjectGTVelocity.twist.twist.linear.y;


    // Terminal State to Compute Gradients
    term_state(0) = x4;
    term_state(1) = vx4; // want the robot to stop there at the destination
    term_state(2) = y4;
    term_state(3) = vy4;
    term_state(4) = z4;
    term_state(5) = 0;


    // //State Cost
    // costWeight(0) += targetMeanDiffSquared(0); //x
    // costWeight(1) += targetMeanDiffSquared(0); //vx
    // costWeight(2) += targetMeanDiffSquared(0); //y
    // costWeight(3) += targetMeanDiffSquared(0); //vy
    // costWeight(4) += targetMeanDiffSquared(0); //z
    // costWeight(5) += targetMeanDiffSquared(0); //vz


    avoidTeamMates_byComputingExtForce(); // also fills in selfPoseTraj message

    // StateInput = solveMPC.OCPsolDesigner(deltaT, obstacle_force, ExtForce, cur_state, term_state, costWeight, state_limits, input_limits, targetMeanDiffSquared, targetFusedState);
    StateInput = solveMPC.OCPsolDesigner(deltaT, obstacle_force, ExtForce, cur_state, term_state, costWeight, state_limits, input_limits);

    //  Publish most recent output of nmpc
    outPose.position.x =  StateInput(0,15);
    outPose.velocity.x =  StateInput(1,15);
    outPose.position.y =  StateInput(2,15);
    outPose.velocity.y =  StateInput(3,15);
    outPose.position.z =  StateInput(4,15);
    outPose.velocity.z =  StateInput(5,15);

    wayPoint.position.x = StateInput(0,15);
    wayPoint.position.y = StateInput(2,15);
    wayPoint.position.z = StateInput(4,15);

    if(useZeroAsFixedTarget)
    {
        outPose.POI.x = 0;
        outPose.POI.y = 0;
        outPose.POI.z = 0;
    }
    else
    {
        outPose.POI.x = targetObjectGTPose.pose.pose.position.x;
        outPose.POI.y = targetObjectGTPose.pose.pose.position.y;
        outPose.POI.z = targetObjectGTPose.pose.pose.position.z;
    }


    outPose.header= msg->header;
    selfPoseTraj.header = msg->header;

    // outPose.d2t = sqrt(pow(targetObjectGTPose.pose.pose.position.x - selfPose.pose.pose.position.x,2) +
    //                    pow(targetObjectGTPose.pose.pose.position.y - selfPose.pose.pose.position.y,2));

    pubOutPoseSelf_.publish(outPose);
    // pubMatlabPoseSelf.publish(wayPoint);
    pubSelfPoseTraj_.publish(selfPoseTraj);

    outPoseToRviz.header.stamp = msg->header.stamp;
    outPoseToRviz.header.frame_id = "world";

    outPoseToRviz.pose.position.x = selfPose.pose.pose.position.x;
    outPoseToRviz.pose.position.y = selfPose.pose.pose.position.y;
    outPoseToRviz.pose.position.z = selfPose.pose.pose.position.z;

    double yaw = atan2(outPose.position.y,outPose.position.x);
    double t0 = std::cos(yaw * 0.5);
    double t1 = std::sin(yaw * 0.5);
    double t2 = std::cos(0 * 0.5);
    double t3 = std::sin(0 * 0.5);
    double t4 = std::cos(0 * 0.5);
    double t5 = std::sin(0 * 0.5);

    outPoseToRviz.pose.orientation.w = t0 * t2 * t4 + t1 * t3 * t5;
    outPoseToRviz.pose.orientation.x = t0 * t3 * t4 - t1 * t2 * t5;
    outPoseToRviz.pose.orientation.y = t0 * t2 * t5 + t1 * t3 * t4;
    outPoseToRviz.pose.orientation.z = t1 * t2 * t4 - t0 * t3 * t5;

    // outPoseRviz_pub.publish(outPoseToRviz);
}

// void Planner::selfIMUCallback(const sensor_msgs::Imu::ConstPtr& msg)
// {
//   ///@TODO uncomment the lines below when necessary. For now it is all zero anyway.
//   selfIMUReading.header = msg->header;
//   selfIMUReading.orientation = msg->orientation;
//   selfIMUReading.angular_velocity = msg->angular_velocity;
//   //selfIMUReading.angular_velocity_covariance = msg->angular_velocity_covariance;
//   selfIMUReading.linear_acceleration = msg->linear_acceleration;
//   //selfIMUReading.header_covariance = msg->linear_acceleration_covariance;
// }


void Planner::reconf_callback(nmpc_planner::nmpcPlannerParamsConfig &config) //R:Dynamic Reconfigure?
{
  ROS_INFO("Reconfigure Request: neighborDistThreshold = %f  distanceThresholdToTarget = %f   copterDesiredHeightinNED = %f",config.neighborDistThreshold, config.distanceThresholdToTarget, config.copterDesiredHeightinNED);
  ROS_INFO("Reconfigure Request: approachAngleThreshold = %f ",config.approachAngleThreshold);

  ROS_INFO("Reconfigure Request: INTERNAL_SUB_STEP = %f deltaT = %f",config.INTERNAL_SUB_STEP, config.deltaT);
  ROS_INFO("Reconfigure Request: Velocity Horizontal = %f Accelaration Horizontal = %f",config.copterVelocityLimitHorizontal, config.copterAccelarationLimitHorizontal);
  ROS_INFO("Reconfigure Request: Velocity Vertical = %f Accelaration Vertical = %f",config.copterVelocityLimitVertical, config.copterAccelarationLimitVertical);
  ROS_INFO("Reconfigure Request: maxOffsetUncertaintyRadius = %f ",config.maxOffsetUncertaintyRadius);

  ROS_INFO("Reconfigure Request: targetGuaranteeThreshold = %f ",config.targetGuaranteeThreshold);
  ROS_INFO("Reconfigure Request: activeGuaranteeThreshold = %f ",config.activeGuaranteeThreshold);
  ROS_INFO("Reconfigure Request: obstacleGuaranteeThreshold = %f ",config.obstacleGuaranteeThreshold);
  ROS_INFO("Reconfigure Request: neighborGuaranteeThreshold = %f ",config.neighborGuaranteeThreshold);

  neighborDistThreshold=config.neighborDistThreshold;

  approachAngleThreshold = config.approachAngleThreshold;

  distanceThresholdToTarget=config.distanceThresholdToTarget;

  copterDesiredHeightinNED=config.copterDesiredHeightinNED;

  INTERNAL_SUB_STEP=config.INTERNAL_SUB_STEP;

  maxOffsetUncertaintyRadius=config.maxOffsetUncertaintyRadius;


  targetGuaranteeThreshold = config.targetGuaranteeThreshold;
  activeGuaranteeThreshold = config.activeGuaranteeThreshold;
  obstacleGuaranteeThreshold = config.obstacleGuaranteeThreshold;
  neighborGuaranteeThreshold = config.neighborGuaranteeThreshold;

  deltaT=config.deltaT;
  activeTrackingWeight=config.activeTrackingWeight;
  energyWeight=config.energyWeight;
  copterVelocityLimitX=config.copterVelocityLimitHorizontal;
  copterVelocityLimitY=config.copterVelocityLimitHorizontal;
  copterVelocityLimitZ=config.copterVelocityLimitVertical;
  copterAccelarationLimitX=config.copterAccelarationLimitHorizontal;
  copterAccelarationLimitY=config.copterAccelarationLimitHorizontal;
  copterAccelarationLimitZ=config.copterAccelarationLimitVertical;

}

int main(int argc, char* argv[])
{

  ros::init(argc, argv, "nmpc_planner_Diminishing");

  if (argc < 3)
    {
      ROS_WARN("WARNING: you should specify i) selfID and ii) the number of robots in the team including self\n");
      return 1;
    }
  else
  {
    ROS_INFO("nmpc_planner running for = %s using %s robots in the team including self",argv[1],argv[2]);
  }

  ros::NodeHandle nh("~");
  Planner node(&nh,atoi(argv[1]),atoi(argv[2]));
  spin();

  return 0;
}
