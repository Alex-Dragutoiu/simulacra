//
//  MenuState.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <iostream>
#include <memory>

#include "State.hpp"
#include "GameState.hpp"

#include "../gui/Button.hpp"
#include "../gui/TextBox.hpp"

#include "../engine/GameEngine.hpp"
#include "../utilities/AssetLoader.hpp"

#include "../defines.h"

class GameEngine;

class MenuState : public State {
    // Variables
private:
    GameEngine* context;
    
    std::shared_ptr<sf::Font> font;
    sf::Text gameTitle;
    sf::Text studioTitle;
    
    // TextBox* textBox;
    
    std::shared_ptr<sf::Texture> texture;
    sf::Sprite backgroundImage;
    
    std::unordered_map<std::string, simulacra::Button> buttons;
    
//    simulacra::Button start;
//    simulacra::Button options;
//    simulacra::Button credits;
//    simulacra::Button quit;
private:
    void initButtons();
    
public:
    void init() override;
    
    // The three important actions within a game loop
    void handleEvents(sf::Event& event) override;
    void draw(std::shared_ptr<sf::RenderWindow>& target) override;
    void update(const sf::Time& dt) override;
    
    std::string toString() override;
    
    MenuState(GameEngine* context);
    ~MenuState();
};


