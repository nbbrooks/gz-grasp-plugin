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
  ros_gz_grasp_fix::GraspFix::ISystemUpdate,
  ros_gz_grasp_fix::GraspFix::ISystemPostUpdate)


namespace
{

const std::string LEFT_TIP = "robotiq_85_left_finger_tip_link";
const std::string RIGHT_TIP = "robotiq_85_right_finger_tip_link";

}  //

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

void GraspFix::Configure(
  const ignition::gazebo::Entity & _entity,
  const std::shared_ptr < const sdf::Element > & _sdf,
  ignition::gazebo::EntityComponentManager & _ecm,
  ignition::gazebo::EventManager &)
{
    std::cerr << "### ROS_GZ_GRASP_FIX::CONFIGURE" << std::endl;
}

void GraspFix::Update(
  const ignition::gazebo::UpdateInfo &  _info,
  ignition::gazebo::EntityComponentManager &  _ecm) {
  // std::cerr << "### ROS_GZ_GRASP_FIX::UPDATE" << std::endl;

  // if ((common::Time::GetWallTime() - this->prevUpdateTime) < this->updateRate)
  //   return;

  // // first, copy all contact data into local struct. Don't do the complex grip check (CheckGrip)
  // // within the mutex, because that slows down OnContact().
  // this->mutexContacts.lock();
  // std::map<std::string, std::map<std::string, CollidingPoint> > contPoints(
  //   this->contacts);
  // this->contacts.clear(); // clear so it can be filled anew by OnContact().
  // this->mutexContacts.unlock();
}

void GraspFix::PostUpdate(
  const ignition::gazebo::UpdateInfo & _info,
  const ignition::gazebo::EntityComponentManager & _ecm)
{

    // std::cerr << "### ROS_GZ_GRASP_FIX::POST_UPDATE" << std::endl;
}

}  // namespace ros_gz_grasp_fix
