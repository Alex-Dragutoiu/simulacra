//
//  Utils.h
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 31/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>

template <typename C>
sf::VertexArray rectangle(C x, C y, C width, C height, sf::Color colour) {
    
    /* draw a rectangle */
    sf::VertexArray rect(sf::LineStrip, 5);
    
    rect[0].position = sf::Vector2f(x, y);
    rect[1].position = sf::Vector2f(x + width, y);
    rect[2].position = sf::Vector2f(x + width, y + height);
    rect[3].position = sf::Vector2f(x, y + height);
    rect[4].position = sf::Vector2f(x, y);

    rect[0].color = colour;
    rect[1].color = colour;
    rect[2].color = colour;
    rect[3].color = colour;
    rect[4].color = colour;

    return rect;
}

//std::string getWorkingDir() {
//    return "Resources/";
//}
