// Copyright 2023 PickNik Inc.
// All rights reserved.
//
// Unauthorized copying of this code base via any medium is strictly prohibited.
// Proprietary and confidential.

#include "grasp_fix.hh"

#include <iostream>

#include <ignition/plugin/Register.hh>
#include <rclcpp/rclcpp.hpp>

IGNITION_ADD_PLUGIN(
  ros_gz_grasp_fix::GraspFix,
  ignition::gazebo::System,
  ros_gz_grasp_fix::GraspFix::ISystemConfigure,
  ros_gz_grasp_fix::GraspFix::ISystemPostUpdate)

namespace ros_gz_grasp_fix
{
class GraspFixPrivate
{


public:
  ignition::gazebo::Entity entity_;

public:
  std::chrono::steady_clock::duration current_time_;

};

//////////////////////////////////////////////////
GraspFix::GraspFix()
: dataPtr(std::make_unique < GraspFixPrivate > ())
{
    std::cerr << "### ROS_GZ_GRASP_FIX::ROS_GZ_GRASP_FIX" << std::endl;
}

//////////////////////////////////////////////////
void GraspFix::Configure(
  const ignition::gazebo::Entity & _entity,
  const std::shared_ptr < const sdf::Element > & _sdf,
  ignition::gazebo::EntityComponentManager & _ecm,
  ignition::gazebo::EventManager &)
{
    std::cerr << "### ROS_GZ_GRASP_FIX::CONFIGURE" << std::endl;
}

//////////////////////////////////////////////////
void GraspFix::PostUpdate(
  const ignition::gazebo::UpdateInfo & _info,
  const ignition::gazebo::EntityComponentManager & _ecm)
{

    std::cerr << "### ROS_GZ_GRASP_FIX::POST_UPDATE" << std::endl;

}
}  // namespace ros_gz_grasp_fix
