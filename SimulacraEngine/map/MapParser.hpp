//
//  MapParser.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 02/09/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include <fstream>
#include <nlohmann/json.hpp>

#include <SFML/Graphics.hpp>

#include "../ResourceIdentifiers.h"

using json = nlohmann::json;

namespace simulacra {

    struct TileInfo {
        int tileID;
        int tu, tv;
    };
    
    struct SpriteSheetData {
        sf::Vector2u tileSize;
        sf::Texture spriteSheet;
    };

    struct Tile{
        Tile() { };
        ~Tile() { };

        std::shared_ptr<TileInfo> info;
    };
    
    class Layer : public sf::Drawable, public sf::Transformable {
    public:
        Layer(std::vector<int> tileMap, const std::shared_ptr<SpriteSheetData>& spriteSheetData, sf::Vector2u size) : spriteSheetData(spriteSheetData), size(size) {
            
            // resize the vertex array to fit the level size
            layer_m.setPrimitiveType(sf::Quads);
            layer_m.resize(size.x * size.y * 4);
            
            sf::Vector2u tileSize = spriteSheetData->tileSize;
            
            // populate the vertex array, with one quad per tile
            for (size_t i = 0; i < size.x; ++i) {
                for (size_t j = 0; j < size.y; ++j) {
                    int tileNumber = tileMap[i + j * size.x];
                    
                    // find its position in the tileset texture
                    int tu = tileNumber % (spriteSheetData->spriteSheet.getSize().x / tileSize.x);
                    int tv = tileNumber / (spriteSheetData->spriteSheet.getSize().x / tileSize.x);
                    
                    // get a pointer to the current tile's quad
                    sf::Vertex* tile = &layer_m[(i + j * size.x) * 4];
                    
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
        };
        
        ~Layer() { };
        
        int getID() { return id; }
    
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
            // apply the transform
            states.transform *= getTransform();
            
            // apply the tileset texture
            states.texture = &spriteSheetData->spriteSheet;
            
            // draw the vertex array
            target.draw(layer_m, states);
        }
        
    private:
        int id;
        std::shared_ptr<SpriteSheetData> spriteSheetData;
    
        sf::VertexArray layer_m;
        sf::Vector2u size;
    };

    class MapParser {
    public:
        void loadFromJSON(const std::string& filepath);
        void draw(sf::RenderTarget& target) const;
        
        MapParser(TextureLoader& textureLoader);
        ~MapParser();
        
    private:
    
        /* builds the sprite sheet data from a json */
        std::shared_ptr<SpriteSheetData> parseSpriteSheetDataFromJSON(const json& json);
        
        /* build a layer of tiles from a json */
        std::shared_ptr<Layer> parseLayerFromJSON(const json& json);
        
    private:
        std::vector<std::shared_ptr<Layer>> layers;
        
        TextureLoader& textureLoader;
        
    };
}
