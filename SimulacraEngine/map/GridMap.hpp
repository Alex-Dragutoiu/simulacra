//
//  GridMap.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 18/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace simulacra {
    class GridMap {
    public:
        GridMap(const int& width, const int& height, const float& scale, const sf::Vector2u& tileSize);
        ~GridMap();
        
        void init();
        
        void draw(sf::RenderTarget& target, bool isActive);
        
    private:
        sf::Vector3i props;
        sf::Vector2u tileSize;
        
        std::vector<sf::RectangleShape> gridX;
        std::vector<sf::RectangleShape> gridY;
    };
}
