//
//  AnimationSystem.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 05/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include "System.hpp"

#include <unordered_map>

namespace ECS {
    
    class AnimationSystem : public UpdateSystem {
    public:
        AnimationSystem(const EntityList& list);
        virtual void update(const float& dt) override;
        
    };
}
