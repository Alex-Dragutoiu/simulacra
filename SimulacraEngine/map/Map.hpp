//
//  Map.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "../entities/Entity.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace simulacra {

    struct Layer {
        int n;
        
        sf::Texture tileSet;
        sf::VertexArray layerMap;
        
    };
    
    class Map : public sf::Drawable, public sf::Transformable {
    public:
        Map(const unsigned int& width, const unsigned int& height);
        ~Map() = default;
        
        void load(const sf::Texture& tileSet, sf::Vector2u tileSize);
        
        int getTile(const int& x, const int& y) {
            int i = x / tileSize.x;
            int j = y / tileSize.y;
            
            return tileMap[i + j * width];
        };
        
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
            // apply the transform
            states.transform *= getTransform();
            
            // apply the tileset texture
            states.texture = &tileSet;
            
            // draw the vertex array
            target.draw(vertices, states);
        }
        
    private:
        sf::VertexArray vertices;
        
        sf::Texture tileSet;
        sf::Vector2u tileSize;
         
        unsigned int width;
        unsigned int height;
        
        json map;
        
        std::vector<int> tileMap = {
             3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
             3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
             3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
             3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
             3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
             3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
             3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
             3,  3,  3,  3,  3,  3,  3,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,  3,
             2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
             2,  3,  2,  3,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
             2,  3,  2,  3,  2,  3,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
             2,  3,  2,  3,  2,  3,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
             2,  3,  2,  3,  2,  3,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,
             2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
             2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
             2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  
        }; // 40 x 4    
    };
}
