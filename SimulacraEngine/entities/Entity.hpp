//
//  Entity.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 25/07/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include "GameObject.hpp"
#include "../components/SpriteComponent/SpriteComponent.hpp"

namespace simulacra {
    class Entity : public GameObject {
    public:
        Entity();
        virtual ~Entity() { }
        
        void update(const sf::Time& dt) override;
        void draw(sf::RenderTarget& target) override;
    
        void setHealth(const float& health);
        float getHealh();
        
        void setDamage(const float& damage);
        float getDamage();
        
        void setArmor(const float& armor);
        float getArmor();
        
        void setMana(const float& mana);
        float getMana();
        
        void setSpeed(const float& speed);
        float getSpeed();
        
    protected:
        float health;
        float damage;
        float armor;
        float mana;
        float speed;
    };
}
