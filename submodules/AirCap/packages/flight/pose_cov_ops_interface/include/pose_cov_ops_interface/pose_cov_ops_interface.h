//
// Created by glawless on 11.05.17.
// Simplified ROS2 version
//

#ifndef POSE_COV_OPS_INTERFACE_POSECOVOPSINTERFACE_H
#define POSE_COV_OPS_INTERFACE_POSECOVOPSINTERFACE_H

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_with_covariance.hpp>
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

namespace pose_cov_ops {
  namespace interface {

    using geometry_msgs::msg::PoseWithCovariance;
    using geometry_msgs::msg::PoseWithCovarianceStamped;
    using geometry_msgs::msg::Point;
    using geometry_msgs::msg::Pose;

    template<typename K>
    struct topicSubInfo {
      std::string name;
      K key;
      unsigned int cache_size;
      uint32_t queue_size;

      topicSubInfo(std::string _name, K _key, unsigned int _cache_size, uint32_t _queue_size) 
        : name(_name), key(_key), cache_size(_cache_size), queue_size(_queue_size) {};
    };

    template<typename K>
    class Interface {
    private:
      rclcpp::Node::SharedPtr node_;
      std::unordered_map<K, std::vector<PoseWithCovarianceStamped>> pose_cache_;

    public:
      Interface(const std::vector<topicSubInfo<K>> &pose_topics, rclcpp::Node::SharedPtr node);

      // Basic functionality for compilation
      rclcpp::Time oldestTimeInCache(K key) const;
      void print(std::ostream& stream) const;

      // Simplified compose functions that just return false for now
      template<typename P>
      bool compose_up(const P& in_pose, const K &transformation_key, const rclcpp::Time &t, PoseWithCovariance &out_pose) {
        (void)in_pose; (void)transformation_key; (void)t; (void)out_pose; // Suppress unused parameter warnings
        return false; // Simplified implementation
      }

      bool compose_up(const Point& in_pose, const K &transformation_key, const rclcpp::Time &t, PoseWithCovariance &out_pose) {
        (void)in_pose; (void)transformation_key; (void)t; (void)out_pose;
        return false;
      }

      template<typename P>
      bool compose_up(const P& in_pose, const std::vector<K> &transformation_keys_ordered, const rclcpp::Time &t, PoseWithCovariance &out_pose) {
        (void)in_pose; (void)transformation_keys_ordered; (void)t; (void)out_pose;
        return false;
      }

      bool compose_up(const Point& in_pose, const std::vector<K> &transformation_keys_ordered, const rclcpp::Time &t, PoseWithCovariance &out_pose) {
        (void)in_pose; (void)transformation_keys_ordered; (void)t; (void)out_pose;
        return false;
      }

      template<typename P>
      bool compose_down(const P& in_pose, const K &transformation_key, const rclcpp::Time &t, PoseWithCovariance &out_pose) {
        (void)in_pose; (void)transformation_key; (void)t; (void)out_pose;
        return false;
      }

      bool compose_down(const Point& in_point, const K &transformation_key, const rclcpp::Time &t, PoseWithCovariance &out_pose) {
        (void)in_point; (void)transformation_key; (void)t; (void)out_pose;
        return false;
      }

      template<typename P>
      bool compose_down(const P& in_pose, const std::vector<K> &transformation_keys_ordered, const rclcpp::Time &t, PoseWithCovariance &out_pose) {
        (void)in_pose; (void)transformation_keys_ordered; (void)t; (void)out_pose;
        return false;
      }

      bool compose_down(const Point& in_point, const std::vector<K> &transformation_keys_ordered, const rclcpp::Time &t, PoseWithCovariance &out_pose) {
        (void)in_point; (void)transformation_keys_ordered; (void)t; (void)out_pose;
        return false;
      }
    };

    template<typename K>
    inline std::ostream& operator<< (std::ostream& stream, const Interface<K>& interface) {
      interface.print(stream);
      return stream;
    }
  }
}

#endif //POSE_COV_OPS_INTERFACE_POSECOVOPSINTERFACE_H

