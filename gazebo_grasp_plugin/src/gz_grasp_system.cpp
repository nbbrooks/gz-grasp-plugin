// Copyright 2023 PickNik Inc.
// All rights reserved.
//
// Unauthorized copying of this code base via any medium is strictly prohibited.
// Proprietary and confidential.

#include "gz_grasp_system/gz_grasp_system.hpp"

#ifdef GZ_HEADERS
#include <gz/sim/components/Joint.hh>
#include <gz/sim/components/JointType.hh>
#include <gz/sim/components/Name.hh>
#include <gz/sim/components/ParentEntity.hh>
#include <gz/sim/components/World.hh>
#include <gz/sim/Model.hh>
#include <gz/plugin/Register.hh>
#else
#include <ignition/gazebo/components/Joint.hh>
#include <ignition/gazebo/components/JointType.hh>
#include <ignition/gazebo/components/Name.hh>
#include <ignition/gazebo/components/ParentEntity.hh>
#include <ignition/gazebo/components/World.hh>
#include <ignition/gazebo/Model.hh>
#include <ignition/plugin/Register.hh>
#endif


namespace gz_grasp_system
{


  void GzGraspSystem::Configure(
    const sim::Entity & _entity,
    const std::shared_ptr<const sdf::Element> & _sdf,
    sim::EntityComponentManager & _ecm,
    sim::EventManager & _eventMgr) {
    ignmsg << "GzGraspSystem::Configure" << std::endl;
    std::cerr << "GzGraspSystem::Configure" << std::endl;
  }


  void GzGraspSystem::PostUpdate(const gz::sim::UpdateInfo &_info,
      const gz::sim::EntityComponentManager &_ecm)
  {
    ignmsg << "SampleSystem::PostUpdate" << std::endl;
    std::cerr << "SampleSystem::PostUpdate" << std::endl;
  }
}  // namespace gz_grasp_system

#ifdef GZ_HEADERS
GZ_ADD_PLUGIN(
  gz_grasp_system::GzGraspSystem,
  gz::sim::System,
  gz_grasp_system::GzGraspSystem::ISystemConfigure,
  gz_grasp_system::GzGraspSystem::ISystemPreUpdate,
  gz_grasp_system::GzGraspSystem::ISystemPostUpdate)
GZ_ADD_PLUGIN_ALIAS(
  gz_grasp_system::GzGraspSystem,
  "gz_grasp_system::GzGraspSystemPlugin")
#else
IGNITION_ADD_PLUGIN(
  gz_grasp_system::GzGraspSystem,
  ignition::gazebo::System,
  gz_grasp_system::GzGraspSystem::ISystemConfigure,
  gz_grasp_system::GzGraspSystem::ISystemPreUpdate,
  gz_grasp_system::GzGraspSystem::ISystemPostUpdate)
IGNITION_ADD_PLUGIN_ALIAS(
  gz_grasp_system::GzGraspSystem,
  "gz_grasp_system::GzGraspSystemPlugin")
#endif
