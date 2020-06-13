//
//  Animation.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#include "Animation.hpp"

#define SPRITE_DIMENSION 64

Animation::Animation(const double switchTime) {
    /* each sprite in the sprite sheet is 64 x 64, but might change according to the spritesheet */
    offset = SPRITE_DIMENSION;
    
    /* we start at time 0 */
    currentTime = 0;
    
    /* this is the position on the texture, which in our case is a sprite sheet */
    rect = std::make_shared<sf::IntRect>(0, 576, offset, offset);
    
    this->switchTime = switchTime;
}

Animation::~Animation() { }

sf::IntRect& Animation::update(const double dt, int state) {
    switch (state) {
        case 0: // IDLE
            rect->left = 0;
            break;
        case 1: // LEFT
            rect->top = 576;
            setFrame(dt);
            break;
        case 2: // RIGHT
            rect->top = 704;
            setFrame(dt);
            break;
        default:
            std::cout << "[WARNING]: Unknown state!";
            break;
    }
    
    return *rect;
}

void Animation::setFrame(const double dt) {
    currentTime += dt;
    if (currentTime >= switchTime) {
        if (rect->left == 512) {
            rect->left = SPRITE_DIMENSION;
        } else {
            rect->left += SPRITE_DIMENSION;
        }
        currentTime = 0;
    }
}

void Animation::setSwitchTime(const double switchTime) {
    this->switchTime = switchTime;
}

void Animation::setOffset(const int offset) {
    this->offset = offset;
}
