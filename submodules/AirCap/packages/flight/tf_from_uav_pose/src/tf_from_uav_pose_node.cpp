//
// tf_from_uav_poses_node.cpp
// ROS2 version - C++17 required
//

#include <tf_from_uav_pose/tf_from_uav_pose.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Transform.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

namespace tf_from_uav_pose {

tfFromUAVPose::tfFromUAVPose() : Node("tf_from_uav_pose") {

    std::string
            poseTopicName{"pose"},
            rawPoseTopicName{"pose/raw"},
            stdPoseTopicName{"pose/corr/std"},
            stdRawPoseTopicName{"pose/raww/std"},
            throttledPoseTopicName{"throttledPose"},
            machineFrameID{"machine_1_base_link"},
            worldFrameID{"world"},
            worldENUFrameID{"world_ENU"},
            worldNWUFrameID{"world_NWU"},
            cameraFrameID{"cameraFrameID"},
            cameraRGBOpticalFrameID{"cameraRGBOpticalFrameID"};

    // Declare and get parameters
    this->declare_parameter("poseTopicName", poseTopicName);
    this->declare_parameter("rawPoseTopicName", rawPoseTopicName);
    this->declare_parameter("stdPoseTopicName", stdPoseTopicName);
    this->declare_parameter("stdRawPoseTopicName", stdRawPoseTopicName);
    this->declare_parameter("throttledPoseTopicName", throttledPoseTopicName);
    this->declare_parameter("machineFrameID", machineFrameID);
    this->declare_parameter("worldFrameID", worldFrameID);
    this->declare_parameter("worldENUFrameID", worldENUFrameID);
    this->declare_parameter("worldNWUFrameID", worldNWUFrameID);
    this->declare_parameter("cameraFrameID", cameraFrameID);
    this->declare_parameter("cameraRGBOpticalFrameID", cameraRGBOpticalFrameID);
    this->declare_parameter("dontPublishTFs", false);
    this->declare_parameter("offsetX", 0.0);
    this->declare_parameter("offsetY", 0.0);
    this->declare_parameter("offsetZ", 0.0);
    this->declare_parameter("covarianceX", 0.0);
    this->declare_parameter("covarianceY", 0.0);
    this->declare_parameter("covarianceZ", 0.0);
    this->declare_parameter("throttleRate", 10.0);

    this->get_parameter("poseTopicName", poseTopicName);
    this->get_parameter("rawPoseTopicName", rawPoseTopicName);
    this->get_parameter("stdPoseTopicName", stdPoseTopicName);
    this->get_parameter("stdRawPoseTopicName", stdRawPoseTopicName);
    this->get_parameter("throttledPoseTopicName", throttledPoseTopicName);
    this->get_parameter("machineFrameID", machineFrameID);
    this->get_parameter("worldFrameID", worldFrameID);
    this->get_parameter("worldENUFrameID", worldENUFrameID);
    this->get_parameter("worldNWUFrameID", worldNWUFrameID);
    this->get_parameter("cameraFrameID", cameraFrameID);
    this->get_parameter("cameraRGBOpticalFrameID", cameraRGBOpticalFrameID);
    this->get_parameter("dontPublishTFs", dontPublishTFs_);
    this->get_parameter("offsetX", offset_[0]);
    this->get_parameter("offsetY", offset_[1]);
    this->get_parameter("offsetZ", offset_[2]);
    this->get_parameter("covarianceX", added_covariance_[0]);
    this->get_parameter("covarianceY", added_covariance_[1]);
    this->get_parameter("covarianceZ", added_covariance_[2]);
    this->get_parameter("throttleRate", throttleRate_);

    // In case it is requested to not publish TFs, the calculations will still happen but it won't be advertised/published
    if (!dontPublishTFs_) {
        RCLCPP_INFO(this->get_logger(), "Subscribing to '%s' and publishing tf with parent '%s' and child '%s'", 
                   poseTopicName.c_str(), worldFrameID.c_str(), machineFrameID.c_str());

        tfBroadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);
        statictfBroadcaster_ = std::make_unique<tf2_ros::StaticTransformBroadcaster>(*this);
    } else {
        RCLCPP_INFO(this->get_logger(), "Requested to not publish TFs - Publishing only poses!");
    }

