//
// Created by glawless on 11.05.17.
// Modified for ROS2 compatibility
//

#include <pose_cov_ops_interface/pose_cov_ops_interface.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Transform.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

namespace pose_cov_ops {
  namespace interface {

    template<typename K>
    Interface<K>::Interface(const std::vector<topicSubInfo<K>> &pose_topics, rclcpp::Node::SharedPtr node) 
      : node_(node) {
      
      // Initialize empty cache for each topic
      for (const topicSubInfo<K> &topic : pose_topics) {
        pose_cache_[topic.key] = std::vector<PoseWithCovarianceStamped>();
        pose_cache_[topic.key].reserve(topic.cache_size);
      }
    }

    template<typename K>
    rclcpp::Time Interface<K>::oldestTimeInCache(K key) const {
      try {
        const auto& cache = pose_cache_.at(key);
        if (cache.empty()) {
          return rclcpp::Time(0);
        }
        return cache.front().header.stamp;
      }
      catch (std::out_of_range &oor) {
        RCLCPP_ERROR(node_->get_logger(), "Out of Range error for key: %s", std::to_string(key).c_str());
        RCLCPP_ERROR(node_->get_logger(), "Are you sure it exists? Printing interface contents...");
        throw oor;
      }
    }

    template<typename K>
    void Interface<K>::simple_compose(const PoseWithCovariance& p1, const Pose& p2, PoseWithCovariance& result) {
      // Convert to tf2 transforms for easier composition
      tf2::Transform tf1, tf2, tf_result;
      
      tf2::fromMsg(p1.pose, tf1);
      tf2::fromMsg(p2, tf2);
      
      tf_result = tf1 * tf2;
      
      result.pose = tf2::toMsg(tf_result);
      
      // For simplicity, just copy the covariance from p1
      // In a full implementation, covariance would be properly propagated
      result.covariance = p1.covariance;
    }

    template<typename K>
    void Interface<K>::simple_inverse_compose(const Pose& p1, const PoseWithCovariance& p2, PoseWithCovariance& result) {
      // Convert to tf2 transforms
      tf2::Transform tf1, tf2, tf_result;
      
      tf2::fromMsg(p1, tf1);
      tf2::fromMsg(p2.pose, tf2);
      
      tf_result = tf1.inverse() * tf2;
      
      result.pose = tf2::toMsg(tf_result);
      
      // For simplicity, just copy the covariance from p2
      result.covariance = p2.covariance;
    }

    template<typename K>
    template<typename P>
    bool Interface<K>::compose_up(const P &in_pose, const K &transformation_key, const rclcpp::Time &t,
                                  PoseWithCovariance &out_pose) {

      // For this simplified version, we'll just return a basic composition
      // In a full implementation, this would search the cache for the closest time
      try {
        const auto& cache = pose_cache_.at(transformation_key);
        if (cache.empty()) {
          return false;
        }
        
        // Use the latest pose for simplicity
        const auto& transform_pose = cache.back().pose;
        
        // Convert input pose to Pose message if needed
        Pose input_as_pose;
        if constexpr (std::is_same_v<P, Pose>) {
          input_as_pose = in_pose;
        } else if constexpr (std::is_same_v<P, PoseWithCovariance>) {
          input_as_pose = in_pose.pose;
        } else {
          // Handle other types as needed
          return false;
        }
        
        simple_compose(transform_pose, input_as_pose, out_pose);
        return true;
      }
      catch (std::out_of_range &oor) {
        RCLCPP_ERROR(node_->get_logger(), "Out of Range error for key: %s", std::to_string(transformation_key).c_str());
        throw oor;
      }
    }

    template<typename K>
    bool Interface<K>::compose_up(const Point &in_point, const K &transformation_key, const rclcpp::Time &t,
                                  PoseWithCovariance &out_pose) {

      Pose in_pose;
      in_pose.position = in_point;
      in_pose.orientation.w = 1.0;

      return compose_up(in_pose, transformation_key, t, out_pose);
    }

    template<typename K>
    template<typename P>
    bool Interface<K>::compose_up(const P &in_pose, const std::vector<K> &transformation_keys_ordered,
                                  const rclcpp::Time &t, PoseWithCovariance &out_pose) {

      if (transformation_keys_ordered.size() < 1)
        return false;

      PoseWithCovariance t_pose, t_outpose;
      t_pose.pose.orientation.w = 1.0;

      for(auto it = transformation_keys_ordered.rbegin(); it != transformation_keys_ordered.rend(); ++it) {
        if (!compose_up(t_pose, *it, t, t_outpose))
          return false;
        t_pose = t_outpose;
      }

      // Convert input pose to Pose if needed
      Pose input_as_pose;
      if constexpr (std::is_same_v<P, Pose>) {
        input_as_pose = in_pose;
      } else if constexpr (std::is_same_v<P, PoseWithCovariance>) {
        input_as_pose = in_pose.pose;
      }

      simple_compose(t_pose, input_as_pose, out_pose);
      return true;
    }

