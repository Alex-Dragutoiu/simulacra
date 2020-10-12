//
//  CollisionSystem.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 07/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include "System.hpp"
#include "QuadTree.hpp"

#include <unordered_map>
#include <memory>

namespace ECS {
    class CollisionSystem : public UpdateSystem {
    public:
        CollisionSystem(const EntityList& list);
        virtual void update(const float& dt) override;
        
    private:
        std::vector<std::shared_ptr<Entity>> collidables;
        std::shared_ptr<QuadTree> collision;
    };
}
