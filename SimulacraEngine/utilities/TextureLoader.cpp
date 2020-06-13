//
//  TextureLoader.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#include "TextureLoader.hpp"

TextureLoader::TextureLoader() { }

TextureLoader::~TextureLoader() { }

std::shared_ptr<sf::Texture> TextureLoader::load(const std::string& filename) {
    
    /* First lookup if the texture with that filename
     * is already loaded, if yes, return it instead
     * so that it can be shared.
     */
    if (textures.find(filename) != textures.end()) {
        return textures.find(filename)->second;
    }
    
    /* Texture with that filename is not loaded yet.
     * Load it and save it into the map cache.
     */
    std::shared_ptr<sf::Texture> newTexture = std::make_shared<sf::Texture>();
    newTexture->loadFromFile(filename);
    
    /* Add to the cache map so that next time if someone
     * tries to load() it again, we don't duplicate any data.
     */
    textures.insert(std::make_pair(filename, newTexture));
    
    return newTexture;
}

std::unordered_map<std::string, std::shared_ptr<sf::Texture>> TextureLoader::textures;
