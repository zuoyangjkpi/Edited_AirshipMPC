//
// Provides a sensor_msgs/CameraInfo message in a latched topic
// Info is read from URL using the camera_info_manager interface
//

#include <rclcpp/rclcpp.hpp>
#include <camera_info_manager/camera_info_manager.hpp>
#include <sensor_msgs/msg/camera_info.hpp>

class CameraInfoPublisher : public rclcpp::Node
{
public:
  CameraInfoPublisher() : Node("camera_info_publisher")
  {
    // Parameters
    this->declare_parameter<std::string>("camera_info_url", "");
    this->declare_parameter<std::string>("camera_info_topic", "camera_info");
    
    std::string url;
    if (!this->get_parameter("camera_info_url", url) || url.empty()) {
      RCLCPP_ERROR(this->get_logger(), "Must provide camera_info_url parameter");
      rclcpp::shutdown();
      return;
    }
    
    std::string topic;
    this->get_parameter("camera_info_topic", topic);
    
    // Create camera info manager
    manager_ = std::make_shared<camera_info_manager::CameraInfoManager>(this, "video", url);
    
    // Create publisher with latched QoS
    rclcpp::QoS qos(1);
    qos.transient_local();  // This is the ROS2 equivalent of latched
    pub_ = this->create_publisher<sensor_msgs::msg::CameraInfo>(topic, qos);
    
    RCLCPP_INFO(this->get_logger(), "Publishing camera_info to topic %s", topic.c_str());
    
    // Publish once
    pub_->publish(manager_->getCameraInfo());
  }

private:
  rclcpp::Publisher<sensor_msgs::msg::CameraInfo>::SharedPtr pub_;
  std::shared_ptr<camera_info_manager::CameraInfoManager> manager_;
};

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  
  auto node = std::make_shared<CameraInfoPublisher>();
  
  rclcpp::spin(node);
  
  rclcpp::shutdown();
  return 0;
}

