//
//  Animation.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#include "Animation.hpp"

namespace simulacra {
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
}
