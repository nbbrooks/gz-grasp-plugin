// Copyright 2023 PickNik Inc.
// All rights reserved.
//
// Unauthorized copying of this code base via any medium is strictly prohibited.
// Proprietary and confidential.

#pragma once

#include <memory>
#include <ignition/gazebo/System.hh>

namespace ros_gz_grasp_fix
{
  // Forward declarations.
  class GraspFixPrivate;

  class GraspFix:
  public ignition::gazebo::System,
  public ignition::gazebo::ISystemConfigure,
  public ignition::gazebo::ISystemPostUpdate
  {
    /// \brief Constructor

public:
    GraspFix();

    /// \brief Destructor

public:
    ~GraspFix() override = default;

    // Documentation inherited

public:
    void Configure(
      const ignition::gazebo::Entity & _entity,
      const std::shared_ptr < const sdf::Element > & _sdf,
      ignition::gazebo::EntityComponentManager & _ecm,
      ignition::gazebo::EventManager & _eventMgr) override;

    // Documentation inherited

public:
    void PostUpdate(
      const ignition::gazebo::UpdateInfo & _info,
      const ignition::gazebo::EntityComponentManager & _ecm) override;

   /// \brief Private data pointer.

private:
    std::unique_ptr < GraspFixPrivate > dataPtr;
  };
}
