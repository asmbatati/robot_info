# cmake_minimum_required(VERSION 3.0.2)
# project(robot_info)

# find_package(catkin REQUIRED COMPONENTS
#   robotinfo_msgs
#   roscpp
# )

# catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES robot_info
#  CATKIN_DEPENDS robotinfo_msgs roscpp
# #  DEPENDS system_lib
# )

# include_directories(
#   include
#   ${catkin_INCLUDE_DIRS}
# )

# add_library(robot_info src/robot_info_class.cpp src/agv_robot_info_class.cpp)

# add_executable(${PROJECT_NAME}_node src/robot_info_main.cpp)
# add_executable(agv_robot_info_node src/agv_robot_info_main.cpp src/hydraulic_system_monitor.cpp)

# target_link_libraries(${PROJECT_NAME}_node robot_info ${catkin_LIBRARIES})
# target_link_libraries(agv_robot_info_node robot_info ${catkin_LIBRARIES})

cmake_minimum_required(VERSION 3.0.2)
project(robot_info)

find_package(catkin REQUIRED COMPONENTS
  robotinfo_msgs
  roscpp
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES robot_info
#  CATKIN_DEPENDS robotinfo_msgs roscpp
#  DEPENDS system_lib
  INCLUDE_DIRS include
  LIBRARIES robot_info
  CATKIN_DEPENDS robotinfo_msgs roscpp
)

add_library(robot_info
  src/robot_info_class.cpp
  src/agv_robot_info_class.cpp
  src/hydraulic_system_monitor.cpp
)
target_link_libraries(robot_info ${catkin_LIBRARIES})

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(robot_info_node src/robot_info_class.cpp src/robot_info_main.cpp)
target_link_libraries(robot_info_node robot_info ${catkin_LIBRARIES})

add_executable(agv_robot_info_node src/robot_info_class.cpp src/agv_robot_info_class.cpp src/hydraulic_system_monitor.cpp src/agv_robot_info_main.cpp)
target_link_libraries(agv_robot_info_node robot_info ${catkin_LIBRARIES})