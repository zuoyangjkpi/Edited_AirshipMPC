// based on the example https://github.com/garyservin/serial-example/blob/master/src/serial_example_node.cpp
// Converted to ROS2

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/empty.hpp>
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>

// extracting double value from a string
void extract_value(std::string& sdata, double& value)
{
    std::string::size_type sz;
    value = std::stod (sdata,&sz);
    sdata = sdata.substr(sz);

    return;
}

// transforming received deviation values to the appropriate values in covariance matrix
void transform_sdvalue(double& val)
{
    if (val<0)
        val = -1.0*(val*val);
    else
        val = val*val;
}

// parser for GPS data, ENU format expected
// format of the serial input described on the page 102 of
// http://www.rtklib.com/prog/manual_2.4.2.pdf
void parse_GPS(std::string& gps, std::string& t_stamp,double& east, double& north,
                           double& up, double covariance[36])
{
    // extracting time_stamp
    t_stamp = gps.substr(0,23);
    gps = gps.substr(24,gps.length()-24);

    // extracting values for the covariance matrix diagonal
    extract_value(gps,east);
    extract_value(gps,north);
    extract_value(gps,up);
    // variable for skipping unused values from serial input
    // namely number of satelites(ns), and quality(Q)
    double temp = 0;
    extract_value(gps,temp);
    extract_value(gps,temp);
    // values received for position errors represent sqrt(abs(member of covariance matrix))
    // they need to be transformed
    // covarinace array indices should be change according to msg format used (float64[36])
    // sdn
    extract_value(gps,covariance[0]);
    transform_sdvalue(covariance[0]);
    // sde
    extract_value(gps,covariance[7]);
    transform_sdvalue(covariance[7]);
    // sdu
    extract_value(gps,covariance[14]);
    transform_sdvalue(covariance[14]);
    // sdne
    extract_value(gps,covariance[6]);
    transform_sdvalue(covariance[6]);
    covariance[1] = covariance[6];
    // sdeu
    extract_value(gps,covariance[8]);
    transform_sdvalue(covariance[8]);
    // changing sign because the actual coordinate is up
    covariance[8] = - covariance[8];
    covariance[13] = covariance[8];
    // sdun
    extract_value(gps,covariance[2]);
    transform_sdvalue(covariance[2]);
    // changing sign because the actual coordinate is up
    covariance[2] = - covariance[2];
    covariance[12] = covariance[2];
    return;
}

int main (int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("gps_serial");
    
    std::string device_name{"/dev/stdin"};
    std::string gps_topic{"gpspose"};
    
    // Declare and get parameters
    node->declare_parameter("device_name", device_name);
    node->declare_parameter("gps_topic", gps_topic);
    node->get_parameter("device_name", device_name);
    node->get_parameter("gps_topic", gps_topic);
    
    auto pose_pub = node->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>(gps_topic, 5);
    
    double east,north,up;
    double covariance[36];
    // initializing covariance matrix with zeros
    for (int k=0;k<36;k++)
        covariance[k] = 0;
    
    // setting loop rate to 5 Hz
    rclcpp::Rate rate(5);
    std::ifstream myfile (device_name);

    while(rclcpp::ok())
    {
        rclcpp::spin_some(node);
        
        if (myfile.is_open())
        {
            std_msgs::msg::String gps;
            geometry_msgs::msg::PoseWithCovarianceStamped msg;
            std::string t_stamp;
            
            // reading from file/device
            if (!std::getline(myfile,gps.data)) {
                myfile.close();
                RCLCPP_ERROR(node->get_logger(), "end of file");
                rclcpp::shutdown();
                return -1;
            }
            
            msg.header.stamp = node->get_clock()->now();
            
            // parsing GPS information
            if (gps.data.substr(0,1)!="%" && gps.data.size()>140)
            {
                //RCLCPP_INFO(node->get_logger(), "%s", gps.data.c_str());
                parse_GPS(gps.data,t_stamp,east,north,up,covariance);
                
                // forming a ros message with parsed GPS data in ENU format, converted up to down
                // Note: ROS2 doesn't have header.seq, it's automatically handled
                msg.header.frame_id = "world";
                
                // adding position, converting to actual north east down coordinates
                msg.pose.pose.position.x = north;
                msg.pose.pose.position.y = east;
                msg.pose.pose.position.z = -up;
                
                // adding orientation
                msg.pose.pose.orientation.x = 0;
                msg.pose.pose.orientation.y = 0;
                msg.pose.pose.orientation.z = 0;
                msg.pose.pose.orientation.w = 1;
                
                // filling the covariance matrix
                for (int k=0;k<36;k++)
                    msg.pose.covariance[k]=covariance[k];
                
                // publishing the message
                pose_pub->publish(msg);
            } else {
                RCLCPP_INFO(node->get_logger(), "ignoring data line");
            }
        }
        else {
            RCLCPP_ERROR(node->get_logger(), "unable to open file");
            rclcpp::shutdown();
            return -1;
        }
        
        rate.sleep();
    }
    
    rclcpp::shutdown();
    return 0;
}

