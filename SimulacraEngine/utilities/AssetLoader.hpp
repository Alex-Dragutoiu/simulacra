//
//  AssetLoader.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 15/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>

class AssetLoader {
private:
    static std::unordered_map<std::string, std::shared_ptr<sf::Texture>> textures;
    static std::unordered_map<std::string, std::shared_ptr<sf::Font>> fonts;
    
public:
    static std::shared_ptr<sf::Texture> loadTexture(const std::string& filename);
    static std::shared_ptr<sf::Font> loadFont(const std::string& filename);
    
    // constructors and destructors
    AssetLoader();
    ~AssetLoader();
};
