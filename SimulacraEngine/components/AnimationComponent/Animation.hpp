//
//  Animation.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

namespace simulacra {
    class Animation {
    public:
        Animation(sf::Texture* animSheet, int noOfFrames, const int& width, const int& height, const double& delay);
        ~Animation();
        
        void setDelay(const double& delay);
        double getDelay();
        
        void setOffset(int offset);
        int getOffset();
        
        const sf::Texture* getTexture() {
            return animSheet;
        };
        
        sf::IntRect getRect() {
            return *current;
        }
        
        sf::IntRect& play(const sf::Time& dt);
        void pause();
        void reset();
        
    private:
        
        /* the time at which we switch to the next sprite */
        double delay;
        
        /* how much time has passed since the last frame of animation */
        double elapsedTime;
        
        /* x dimension of the sprite */
        int width, height;
        
        int noOfFrames;
        
        sf::Texture* animSheet;
        
        std::shared_ptr<sf::IntRect> current;

    };
}
