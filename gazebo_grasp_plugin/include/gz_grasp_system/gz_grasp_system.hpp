// Copyright 2023 PickNik Inc.
// All rights reserved.
//
// Unauthorized copying of this code base via any medium is strictly prohibited.
// Proprietary and confidential.

#pragma once

// https://gazebosim.org/api/sim/7/migrationplugins.html
// https://github.com/gazebosim/gz-sim/pull/977
// https://github.com/gazebosim/ros_gz
// https://github.com/kongoncharuk/gazebo-pkgs/tree/humble

#ifdef GZ_HEADERS
#include <gz/sim/System.hh>
namespace sim = gz::sim;
#else
#include <ignition/gazebo/System.hh>
namespace sim = ignition::gazebo;
#endif

namespace gz_grasp_system
{

class GzGraspSystem
  : public sim::System,
  public sim::ISystemConfigure,
  public sim::ISystemPreUpdate,
  public sim::ISystemPostUpdate
{
public:
  /// \brief Constructor
  GzGraspSystem();

  /// \brief Destructor
  ~GzGraspSystem() override;

  // Documentation inherited
  void Configure(
    const sim::Entity & _entity,
    const std::shared_ptr<const sdf::Element> & _sdf,
    sim::EntityComponentManager & _ecm,
    sim::EventManager & _eventMgr) override;

  // Documentation inherited
  void PreUpdate(
    const sim::UpdateInfo & _info,
    sim::EntityComponentManager & _ecm) override;

  void PostUpdate(
    const sim::UpdateInfo & _info,
    const sim::EntityComponentManager & _ecm) override;

};
 
}  // namespace gz_grasp_system
