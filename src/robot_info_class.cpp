#include "robot_info/robot_info_class.h"

RobotInfo::RobotInfo(ros::NodeHandle *nh) {
  this->nh = nh;
  this->robot_info_topic = "robot_info";

  this->robot_description = "robot_description: Mir100";
  this->serial_number = "serial_number: 567A359";
  this->ip_address = "ip_address: 169.254.5.180";
  this->firmware_version = "firmware_version: 3.5.8";

  InfoPublisher();
}
RobotInfo::RobotInfo(ros::NodeHandle *nh, const std::string &robot_description,
                     const std::string &serial_number,
                     const std::string &ip_address,
                     const std::string &firmware_version)
    : RobotInfo::RobotInfo(
          nh) {
  this->robot_description = robot_description;
  this->serial_number = serial_number;
  this->ip_address = ip_address;
  this->firmware_version = firmware_version;

}
void RobotInfo::RobotMessage(robotinfo_msgs::RobotInfo10Fields &msg) const {
  msg.data_field_01 = this->robot_description;
  msg.data_field_02 = this->serial_number;
  msg.data_field_03 = this->ip_address;
  msg.data_field_04 = this->firmware_version;
}

void RobotInfo::InfoPublisher() {
  this->robot_info_publisher = nh->advertise<robotinfo_msgs::RobotInfo10Fields>(
      this->robot_info_topic, 1000);
  ROS_INFO("Robot info publisher initialized.");
}
void RobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields msg;
  this->RobotMessage(msg);
  robot_info_publisher.publish(msg);
}