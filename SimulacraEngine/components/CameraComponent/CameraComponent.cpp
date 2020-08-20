//
//  CameraComponent.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 07/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "CameraComponent.hpp"

namespace simulacra {

    CameraComponent::CameraComponent(GameObject* owner, std::shared_ptr<sf::View> camera) : Component(owner) {
        this->camera = camera;
        transformation = owner->getComponent<TransformationComponent>();

        /* Make camera centered on player
         * Apply camera boundary given player initial position
         */
        if (transformation->getPosition().x < camera->getCenter().x / 2) {
            camera->setCenter(camera->getCenter().x, transformation->getPosition().y);
        } else {
            camera->setCenter(transformation->getPosition());
        }
        
    }

    CameraComponent::~CameraComponent() { }

    void CameraComponent::update(const sf::Time& dt) {

        if (transformation->getPosition().x >= camera->getSize().x / 2) {
            camera->setCenter(transformation->getPosition());
        }
    }

    /// \todo once you set up a new camera attached to the object you need to center it on the object
    void CameraComponent::setCamera(const std::shared_ptr<sf::View>& camera) {
        this->camera = camera;
    }
}
