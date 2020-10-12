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
#include "Animation.hpp"

#include <unordered_map>
#include <string>

#include "../../Utils.h"

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
            drawTheColliderBox = true;
        }
        
        ColliderComponent(EntityID owner, const sf::FloatRect& collider) : Component(owner), collider(collider) {
            drawTheColliderBox = true;
        }
        
        void move(const float& xDir, const float& yDir) {
            collider.left += xDir;
            collider.top += yDir;
        }
        
        virtual bool intersects(std::shared_ptr<ColliderComponent> other) {
            std::shared_ptr<ColliderComponent> collider = std::dynamic_pointer_cast<ColliderComponent>(other);
            if (collider) {
                const sf::FloatRect& rect1 = getCollidable();
                const sf::FloatRect& rect2 = collider->getCollidable();
                if (rect1.intersects(rect2)) {
                    return true;
                }
            }
            return false;
        }
        
        virtual sf::Vector2f resolveOverlap(std::shared_ptr<ColliderComponent> other) {
            const sf::FloatRect& rect1 = getCollidable();
            sf::FloatRect& rect2 = other->getCollidable();
            
            float resolve = 0;
            sf::Vector2f vect;
            
            float xDiff = rect1.left - rect2.left;
            float yDiff = rect1.top  - rect2.top;
            
            if (fabs(xDiff) > fabs(yDiff)) {
                // Colliding on the left.
                if (xDiff > 0) {
                    // We add a positive x value to move the object to the right.
                    resolve = (rect2.left + rect2.width) - rect1.left;
                } else {
                    // Colliding on the right.
                    // We add a negative x value to move the object to the left.
                    resolve = -((rect1.left + rect1.width) - rect2.left);
                }
                return sf::Vector2f(resolve, 0.f);
            } else {
                // Colliding above.
                if (yDiff > 0) {
                    // We add a positive y value to move the object down.
                    resolve = (rect2.top + rect2.height) - rect1.top;
                } else {
                    // Colliding below
                    // We add a negative y value to move the object up.
                    resolve = -((rect1.top + rect1.height) - rect2.top);
                }
                return sf::Vector2f(0.f, resolve);
            }
            return sf::Vector2f(0.f, 0.f);
        }
        
        sf::FloatRect& getCollidable() {
            return collider;
        }
        
        void setPosition(const sf::Vector2f& position) {
            collider.left = position.x;
            collider.top = position.y;
        }
        
        void setPosition(const float& x, const float& y) {
            collider.left = x;
            collider.top = y;
        }
        
        void draw(sf::RenderTarget& target) {
            if (drawTheColliderBox) {
                target.draw(rectangle(collider.left, collider.top, collider.width, collider.height, sf::Color::Red));
            }
        }
        
        sf::FloatRect& getCollider() {
            return collider;
        }
        
        void setDrawable(bool drawTheColliderBox) {
            this->drawTheColliderBox = drawTheColliderBox;
        }
        
        bool& isDrawable() {
            return drawTheColliderBox;
        }
        
    private:
        bool drawTheColliderBox;
        sf::FloatRect collider;
    
    };
    

    class AnimationComponent : public Component {
    public:
        AnimationComponent(EntityID owner, const double& delay) : Component(owner), delay(delay) { }
        
        void addAnimation(std::string action, sf::Texture* animation, const int& width, const int& height) {
            int frames = animation->getSize().x / width;
            Animation anim(animation, frames, width, height, delay);
            animations.insert(std::make_pair(action, anim));
        }
        
        Animation getAnimation(std::string action) {
            auto found = animations.find(action);
            assert(found != animations.end());
            
            return found->second;
        }
        
    private:
        double delay;
        std::unordered_map<std::string, Animation> animations;
        
    };
}