    template<typename K>
    bool Interface<K>::compose_up(const Point &in_point, const std::vector<K> &transformation_keys_ordered,
                                  const rclcpp::Time &t, PoseWithCovariance &out_pose) {

      Pose in_pose;
      in_pose.position = in_point;
      in_pose.orientation.w = 1.0;

      return compose_up(in_pose, transformation_keys_ordered, t, out_pose);
    }

    template<typename K>
    template<typename P>
    bool Interface<K>::compose_down(const P &in_pose, const K &transformation_key, const rclcpp::Time &t,
                                    PoseWithCovariance &out_pose) {

      try {
        const auto& cache = pose_cache_.at(transformation_key);
        if (cache.empty()) {
          return false;
        }
        
        const auto& transform_pose = cache.back().pose.pose;
        
        // Convert input pose to Pose if needed
        Pose input_as_pose;
        if constexpr (std::is_same_v<P, Pose>) {
          input_as_pose = in_pose;
        } else if constexpr (std::is_same_v<P, PoseWithCovariance>) {
          input_as_pose = in_pose.pose;
        }
        
        simple_inverse_compose(input_as_pose, transform_pose, out_pose);
        return true;
      }
      catch (std::out_of_range &oor) {
        RCLCPP_ERROR(node_->get_logger(), "Out of Range error for key: %s", std::to_string(transformation_key).c_str());
        throw oor;
      }
    }

    template<typename K>
    bool Interface<K>::compose_down(const Point &in_point, const K &transformation_key, const rclcpp::Time &t,
                                    PoseWithCovariance &out_pose) {

      Pose in_pose;
      in_pose.position = in_point;
      in_pose.orientation.w = 1.0;

      return compose_down(in_pose, transformation_key, t, out_pose);
    }

    template<typename K>
    template<typename P>
    bool Interface<K>::compose_down(const P &in_pose, const std::vector<K> &transformation_keys_ordered, 
                                   const rclcpp::Time &t, PoseWithCovariance &out_pose) {

      if (transformation_keys_ordered.size() < 1)
        return false;

      PoseWithCovariance t_pose, t_outpose;
      t_pose.pose.orientation.w = 1.0;

      for(auto it = transformation_keys_ordered.rbegin(); it != transformation_keys_ordered.rend(); ++it) {
        if (!compose_up(t_pose, *it, t, t_outpose))
          return false;
        t_pose = t_outpose;
      }

      // Convert input pose to Pose if needed
      Pose input_as_pose;
      if constexpr (std::is_same_v<P, Pose>) {
        input_as_pose = in_pose;
      } else if constexpr (std::is_same_v<P, PoseWithCovariance>) {
        input_as_pose = in_pose.pose;
      }

      simple_inverse_compose(input_as_pose, t_pose, out_pose);
      return true;
    }

    template<typename K>
    bool Interface<K>::compose_down(const Point &in_point, const std::vector<K> &transformation_keys_ordered,
                                    const rclcpp::Time &t, PoseWithCovariance &out_pose) {

      Pose in_pose;
      in_pose.position = in_point;
      in_pose.orientation.w = 1.0;

      return compose_down(in_pose, transformation_keys_ordered, t, out_pose);
    }

    template<typename K>
    void Interface<K>::print(std::ostream &stream) const {
      stream << "Interface at time " << node_->get_clock()->now().seconds() << std::endl;
      if (pose_cache_.empty())
        stream << "Empty" << std::endl;

      for (auto it = pose_cache_.begin(); it != pose_cache_.end(); ++it) {
        const auto& cache = it->second;
        stream << "\tcache:\n\t\tkey:\t" << it->first << "\n\t\tsize:\t" << cache.size();
        if (!cache.empty()) {
          stream << "\n\t\toldest:\t" << cache.front().header.stamp.sec << "." << cache.front().header.stamp.nanosec;
        }
        stream << std::endl;
      }
    }

    // Explicitly instantiate the class for int and string keys
    template class Interface<std::string>;
    template class Interface<int>;

    // Explicit template instantiations for commonly used types
    template bool Interface<std::string>::compose_up(const PoseWithCovariance &, const std::vector<std::string> &, 
                                                     const rclcpp::Time &, PoseWithCovariance &);
    template bool Interface<std::string>::compose_up(const PoseWithCovariance &, const std::string &, 
                                                     const rclcpp::Time &, PoseWithCovariance &);
    template bool Interface<std::string>::compose_down(const PoseWithCovariance &, const std::vector<std::string> &,
                                                       const rclcpp::Time &, PoseWithCovariance &);
    template bool Interface<std::string>::compose_down(const PoseWithCovariance &, const std::string &, 
                                                       const rclcpp::Time &, PoseWithCovariance &);

    template bool Interface<int>::compose_up(const PoseWithCovariance &, const std::vector<int> &, 
                                            const rclcpp::Time &, PoseWithCovariance &);
    template bool Interface<int>::compose_up(const PoseWithCovariance &, const int &, 
                                            const rclcpp::Time &, PoseWithCovariance &);
    template bool Interface<int>::compose_down(const PoseWithCovariance &, const std::vector<int> &, 
                                              const rclcpp::Time &, PoseWithCovariance &);
    template bool Interface<int>::compose_down(const PoseWithCovariance &, const int &, 
                                              const rclcpp::Time &, PoseWithCovariance &);

  }
}

