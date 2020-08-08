//
//  Component.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 19/07/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>

#include "../entities/GameObject.hpp"
#include "../utilities/AssetLoader.hpp"

#include "../enums.h"
#include "../ResourceIdentifiers.h"

namespace simulacra {
    
    class GameObject;
    
    /* Basic Component */
    class Component {
    public:
        enum class Types {
            MOVEMENT,
            CAMERA,
            ANIMATION,
            PHYSICS
        };
    
    public:
        bool isActive();
        void setActive(bool active);
        GameObject* getOwner();
        
    public:
        virtual void update(const sf::Time& dt);
        virtual void draw(sf::RenderTarget& target);
        
        Component(GameObject* owner);
        virtual ~Component() { }
        
    protected:
        GameObject* owner;
        
    private:
        bool active;
        
    };
    
}
    //// SPRITE COMPONENT ////
//    class SpriteComponent : public Component {
//    public:
//        SpriteComponent(GameObject* owner, sf::Texture* texture);
//        ~SpriteComponent();
//        
//        void update(const sf::Time& dt) override;
//        void draw(sf::RenderTarget& target);
//        
//        void setTexture(const sf::Texture& texture);
//        void setTextureRect(int x, int y, int width, int height);
//        void setTextureRect(const sf::IntRect& rect);
//        
//        sf::Sprite& getSprite();
//        
//        void move(float offsetX, float offsetY);
//        
//    private:
//        sf::Texture* texture;
//        sf::Sprite sprite;
//        
//        std::shared_ptr<TransformComponent> transformation_c;
//    };
    
//    /* Component responsible for the movement of the player */
//    class MovementComponent : public Component {
//    public:
//        MovementComponent(GameObject* owner, const float& velocity);
//        ~MovementComponent();
//
//        void update(const sf::Time& dt) override;
//        void setVelocity(const float& velocity);
//
//        Action getAction();
//
//    private:
//        void move(const float dt, const float xDir, const float yDir);
//
//    private:
//        Action action;
//        Action lastAction;
//
//        float velocity;
//
//        std::shared_ptr<TransformComponent> transformation;
//        std::shared_ptr<AnimationComponent> animation_c;
//        std::shared_ptr<SpriteComponent> sprite;
//    };

    //// CAMERA COMPONENT ////

//
    //// ANIMATION COMPONENT ////


