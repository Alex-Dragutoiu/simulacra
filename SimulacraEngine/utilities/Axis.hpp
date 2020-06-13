//
//  Axis.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Axis {
private:
    sf::RectangleShape X;
    sf::RectangleShape Y;
    sf::Font font;
    sf::Text coord;
    
public:
    // Constructors & Destructors
    Axis(int x, int y);
    ~Axis();
    
    // Functions
    void move(const float dt, const float xDir, const float yDir);
    void update(const float dt);
    void draw(sf::RenderTarget* target);
};

