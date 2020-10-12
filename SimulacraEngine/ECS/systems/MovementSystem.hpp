//
//  MovementSystem.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 05/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include "System.hpp"

namespace ECS {
    class MovementSystem : public UpdateSystem {
    public:
        MovementSystem(const EntityList& list);
        virtual void update(const float& dt) override;
        
    private:
        Action action;
        Action lastAction;
    };
}
