#pragma once
#include "robot_info/robot_info_class.h"

class AGVRobotInfo : public RobotInfo {
private:
    std::string maximum_payload;
public:
    using RobotInfo::RobotInfo;
    
    AGVRobotInfo(ros::NodeHandle* nh);

    AGVRobotInfo(ros::NodeHandle* nh, const std::string& maximum_payload);

    void publish_data() override;
};