#pragma once
#include <ros/ros.h>
#include <string>
#include "robotinfo_msgs/RobotInfo10Fields.h"

class RobotInfo {
private:
    std::string robot_description;
    std::string serial_number;
    std::string ip_address;
    std::string firmware_version;
    std::string robot_info_topic;  
protected:
    ros::NodeHandle* nh; 
    ros::Publisher robot_info_publisher;

    void InfoPublisher();

    void RobotMessage(robotinfo_msgs::RobotInfo10Fields& msg) const;

public:
    RobotInfo(ros::NodeHandle* nh);

    RobotInfo(ros::NodeHandle* nh,
              const std::string& robot_description,
              const std::string& serial_number,
              const std::string& ip_address,
              const std::string& firmware_version);

    virtual void publish_data();
};