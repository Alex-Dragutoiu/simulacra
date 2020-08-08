//
//  TransformationComponent.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 07/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>

#include "../Component.hpp"
#include "../../entities/GameObject.hpp"

namespace simulacra {
    
    class TransformationComponent : public Component {
    public:        
        TransformationComponent(GameObject* owner, const float& x, const float& y);
        TransformationComponent(GameObject* owner, const sf::Vector2f& position);
        TransformationComponent(GameObject* owner);
        ~TransformationComponent() = default;
        
        void setPosition(const sf::Vector2f& position);
        void setPosition(const float& x, const float& y);
        sf::Vector2f getPosition();
        
    private:
        sf::Vector2f position;
    };
}
