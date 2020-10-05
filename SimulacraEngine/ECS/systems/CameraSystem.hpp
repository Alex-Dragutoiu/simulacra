//
//  CameraSystem.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 06/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include "System.hpp"

namespace ECS {
    
    class CameraSystem : public UpdateSystem {
    public:
        CameraSystem(const EntityList& list);
        virtual void update(const float& dt) override;
    };
}
