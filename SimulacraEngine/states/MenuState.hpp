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

#include "../gui/Button.hpp"
#include "../gui/TextBox.hpp"

#include "../engine/GameEngine.hpp"

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
    
    Button start;
    Button options;
    Button credits;
    Button quit;
    
    // Functions
private:
    void initText(sf::Text& text, std::string string, sf::Font* font, float charSize, float x, float y, sf::Color colour);
    
public:
    void init() override;
    
    // The three important actions within a game loop
    void handleEvents(sf::Event& event) override;
    void draw(std::shared_ptr<sf::RenderWindow>& target) override;
    void update(const sf::Time& dt) override;
    MenuState(GameEngine* context);
    ~MenuState();
};


