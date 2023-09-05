cmake_minimum_required(VERSION 3.5)

project(ros_gz_grasp_fix)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

find_package(ignition-gazebo6)

include_directories(
  src
)

set(PLUGIN_NAME RosGzGraspFix)

add_library(${PLUGIN_NAME} SHARED
  src/grasp_fix.cc
)

ament_target_dependencies(${PLUGIN_NAME}
  rclcpp
)

target_link_libraries(${PLUGIN_NAME}
  ignition-gazebo6::core
)

install(TARGETS ${PLUGIN_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

# Setup the project
ament_package()
