//
//  Entity.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 02/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "Entity.hpp"

namespace ECS {
    Entity::Entity(EntityID id) : id(id) { }
    
    Entity::~Entity() { }
    
    EntityID Entity::getInstanceID() {
        return id;
    }
    
    const Signature Entity::getSignature() const {
        return compBitmask;
    }
}
