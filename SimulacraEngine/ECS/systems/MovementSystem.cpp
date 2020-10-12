//
//  MovementSystem.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 05/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "MovementSystem.hpp"

namespace ECS {
    MovementSystem::MovementSystem(const EntityList& list) : UpdateSystem(list) { }
    
    void MovementSystem::update(const float& dt) {
        for (auto& entity : entities) {
            if (entity->hasComponent<SpriteComponent>() && entity->hasComponent<TransformationComponent>() && entity->hasComponent<VelocityComponent>()) {
                auto velocity = entity->getComponent<VelocityComponent>()->velocity;
                auto transComp = entity->getComponent<TransformationComponent>();
                
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    transComp->move(dt * -1.f * velocity, 0.f);
                    if (entity->hasComponent<ColliderComponent>()) {
                        auto colliderComp = entity->getComponent<ColliderComponent>();
                        colliderComp->move(dt * -1 * velocity, 0.f);
                    }
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    transComp->move(dt * 1.f * velocity, 0.f);
                    if (entity->hasComponent<ColliderComponent>()) {
                        auto colliderComp = entity->getComponent<ColliderComponent>();
                        colliderComp->move(dt * 1 * velocity, 0.f);
                    }
                }
            }
        }
    }
    
    //    void MovementComponent::update(const sf::Time &dt) {
    //        if (!animation_c->isPlaying() || action != Action::ATTACK_RIGHT) {
    //            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    //                move(dt.asSeconds(), -1.f, 0.f);
    //                action = Action::LEFT;
    //            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    //                move(dt.asSeconds(), 1.f, 0.f);
    //                action = Action::RIGHT;
    //            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
    //                action = Action::ATTACK_RIGHT;
    //            } else {
    //                if (lastAction == Action::LEFT) {
    //                    action = Action::IDLE_LEFT;
    //                } else if (lastAction == Action::RIGHT) {
    //                    action = Action::IDLE_RIGHT;
    //                } else if (lastAction == Action::ATTACK_RIGHT) {
    //                    action = Action::IDLE_RIGHT;
    //                }
    //            }
    //        }
    //
    //        if (animation_c != nullptr) {
    //            animation_c->play(action, dt);
    //        }
    //
    //        lastAction = action;
    //    }

}
