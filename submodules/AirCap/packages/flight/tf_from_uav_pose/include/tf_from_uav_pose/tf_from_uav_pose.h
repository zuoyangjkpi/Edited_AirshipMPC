//
// tf_from_uav_poses_node.h
// ROS2 version - C++17 required
//

#ifndef TF_FROM_UAV_POSE_H
#define TF_FROM_UAV_POSE_H

#include <rclcpp/rclcpp.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <uav_msgs/msg/uav_pose.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Transform.h>

namespace tf_from_uav_pose {

    void uavCovariance_to_rosCovariance(const uav_msgs::msg::UavPose::SharedPtr uav_msg,
                                        geometry_msgs::msg::PoseWithCovariance &std_pose_cov);

    class tfFromUAVPose : public rclcpp::Node {

    private:
        rclcpp::Subscription<uav_msgs::msg::UavPose>::SharedPtr poseSub_;
        rclcpp::Subscription<uav_msgs::msg::UavPose>::SharedPtr rawPoseSub_;
        rclcpp::Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr stdPosePub_;
        rclcpp::Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr stdRawPosePub_;
        rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr throttledPosePub_;
        rclcpp::Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr cameraPosePub_, camRGBPosePub_;
        
        std::unique_ptr<tf2_ros::TransformBroadcaster> tfBroadcaster_;
        std::unique_ptr<tf2_ros::StaticTransformBroadcaster> statictfBroadcaster_;

        geometry_msgs::msg::PoseWithCovarianceStamped stdPose_, stdRawPose_, camRobPose_, rgbCamPose_;
        geometry_msgs::msg::PoseStamped throttledPose_;
        geometry_msgs::msg::TransformStamped tfPose_;
        geometry_msgs::msg::TransformStamped tfWorldENU_;
        geometry_msgs::msg::TransformStamped tfWorldNWU_;
        geometry_msgs::msg::TransformStamped tfCamRGB_;

        ///@TODO remove this hacked offset, do it better
        std::vector<double> offset_{0, 0, 0};
        std::vector<double> added_covariance_{0, 0, 0};
        double throttleRate_{10.0};

        bool dontPublishTFs_{false};

    public:
        tfFromUAVPose();

        void poseCallback(const uav_msgs::msg::UavPose::SharedPtr msg);
        void rawPoseCallback(const uav_msgs::msg::UavPose::SharedPtr msg);
    };
}

#endif //TF_FROM_UAV_POSE_H

