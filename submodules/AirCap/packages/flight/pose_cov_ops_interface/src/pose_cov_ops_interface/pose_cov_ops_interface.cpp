//
// Created by glawless on 11.05.17.
// Simplified ROS2 version
//

#include <pose_cov_ops_interface/pose_cov_ops_interface.h>

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
        if constexpr (std::is_same_v<K, std::string>) {
          RCLCPP_ERROR(node_->get_logger(), "Out of Range error for key: %s", key.c_str());
        } else {
          RCLCPP_ERROR(node_->get_logger(), "Out of Range error for key: %d", static_cast<int>(key));
        }
        RCLCPP_ERROR(node_->get_logger(), "Are you sure it exists? Printing interface contents...");
        throw oor;
      }
    }

    template<typename K>
    void Interface<K>::print(std::ostream &stream) const {
      stream << "Interface at time " << node_->get_clock()->now().seconds() << std::endl;
      if (pose_cache_.empty())
        stream << "Empty" << std::endl;

      for (auto it = pose_cache_.begin(); it != pose_cache_.end(); ++it) {
        const auto& cache = it->second;
        stream << "\tcache:\n\t\tkey:\t";
        if constexpr (std::is_same_v<K, std::string>) {
          stream << it->first;
        } else {
          stream << static_cast<int>(it->first);
        }
        stream << "\n\t\tsize:\t" << cache.size();
        if (!cache.empty()) {
          stream << "\n\t\toldest:\t" << cache.front().header.stamp.sec << "." << cache.front().header.stamp.nanosec;
        }
        stream << std::endl;
      }
    }

    // Explicitly instantiate the class for int and string keys
    template class Interface<std::string>;
    template class Interface<int>;

  }
}

