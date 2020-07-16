//
//  ResourceIdentifiers.h
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 05/07/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include "utilities/AssetLoader.hpp"
#include <SFML/Graphics.hpp>

namespace simulacra {
    
    enum class Textures {
        PLAYER,
        MENU_BACKGROUND,
    };
    
    enum class Fonts {
        MENU_FONT
    };
    
    template <typename Resource, typename Identifier>
    class AssetLoader;
    
    typedef AssetLoader<sf::Texture, Textures> TextureLoader;
    typedef AssetLoader<sf::Font, Fonts> FontLoader;

}

