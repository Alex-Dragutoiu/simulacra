//
//  Animation.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 06/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "Animation.hpp"

namespace ECS {
    
    Animation::Animation(sf::Texture* animSheet, int frames, const int& width, const int& height, const double& delay) {
        this->animSheet = animSheet;
        this->frames = frames;
        this->width = width;
        this->height = height;
        this->delay = delay;
        
        current = std::make_shared<sf::IntRect>(0, 0, width, height);
        elapsedTime = 0;
    }
    
    Animation::~Animation() { }
    
    sf::IntRect& Animation::play(const float& dt) {
        elapsedTime += dt;
        if (elapsedTime >= delay) {
            if (current->left != width * (frames - 1)) {
                current->left += width;
            } else {
                reset();
            }
            elapsedTime = 0;
        }
        
        return *current;
    }
    
    void Animation::pause() { }
    
    void Animation::reset() {
        current->left = 0;
    }
}
