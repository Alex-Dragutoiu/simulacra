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

#include <nlohmann/json.hpp>

using json = nlohmann::json;

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
    
    // map Textures values to JSON as strings
    NLOHMANN_JSON_SERIALIZE_ENUM(Textures, {
        {Textures::DEFAULT_ENTITY, "default_entity"},
        
        {Textures::PLAYER_IDLE_LEFT, "player_idle_left"},
        {Textures::PLAYER_IDLE_RIGHT, "player_idle_right"},
        {Textures::PLAYER_LEFT, "player_left"},
        {Textures::PLAYER_RIGHT, "player_right"},
        {Textures::PLAYER_ATTACK_RIGHT, "player_attack_right"},
        {Textures::PLAYER_ATTACK_LEFT, "player_attack_left"},
        
        {Textures::MAP, "map"},
        {Textures::MENU_BACKGROUND, "menu_background"},
    });
    
    enum class Fonts {
        MENU_FONT
    };
    
    // map Fonts values to JSON as strings
    NLOHMANN_JSON_SERIALIZE_ENUM(Fonts, {
        {Fonts::MENU_FONT, "menu_font"},
    });
    
    
    template <typename Resource, typename Identifier>
    class AssetLoader;
    
    typedef AssetLoader<sf::Texture, Textures> TextureLoader;
    typedef AssetLoader<sf::Font, Fonts> FontLoader;

}

