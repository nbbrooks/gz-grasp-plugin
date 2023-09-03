cmake_minimum_required(VERSION 3.5)
project(gz_grasp_system)

# Default to C11
if(NOT CMAKE_C_STANDARD)
    set(CMAKE_C_STANDARD 11)
endif()
# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()

# Compiler options
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_index_cpp REQUIRED)
find_package(pluginlib REQUIRED)
find_package(rclcpp REQUIRED)
find_package(yaml_cpp_vendor REQUIRED)

set(THIS_PACKAGE_INCLUDE_DEPENDS
  ament_index_cpp
  pluginlib
  rclcpp
  yaml_cpp_vendor
)

set(GZ_PLUGIN)
set(GZ_SIM)

if("$ENV{GZ_VERSION}" STREQUAL "garden")
  find_package(gz-sim7 REQUIRED)
  set(GZ_SIM_VER ${gz-sim7_VERSION_MAJOR})
  message(STATUS "Compiling against Gazebo Garden")
  find_package(gz-plugin2 REQUIRED)
  set(GZ_PLUGIN_VER ${gz-plugin2_VERSION_MAJOR})
  set(GZ_PLUGIN gz-plugin${GZ_PLUGIN_VER}::register)
  set(GZ_SIM gz-sim${GZ_SIM_VER}::core)
  add_definitions(-DGZ_HEADERS)
else()
  find_package(ignition-gazebo6 REQUIRED)
  set(GZ_SIM_VER ${ignition-gazebo6_VERSION_MAJOR})
  message(STATUS "Compiling against Gazebo Fortress")
  find_package(ignition-plugin1 REQUIRED)
  set(GZ_PLUGIN_VER ${ignition-plugin1_VERSION_MAJOR})
  set(GZ_PLUGIN ignition-plugin${GZ_PLUGIN_VER}::register)
  set(GZ_SIM ignition-gazebo${GZ_SIM_VER}::core)
endif()

###

include_directories(include)

###

add_library(${PROJECT_NAME}_plugin SHARED
  src/gz_grasp_system.cpp
)

target_link_libraries(${PROJECT_NAME}_plugin
  ${GZ_SIM}
  ${GZ_PLUGIN}
)
ament_target_dependencies(${PROJECT_NAME}_plugin ${THIS_PACKAGE_INCLUDE_DEPENDS})


#############
## Install ##
#############

install(DIRECTORY
  include
  DESTINATION include
)

install(TARGETS
  ${PROJECT_NAME}_plugin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

# Testing and linting
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()


# pluginlib_export_plugin_description_file(${PROJECT_NAME} gz_grasp_plugins.xml)

# Set up the project
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_package()
