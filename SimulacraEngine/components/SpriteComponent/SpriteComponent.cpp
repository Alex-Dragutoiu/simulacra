//
//  SpriteComponent.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 07/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "SpriteComponent.hpp"

namespace simulacra {
    
    SpriteComponent::SpriteComponent(GameObject* owner, sf::Texture* texture) : Component(owner) {
        transformation_c = owner->getComponent<TransformationComponent>();
        
        this->texture = texture;
        
        sprite.setTexture(*texture);
        sprite.scale(4.f, 4.f);
        sprite.setPosition(transformation_c->getPosition());
    }
    
    SpriteComponent::~SpriteComponent() { }
    
    void SpriteComponent::draw(sf::RenderTarget &target) {
        target.draw(sprite);
    }
    
    void SpriteComponent::setTexture(const sf::Texture& texture) {
        sprite.setTexture(texture);
    }
    
    void SpriteComponent::setTextureRect(int x, int y, int width, int height) {
        sprite.setTextureRect(sf::IntRect(x, y, width, height));
    }
    
    void SpriteComponent::setTextureRect(const sf::IntRect& rect) {
        sprite.setTextureRect(rect);
    }
    
    void SpriteComponent::move(float offsetX, float offsetY) {
        sprite.move(offsetX, offsetY);
    }
}
