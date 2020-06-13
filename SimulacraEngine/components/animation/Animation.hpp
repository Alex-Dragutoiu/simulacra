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

class Animation {
private:
    /* current sprite position on the texture */
    std::shared_ptr<sf::IntRect> rect;
    
    /* dimension of the sprite */
    int offset;
    
    /* the time at which we switch to the next sprite */
    double switchTime;
    
    /* how much time has passed since the last frame of animation */
    double currentTime;
    
private:
    /* sets rect to the next frame of the animation */
    void setFrame(const double dt);
    
public:
    /* Setters */
    void setSwitchTime(const double switchTime);
    void setOffset(const int offset);
    
    /** \param dt       Which represents the delta time and we add i
     *  \param state    The Movement state which can be IDLE, LEFT or RIGHT
     *
     *  \return         The new position of the sprite on the texture
     */
    sf::IntRect& update(const double dt, int state);
    
    Animation(const double switchTime);
    ~Animation();
};

