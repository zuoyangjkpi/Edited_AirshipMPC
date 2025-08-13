//
// Created by glawless on 11.05.17.
//

#ifndef POSE_COV_OPS_INTERFACE_POSECOVOPSINTERFACE_H
#define POSE_COV_OPS_INTERFACE_POSECOVOPSINTERFACE_H

#include <rclcpp/rclcpp.hpp>
#include <unordered_map>
#include <vector>
#include <geometry_msgs/msg/pose_with_covariance.hpp>
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <geometry_msgs/msg/pose.hpp>
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

      ///@brief Returns the oldest pose time available in the cache for a given pose key
      ///@param [in] key pose key
      ///@return rclcpp::Time object
      ///@throw std::out_of_range if a key does not exist in the cache map
      rclcpp::Time oldestTimeInCache(K key) const;

      ///@brief Outputs p1(+)p2, a new pose "as if" p1 was the origin for p2
      ///@param [in] in_pose the pose to be transformed, in the frame corresponding to transformation_key pose
      ///@param [in] transformation_key the key corresponding to the transforming (connecting) pose
      ///@param [in] t the time to use when searching for the poses in the cache
      ///@param [out] out_pose transformed pose in the parent frame
      ///@return true if all poses were found for time t, false otherwise
      ///@throw std::out_of_range if a key does not exist in the cache map
      template<typename P>
      bool compose_up(const P& in_pose, const K &transformation_key, const rclcpp::Time &t, PoseWithCovariance &out_pose);

      ///@brief Overload of compose_up for a geometry_msgs::Point
      bool compose_up(const Point& in_pose, const K &transformation_key, const rclcpp::Time &t, PoseWithCovariance &out_pose);

      ///@brief Outputs (((p1+p2)+p3)+...+plast)
      template<typename P>
      bool compose_up(const P& in_pose, const std::vector<K> &transformation_keys_ordered, const rclcpp::Time &t, PoseWithCovariance &out_pose);

      ///@brief Overload of compose_up for a geometry_msgs::Point
      bool compose_up(const Point& in_pose, const std::vector<K> &transformation_keys_ordered, const rclcpp::Time &t, PoseWithCovariance &out_pose);

      ///@brief Outputs p2(-)p1, a new pose that is p2 "seen from" p1
      template<typename P>
      bool compose_down(const P& in_pose, const K &transformation_key, const rclcpp::Time &t, PoseWithCovariance &out_pose);

      ///@brief Overload of compose_down for a geometry_msgs::Point
      bool compose_down(const Point& in_point, const K &transformation_key, const rclcpp::Time &t, PoseWithCovariance &out_pose);

      ///@brief Outputs plast-(((p1+p2)+p3)+...))
      template<typename P>
      bool compose_down(const P& in_pose, const std::vector<K> &transformation_keys_ordered, const rclcpp::Time &t, PoseWithCovariance &out_pose);

      ///@brief Overload of compose_down for a geometry_msgs::Point
      bool compose_down(const Point& in_point, const std::vector<K> &transformation_keys_ordered, const rclcpp::Time &t, PoseWithCovariance &out_pose);

      ///@brief prints to stream debugging information on the interface
      void print(std::ostream&) const;

    private:
      ///@brief Simple pose composition (simplified version without full covariance handling)
      void simple_compose(const PoseWithCovariance& p1, const Pose& p2, PoseWithCovariance& result);
      
      ///@brief Simple inverse pose composition (simplified version)
      void simple_inverse_compose(const Pose& p1, const PoseWithCovariance& p2, PoseWithCovariance& result);
    };

    template<typename K>
    inline std::ostream& operator<< (std::ostream& stream, const Interface<K>& interface) {
      interface.print(stream);
      return stream;
    }
  }
}

#endif //POSE_COV_OPS_INTERFACE_POSECOVOPSINTERFACE_H

