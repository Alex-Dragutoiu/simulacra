//
//  Map.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "Map.hpp"

namespace simulacra {
    
    Map::Map(const unsigned int& width, const unsigned int& height) {
        this->width = width;
        this->height = height;
    };

    void Map::load(const sf::Texture& tileSet, sf::Vector2u tileSize) {
        this->tileSize = tileSize;
        this->tileSet = tileSet;
        
        // resize the vertex array to fit the level size
        vertices.setPrimitiveType(sf::Quads);
        vertices.resize(width * height * 4);
                
        // populate the vertex array, with one quad per tile
        for (size_t i = 0; i < width; ++i) {
            for (size_t j = 0; j < height; ++j) {
                
                // get the current tile number
                int tileNumber = tileMap[i + j * width];
                
                // find its position in the tileset texture
                int tu = tileNumber % (tileSet.getSize().x / tileSize.x);
                int tv = tileNumber / (tileSet.getSize().x / tileSize.x);
                
                // get a pointer to the current tile's quad
                sf::Vertex* tile = &vertices[(i + j * width) * 4];
                
                // define its 4 corners
                tile[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                tile[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                tile[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                tile[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
                
                // define its 4 texture coordinates
                tile[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                tile[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                tile[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                tile[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }
        }
    }
}
