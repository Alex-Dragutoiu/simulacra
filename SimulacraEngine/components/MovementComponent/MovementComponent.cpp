//
//  MovementComponent.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 07/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "MovementComponent.hpp"

namespace simulacra {
    
    MovementComponent::MovementComponent(GameObject* owner, const float& velocity) : Component(owner), velocity(velocity) {
        action = lastAction = Action::IDLE_RIGHT;
        
        transformation_c = owner->getComponent<TransformationComponent>();
        sprite_c = owner->getComponent<SpriteComponent>();
        animation_c = owner->getComponent<AnimationComponent>();
    }
    
    MovementComponent::~MovementComponent() { }
    
    void MovementComponent::update(const sf::Time &dt) {
        if (!animation_c->isPlaying() || action != Action::ATTACK_RIGHT) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                move(dt.asSeconds(), -1.f, 0.f);
                action = Action::LEFT;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                move(dt.asSeconds(), 1.f, 0.f);
                action = Action::RIGHT;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
                action = Action::ATTACK_RIGHT;
            } else {
                if (lastAction == Action::LEFT) {
                    action = Action::IDLE_LEFT;
                } else if (lastAction == Action::RIGHT) {
                    action = Action::IDLE_RIGHT;
                } else if (lastAction == Action::ATTACK_RIGHT) {
                    action = Action::IDLE_RIGHT;
                }
            }
        }
        
        if (animation_c != nullptr) {
            animation_c->play(action, dt);
        }
        
        lastAction = action;
    }
    
    void MovementComponent::move(const float dt, const float xDir, const float yDir) {
        
        float newPosX = transformation_c->getPosition().x + dt * xDir * velocity;
        
        /* Only allow player to move on positive X axis */
        if (newPosX >= 0) {
            sprite_c->move(dt * xDir * velocity, dt * yDir * velocity);
        }
    }
    
    void MovementComponent::setVelocity(const float& velocity) {
        this->velocity = velocity;
    }
    
    Action MovementComponent::getAction() {
        return action;
    }
}
