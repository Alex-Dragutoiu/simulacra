//
//  TransformationComponent.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 07/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "TransformationComponent.hpp"

namespace simulacra {

    TransformationComponent::TransformationComponent(GameObject* owner) : Component(owner) {
        position.x = 0;
        position.y = 0;
    }

    TransformationComponent::TransformationComponent(GameObject* owner, const sf::Vector2f& position) : Component(owner) {
        this->position = position;
    }

    TransformationComponent::TransformationComponent(GameObject* owner, const float& x, const float& y) : Component(owner) {
        position.x = x;
        position.y = y;
    }

    void TransformationComponent::setPosition(const sf::Vector2f& position) {
        this->position = position;
    }

    void TransformationComponent::setPosition(const float& x, const float& y) {
        position.x = x;
        position.y = y;
    }

    sf::Vector2f TransformationComponent::getPosition() {
        return position;
    }
}
