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
        DEFAULT_ENTITY,
        
        PLAYER_IDLE_LEFT,
        PLAYER_IDLE_RIGHT,
        PLAYER_LEFT,
        PLAYER_RIGHT,
        PLAYER_ATTACK_RIGHT,
        PLAYER_ATTACK_LEFT,
        
        MAP,
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