    RCLCPP_INFO(this->get_logger(), "tf_from_uav_pose node initialized");

    // Prepare TF Messages
    // TF from world to machine
    tfPose_.header.frame_id = worldFrameID;
    tfPose_.child_frame_id = machineFrameID;

    // TF from world_ENU to world (world_ENU will be the root of the tree)
    tfWorldENU_.header.stamp = this->get_clock()->now();
    tfWorldENU_.header.frame_id = worldENUFrameID;
    tfWorldENU_.child_frame_id = worldFrameID;
    tf2::Quaternion qENU;
    qENU.setRPY(M_PI, 0, M_PI_2);
    qENU.normalize();
    tfWorldENU_.transform.rotation = tf2::toMsg(qENU);

    // TF from world to world_NWU
    tfWorldNWU_.header.stamp = tfWorldENU_.header.stamp;
    tfWorldNWU_.header.frame_id = worldFrameID;
    tfWorldNWU_.child_frame_id = worldNWUFrameID;
    tf2::Quaternion qNWU;
    qNWU.setRPY(0, M_PI, 0);
    tfWorldNWU_.transform.rotation = tf2::toMsg(qNWU);

    // TF from camera to rgb optical link
    tfCamRGB_.header.stamp = tfWorldENU_.header.stamp;
    tfCamRGB_.header.frame_id = cameraFrameID;
    tfCamRGB_.child_frame_id = cameraRGBOpticalFrameID;
    tf2::Quaternion qCR;
    qCR.setRPY(M_PI_2, 0, M_PI_2);
    tfCamRGB_.transform.rotation = tf2::toMsg(qCR);

    // Put all static TFs in vector
    std::vector<geometry_msgs::msg::TransformStamped> static_tfs{tfWorldNWU_, tfWorldENU_, tfCamRGB_};

    // Broadcast all static tfs
    if (!dontPublishTFs_)
        statictfBroadcaster_->sendTransform(static_tfs);

    // Advertise std poses
    stdPose_.header.frame_id = worldFrameID;
    stdPosePub_ = this->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>(stdPoseTopicName, 10);

    // Advertise std raw poses
    stdRawPose_.header.frame_id = worldFrameID;
    stdRawPosePub_ = this->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>(stdRawPoseTopicName, 10);

    // Advertise throttled poses
    throttledPose_.header.frame_id = worldFrameID;
    throttledPose_.header.stamp = this->get_clock()->now();
    throttledPosePub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>(throttledPoseTopicName, 10);

    // Subscribe to poses
    poseSub_ = this->create_subscription<uav_msgs::msg::UavPose>(
        poseTopicName, 10, std::bind(&tfFromUAVPose::poseCallback, this, std::placeholders::_1));
    rawPoseSub_ = this->create_subscription<uav_msgs::msg::UavPose>(
        rawPoseTopicName, 10, std::bind(&tfFromUAVPose::rawPoseCallback, this, std::placeholders::_1));
}

