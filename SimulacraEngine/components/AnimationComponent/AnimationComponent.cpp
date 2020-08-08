//
//  AnimationComponent.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 07/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "AnimationComponent.hpp"

namespace simulacra {
    AnimationComponent::AnimationComponent(GameObject* owner, const double& delay) : Component(owner) {
        this->delay = delay;
        elapsedTime = 0;
        isPlayingAnim = false;
        
        sprite_c = owner->getComponent<SpriteComponent>();
    }
    
    AnimationComponent::~AnimationComponent() { }
    
    void AnimationComponent::addAnimation(Action action, sf::Texture* animation, const int& width, const int& height) {
        int noOfFrames = animation->getSize().x / width;
        std::unique_ptr<Animation> anim = std::make_unique<Animation>(animation, noOfFrames, width, height, delay);
        animations.insert(std::make_pair(action, std::move(anim)));
    }
    
    Animation& AnimationComponent::getAnimation(Action action) {
        auto found = animations.find(action);
        assert(found != animations.end());
        
        return *found->second;
    }
    
    void AnimationComponent::play(Action& action, const sf::Time& dt) {
        isPlayingAnim = true;
        
        auto& animation = getAnimation(action);
        sprite_c->setTexture(*animation.getTexture());
        
        elapsedTime += dt.asSeconds();
        if (elapsedTime >= delay) {
            sprite_c->setTextureRect(animations[action]->play(dt));
            elapsedTime = 0;
        }
        
        if (animation.getRect().left == animation.getTexture()->getSize().x - 200) {
                isPlayingAnim = false;
        }
    }
    
    void AnimationComponent::pause(Action action) {
        animations[action]->pause();
    }
    
    void AnimationComponent::reset(Action action) {
        animations[action]->reset();
    }
}
