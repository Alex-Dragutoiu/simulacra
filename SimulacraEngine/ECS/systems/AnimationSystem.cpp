//
//  AnimationSystem.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 05/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "AnimationSystem.hpp"

namespace ECS {
    
    Animation::Animation(sf::Texture* animSheet, int noOfFrames, const int& width, const int& height, const double& delay) {
        this->animSheet = animSheet;
        this->noOfFrames = noOfFrames;
        this->width = width;
        this->height = height;
        this->delay = delay;
        
        current = std::make_shared<sf::IntRect>(0, 0, width, height);
        
        elapsedTime = 0;
    }
    
    Animation::~Animation() { }
    
    sf::IntRect& Animation::play(const sf::Time& dt) {
        if (current->left != width * (noOfFrames - 1)) {
            current->left += width;
        } else {
            reset();
        }
        return *current;
    }
    
    void Animation::pause() {
        
    }
    
    void Animation::reset() {
        current->left = 0;
    }
    
    AnimationSystem::AnimationSystem(const EntityList& list) : UpdateSystem(list) {
        
    }
    
    void AnimationSystem::addAnimation(Action action, sf::Texture* animation, const int& width, const int& height) {
        int noOfFrames = animation->getSize().x / width;
        std::unique_ptr<Animation> anim = std::make_unique<Animation>(animation, noOfFrames, width, height, delay);
        animations.insert(std::make_pair(action, std::move(anim)));
    }
    
    Animation& AnimationSystem::getAnimation(Action action) {
        auto found = animations.find(action);
        assert(found != animations.end());
        
        return *found->second;
    }
    
    void AnimationSystem::play(Action& action, const sf::Time& dt) {
        isPlayingAnim = true;
        
        auto& animation = getAnimation(action);
        
        elapsedTime += dt.asSeconds();
        if (elapsedTime >= delay) {
            elapsedTime = 0;
        }
        
        if (animation.getRect().left == animation.getTexture()->getSize().x - 200) {
            isPlayingAnim = false;
        }
    }
    
    void AnimationSystem::pause(Action action) {
        animations[action]->pause();
    }
    
    void AnimationSystem::reset(Action action) {
        animations[action]->reset();
    }
    
}
