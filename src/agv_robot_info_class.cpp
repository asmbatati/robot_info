#include "robot_info/agv_robot_info_class.h"

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle* nh) : RobotInfo(nh) {
    this->maximum_payload = "maximum_payload: 100 Kg";
}
AGVRobotInfo::AGVRobotInfo(ros::NodeHandle* nh, const std::string& maximum_payload)
    : RobotInfo(nh),
      maximum_payload(maximum_payload) {}
void AGVRobotInfo::publish_data() {
    robotinfo_msgs::RobotInfo10Fields msg;
    
    this->RobotMessage(msg);
    msg.data_field_05 = this->maximum_payload;
    robot_info_publisher.publish(msg);
}