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

    hydraulic_system.setOilTemperature("hydraulic_oil_temperature: 45C");
    hydraulic_system.setOilTankFillLevel("hydraulic_oil_tank_fill_level: 100 %");
    hydraulic_system.setOilPressure("hydraulic_oil_pressure: 250 bar");

    msg.data_field_06 = hydraulic_system.getOilTemperature();
    msg.data_field_07 = hydraulic_system.getOilTankFillLevel();
    msg.data_field_08 = hydraulic_system.getOilPressure();

    robot_info_publisher.publish(msg);
}