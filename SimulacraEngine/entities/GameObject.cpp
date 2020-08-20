//
//  GameObject.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 19/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "GameObject.hpp"

namespace simulacra {
    
    bool GameObject::isAlive() const {
        return alive;
    }
    
    void GameObject::dispose() {
        alive = false;
    }
    
    ObjectID GameObject::getInstanceID() {
        return id;
    }
    
    void GameObject::draw(sf::RenderTarget& target) {
        for (auto& _component : components) {
            _component->draw(target);
        }
    }
    
    void GameObject::update(const sf::Time& dt) {
        for (auto& _component : components) {
            _component->update(dt);
        }
    }
}
