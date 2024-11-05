#pragma once
#include "robot_info/robot_info_class.h"
#include "robot_info/hydraulic_system_monitor.h"

class AGVRobotInfo : public RobotInfo {
private:
    std::string maximum_payload;
    HydraulicSystemMonitor hydraulic_system;
public:
    using RobotInfo::RobotInfo;
    
    AGVRobotInfo(ros::NodeHandle* nh);

    AGVRobotInfo(ros::NodeHandle* nh, const std::string& maximum_payload);

    void publish_data() override;
};