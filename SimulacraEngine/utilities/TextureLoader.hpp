//
//  TextureLoader.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>

class TextureLoader {
private:
    static std::unordered_map<std::string, std::shared_ptr<sf::Texture>> textures;
    
public:
    static std::shared_ptr<sf::Texture> load(const std::string& filename);
    
    // constructor and destructors
    TextureLoader();
    ~TextureLoader();
};
