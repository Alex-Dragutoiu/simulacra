//
//  Component.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 19/07/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "Component.hpp"

namespace simulacra {
    
    Component::Component(GameObject* owner) {
        this->owner = owner;
        active = true;
    }
    
    bool Component::isActive() {
        return active;
    }

    void Component::setActive(bool active) {
        this->active = active;
    }
    
    void Component::update(const sf::Time& dt) { }
    
    void Component::draw(sf::RenderTarget& target) { }

}

//        switch (state) {
//            case MovementState::IDLE:
//                rect->left = 0;
//                break;
//            case MovementState::LEFT:
//                rect->top = offset * 9;
//                setFrame(dt.asSeconds());
//                break;
//            case MovementState::RIGHT:
//                rect->top = offset * 11;
//                setFrame(dt.asSeconds());
//                break;
//            default:
//                std::cout << "[WARNING]: Unknown state!";
//                break;
//        }


//        sprite.setOrigin((sprite.getPosition().x * 2 + sprite.getGlobalBounds().width) / 2,
//                         (sprite.getPosition().y * 2 + sprite.getGlobalBounds().height) / 2);
