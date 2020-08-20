//
//  CollisionComponent.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 17/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "../Component.hpp"

#include "../../entities/GameObject.hpp"

namespace simulacra {
    
    class GameObject;
    
    class CollisionComponent : public Component {
    public:
        CollisionComponent(GameObject* owner);
        ~CollisionComponent();
        
    private:
        sf::IntRect collider;
    
    };
}
