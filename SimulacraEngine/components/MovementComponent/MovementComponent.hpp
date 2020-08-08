//
//  MovementComponent.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 07/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>

#include "../Component.hpp"

#include "../SpriteComponent/SpriteComponent.hpp"
#include "../TransformationComponent/TransformationComponent.hpp"
#include "../AnimationComponent/AnimationComponent.hpp"

#include "../../entities/GameObject.hpp"
#include "../../enums.h"

namespace simulacra {
    
    /* Component responsible for the movement of the player */
    class MovementComponent : public Component {
    public:
        MovementComponent(GameObject* owner, const float& velocity);
        ~MovementComponent();
        
        void update(const sf::Time& dt);
        void setVelocity(const float& velocity);
        
        Action getAction();
        
    private:
        void move(const float dt, const float xDir, const float yDir);
        
    private:
        Action action;
        Action lastAction;
        
        float velocity;
        
        std::shared_ptr<TransformationComponent> transformation_c;
        std::shared_ptr<AnimationComponent> animation_c;
        std::shared_ptr<SpriteComponent> sprite_c;
    };
}