void tfFromUAVPose::poseCallback(const uav_msgs::msg::UavPose::SharedPtr msg) {

    // Copy contents to std pose msg
    stdPose_.header.stamp = msg->header.stamp;
    stdPose_.pose.pose.position = msg->position;
    stdPose_.pose.pose.orientation = msg->orientation;

    // Convert covariance types (simplified without MRPT)
    uavCovariance_to_rosCovariance(msg, stdPose_.pose);

    // Add offset
    try {
        stdPose_.pose.pose.position.x += offset_.at(0);
        stdPose_.pose.pose.position.y += offset_.at(1);
        stdPose_.pose.pose.position.z += offset_.at(2);

        stdPose_.pose.covariance[0] += added_covariance_.at(0);
        stdPose_.pose.covariance[7] += added_covariance_.at(1);
        stdPose_.pose.covariance[14] += added_covariance_.at(2);
    }
    catch (std::out_of_range &oor) {
        RCLCPP_ERROR(this->get_logger(), "Couldn't add offset: %s", oor.what());
        return;
    }

    // Publish std pose msg
    stdPosePub_->publish(stdPose_);

    rclcpp::Duration timediff(msg->header.stamp.sec - throttledPose_.header.stamp.sec, 
                             msg->header.stamp.nanosec - throttledPose_.header.stamp.nanosec);
    if ((1.0/timediff.seconds()) <= throttleRate_) {
        // Copy contents to throttle pose msg
        throttledPose_.header.stamp = msg->header.stamp;
        throttledPose_.pose.position = msg->position;
        throttledPose_.pose.orientation = msg->orientation;

        // Publish throttle pose msg
        throttledPosePub_->publish(throttledPose_);
    }

    // Copy contents to tf msgs
    tfPose_.header.stamp = msg->header.stamp;

    tfPose_.transform.translation.x = stdPose_.pose.pose.position.x;
    tfPose_.transform.translation.y = stdPose_.pose.pose.position.y;
    tfPose_.transform.translation.z = stdPose_.pose.pose.position.z;

    tfPose_.transform.rotation.w = stdPose_.pose.pose.orientation.w;
    tfPose_.transform.rotation.x = stdPose_.pose.pose.orientation.x;
    tfPose_.transform.rotation.y = stdPose_.pose.pose.orientation.y;
    tfPose_.transform.rotation.z = stdPose_.pose.pose.orientation.z;

    // Broadcast tf
    if (!dontPublishTFs_)
        tfBroadcaster_->sendTransform(tfPose_);
}

void tfFromUAVPose::rawPoseCallback(const uav_msgs::msg::UavPose::SharedPtr msg) {

    // Copy contents to std pose msg
    stdRawPose_.header.stamp = msg->header.stamp;
    stdRawPose_.pose.pose.position = msg->position;
    stdRawPose_.pose.pose.orientation = msg->orientation;

    // Convert covariance types (simplified without MRPT)
    uavCovariance_to_rosCovariance(msg, stdRawPose_.pose);

    // Publish std pose msg
    stdRawPosePub_->publish(stdRawPose_);
}

void uavCovariance_to_rosCovariance(const uav_msgs::msg::UavPose::SharedPtr uav_msg,
                                    geometry_msgs::msg::PoseWithCovariance &std_pose_cov) {
    // Simplified covariance conversion without MRPT
    // This is a basic implementation that copies position covariances directly
    // and sets orientation covariances to reasonable defaults
    
    // Initialize covariance matrix to zeros
    std::fill(std_pose_cov.covariance.begin(), std_pose_cov.covariance.end(), 0.0);
    
    // Copy position covariances (first 3x3 block)
    // UAV covariance format: pos_north, pos_east, pos_down at indices 0, 1, 2
    std_pose_cov.covariance[0] = uav_msg->covariance[0];   // pos_x variance
    std_pose_cov.covariance[7] = uav_msg->covariance[11];  // pos_y variance  
    std_pose_cov.covariance[14] = uav_msg->covariance[22]; // pos_z variance
    
    // Set reasonable orientation covariances (last 3x3 block)
    // Since we can't do proper quaternion to Euler conversion without MRPT,
    // we'll use simplified estimates based on quaternion covariances
    double quat_var_sum = uav_msg->covariance[66] + uav_msg->covariance[77] + 
                         uav_msg->covariance[88] + uav_msg->covariance[99]; // q_w, q_x, q_y, q_z variances
    
    std_pose_cov.covariance[21] = quat_var_sum * 0.25; // roll variance estimate
    std_pose_cov.covariance[28] = quat_var_sum * 0.25; // pitch variance estimate
    std_pose_cov.covariance[35] = quat_var_sum * 0.25; // yaw variance estimate
}

}

int main(int argc, char **argv) {

    // Init ROS2 node
    rclcpp::init(argc, argv);

    // Create and spin node
    auto node = std::make_shared<tf_from_uav_pose::tfFromUAVPose>();
    rclcpp::spin(node);
    
    rclcpp::shutdown();
    return 0;
}

