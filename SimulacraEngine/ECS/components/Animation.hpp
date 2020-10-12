//
//  Animation.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 06/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

namespace ECS {
    
    class Animation {
    public:
        Animation(sf::Texture* animSheet, int frames, const int& width, const int& height, const double& delay);
        ~Animation();
        
        void setDelay(const double& delay);
        double getDelay();
        
        void setOffset(int offset);
        int getOffset();
        
        sf::Texture* getAnimSheet() {
            return animSheet;
        }
        
        sf::IntRect& play(const float& dt);
        void pause();
        void reset();
        
    private:
        /* the time at which we switch to the next sprite */
        double delay;
        
        /* how much time has passed since the last frame of animation */
        double elapsedTime;
        
        /* x dimension of the sprite */
        int width, height;
        
        /* number of frames an animation sheet has */
        int frames;
        
        sf::Texture* animSheet;
        
        /* current sprite rect on the texture */
        std::shared_ptr<sf::IntRect> current;
    };
}
