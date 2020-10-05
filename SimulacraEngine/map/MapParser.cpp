//
//  MapParser.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 02/09/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "MapParser.hpp"

namespace simulacra {
    
    MapParser::MapParser(TextureLoader& textureLoader) : textureLoader(textureLoader) {
        
    }
    
    MapParser::~MapParser() {
    
    };
    
    void MapParser::loadFromJSON(const std::string& filepath) {
        std::ifstream file;
        file.open("Resources/" + filepath);
        
        if (!file) {
            throw "file not found!\n";
        }
        
        json json;
        file >> json;
        
        auto const map = json.find("map");
        if (map == json.end()) { throw "map key not found!"; }
        
        for (auto& layer : *map) {
            std::shared_ptr<Layer> lay = parseLayerFromJSON(layer);
            lay->setScale(2.f, 2.f);
            layers.emplace_back(lay);
        }
        
        file.close();
    };
    
    void MapParser::draw(sf::RenderTarget& target) const {
        for (auto& layer : layers) {
            target.draw(*layer);
        }
    }
    
    std::shared_ptr<SpriteSheetData> MapParser::parseSpriteSheetDataFromJSON(const json& json) {
        SpriteSheetData spriteSheetData;
        
        auto const identifier = json.find("identifier");
        if (identifier == json.end()) { throw "file path key not found!"; }
        
        auto const tileWidth = json.find("width");
        if (tileWidth == json.end()) { throw "map width key not found!"; }
        
        auto const tileHeight = json.find("height");
        if (tileHeight == json.end()) { throw "map height key not found!"; }
        
        spriteSheetData.spriteSheet = textureLoader.get(identifier.value());
        spriteSheetData.tileSize.x = tileWidth.value();
        spriteSheetData.tileSize.y = tileHeight.value();
        
        return std::make_shared<SpriteSheetData>(spriteSheetData);
    };
    
    std::shared_ptr<Layer> MapParser::parseLayerFromJSON(const json& json) {
        auto const layerWidth = json.find("width");
        auto const layerHeight = json.find("height");
        
        auto const spriteSheet = json.find("spriteSheet");
        if (spriteSheet == json.end()) { throw "tileSheet key not found!"; }
        
        std::shared_ptr<SpriteSheetData> spriteSheetData = parseSpriteSheetDataFromJSON(*spriteSheet);
        
        auto const data = json.find("data");
        if (data == json.end()) { throw "data key not found!"; }
        
        std::vector<int> tileMap;
        for (auto& tileID : *data) {
            tileMap.emplace_back(tileID);
        }
        
        return std::make_shared<Layer>(tileMap, spriteSheetData, sf::Vector2u(static_cast<int>(layerWidth.value()), static_cast<int>(layerHeight.value())));
    };
    
}
