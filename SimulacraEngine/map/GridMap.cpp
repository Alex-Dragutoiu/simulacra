//
//  GridMap.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 18/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "GridMap.hpp"

namespace simulacra {
    
    GridMap::GridMap(const int& width, const int& height, const float& scale, const sf::Vector2u& tileSize) {
        props.x = width;
        props.y = height;
        props.z = scale;
        
        this->tileSize = tileSize;
        
        init();
    }
    
    GridMap::~GridMap() { }
    
    void GridMap::init() {
        
        gridX.resize(props.x + 1);
        gridY.resize(props.y + 1);
        
        int nextPos = 0;
        
        for (size_t i = 0; i <= props.x; i++) {
            sf::RectangleShape rect;
            
            rect.setSize(sf::Vector2f(2.5f, props.y * tileSize.y * props.z));
            rect.setPosition((i * tileSize.x) + nextPos, 0);
            rect.setFillColor(sf::Color::Black);
            
            nextPos += tileSize.x;
            gridX[i] = rect;
        }
    
        nextPos = 0;
        
        for (size_t i = 0; i <= props.y; i++) {
            sf::RectangleShape rect;
            
            rect.setSize(sf::Vector2f(props.x * tileSize.x * props.z, 2.5f));
            rect.setPosition(0, (i * tileSize.y) + nextPos);
            rect.setFillColor(sf::Color::Black);
            
            nextPos += tileSize.y;
            gridY[i] = rect;
        }
        
    }
    
    void GridMap::draw(sf::RenderTarget& target, bool isActive) {
        if (isActive) {
            // populate the rect array
            for (size_t i = 0; i <= props.x; i++) {
                target.draw(gridX[i]);
            }
            for (size_t i = 0; i <= props.y; i++) {
                target.draw(gridY[i]);
            }
        }
    }
}

