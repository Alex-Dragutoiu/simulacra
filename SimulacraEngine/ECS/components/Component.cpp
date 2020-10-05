//
//  Component.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 02/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "Component.hpp"

namespace ECS {

    Component::Component(EntityID owner) : owner(owner) {
        active = true;
    }
    
    EntityID Component::getOwner() {
        return owner;
    }
    
    void Component::setActive(bool active) {
        this->active = active;
    }
    
    bool Component::isActive() {
        return active;
    }
    
    void Component::toString() {
        
    }
}
