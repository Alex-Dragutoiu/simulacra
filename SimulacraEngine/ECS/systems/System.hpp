//
//  System.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 02/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include "utils.h"
#include "../entities/Entity.hpp"

namespace ECS {
    class Entity;
    
    class System {
    public:
        System() {}
        System(const EntityList& list) : entities(list) { }
        virtual ~System() { }
    
        EntityList getEntities() const { return entities; }
        
    protected:
        EntityList entities;
    };
    
    class DrawSystem : public System {
    public:
        DrawSystem() : System() { }
        virtual void draw(sf::RenderTarget& target) = 0;
        
    public:
        DrawSystem(const EntityList& list) : System(list) { }

    };
    
    class UpdateSystem : public System {
    public:
        UpdateSystem() : System() { }
        virtual void update(const float& dt) = 0;

    public:
        UpdateSystem(const EntityList& list) : System(list) { }

    };

}
