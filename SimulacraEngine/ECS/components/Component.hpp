//
//  Component.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 02/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "../utils.h"

namespace ECS {
    
    class Component {
    public:
        EntityID getOwner();

        bool isActive();
        void setActive(bool active);
        
    public:
        Component(EntityID owner);
        
        virtual ~Component() {
            
        }
        
        virtual void toString();
        
    private:
        EntityID owner;
        bool active;
    };
    
    struct TransformationComponent : public Component {
    public:
        TransformationComponent(EntityID owner, const sf::Vector2f& position, const sf::Vector2f& scale, const float& rotation) : Component(owner), position(position), scale(scale), rotation(rotation) { }
        
        void move(const float& xDir, const float& yDir) {
            position.x += xDir;
            position.y += yDir;
        }
        
        sf::Vector2f position;
        sf::Vector2f scale;
        float rotation;
    };
    
    struct VelocityComponent : public Component {
        VelocityComponent(EntityID owner, const float& velocity) : Component(owner), velocity(velocity) { }
        
        float velocity;
    };
    
    struct SpriteComponent : public Component {
    public:
        SpriteComponent(EntityID owner, sf::Texture& texture) : Component(owner), texture(texture) {
            m_sprite.setTexture(texture);
        }
        
        sf::Texture& texture;
        sf::Sprite m_sprite;
    };
    
    class ColliderComponent : public Component {
    public:
        ColliderComponent(EntityID owner, sf::Vector2u position, sf::Vector2u dimension) : Component(owner) {
            collider.left = position.x;
            collider.top = position.y;
            collider.width = dimension.x;
            collider.height = dimension.y;
        }
        
        ColliderComponent(EntityID owner, const sf::FloatRect& collider) : Component(owner), collider(collider) {
            
        }
        
        void move(const float& xDir, const float& yDir);
        sf::FloatRect collider;
        
        //        void CollisionComponent::draw(sf::RenderTarget& target) {
        //            target.draw(rectangle(box.left, box.top, box.width, box.height, sf::Color::Red));
        //        }
        //
        //        void CollisionComponent::move(const float &xDir, const float &yDir) {
        //            box.left += xDir;
        //            box.top += yDir;
        //        }
    };
    
    
    
}
