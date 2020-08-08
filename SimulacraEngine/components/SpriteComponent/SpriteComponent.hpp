//
//  SpriteComponent.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 07/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "../Component.hpp"

#include "../../entities/GameObject.hpp"

#include "../TransformationComponent/TransformationComponent.hpp"

namespace simulacra {
    
    class GameObject;
    
    class SpriteComponent : public Component {
    public:
        SpriteComponent(GameObject* owner, sf::Texture* texture);
        ~SpriteComponent();
        
        void draw(sf::RenderTarget& target) override;
        
        void setTexture(const sf::Texture& texture);
        void setTextureRect(int x, int y, int width, int height);
        void setTextureRect(const sf::IntRect& rect);
        
        sf::Sprite& getSprite();
        
        void move(float offsetX, float offsetY);
        
    private:
        sf::Texture* texture;
        sf::Sprite sprite;
        
        std::shared_ptr<TransformationComponent> transformation_c;
    };
}
