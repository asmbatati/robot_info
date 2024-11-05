cmake_minimum_required(VERSION 3.0.2)
project(robot_info)

find_package(catkin REQUIRED COMPONENTS
  robotinfo_msgs
  roscpp
)

catkin_package(
 INCLUDE_DIRS include
 LIBRARIES robot_info
 CATKIN_DEPENDS robotinfo_msgs roscpp
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node src/robot_info_class.cpp src/robot_info_main.cpp)
add_executable(agv_robot_info_node src/robot_info_class.cpp 
								   src/agv_robot_info_class.cpp
								   src/agv_robot_info_main.cpp
								   src/hydraulic_system_monitor.cpp)

target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})
target_link_libraries(agv_robot_info_node ${catkin_LIBRARIES})