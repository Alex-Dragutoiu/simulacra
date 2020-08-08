//
//  Entity.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 25/07/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "Entity.hpp"


namespace simulacra {

    Entity::Entity() : GameObject() { }

    void Entity::draw(sf::RenderTarget& target) {
        auto spriteComponent = getComponent<SpriteComponent>();
        if (spriteComponent != nullptr) {
            spriteComponent->draw(target);
        }
    }

    void Entity::update(const sf::Time& dt) {
        for (auto& component : components) {
            component->update(dt);
        }
    }
    
    float Entity::getDamage() { 
        return damage;
    }
    
    void Entity::setDamage(const float &damage) { 
        this->damage = damage;
    }
    
    float Entity::getHealh() { 
        return health;
    }
    
    void Entity::setHealth(const float &health) { 
        this->health = health;
    }
    
    float Entity::getSpeed() { 
        return speed;
    }
    
    void Entity::setSpeed(const float &speed) { 
        this->speed = speed;
    }
    
    float Entity::getMana() { 
        return mana;
    }
    
    void Entity::setMana(const float &mana) { 
        this->mana = mana;
    }
    
    float Entity::getArmor() { 
        return armor;
    }
    
    void Entity::setArmor(const float &armor) { 
        this->armor = armor;
    }
}
