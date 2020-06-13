//
//  Button.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include "Button.hpp"
#include <SFML/Graphics.hpp>

enum buttonStates {
    BTN_IDLE = 0,
    BTN_HOVER,
    BTN_PRESSED
};

class Button {
private:
    short unsigned buttonState;
    
    sf::Text text;
    
    bool hover;
    bool pressed;
    
    sf::Color idleColour;
    sf::Color hoverColour;
    sf::Color pressedColour;
    
public:
    Button();
    Button(float x, float y, int size, std::string text, sf::Color idleColour, sf::Color hoverColour, sf::Color pressedColour);
    ~Button();
    
    // functions
    void update(const sf::Vector2f mousePos);
    void draw(const std::shared_ptr<sf::RenderWindow>& target);
    
    // Getters & Setters
    sf::Color getIdleColour() {
        return idleColour;
    };
    
    void setIdleColour(const sf::Color& idleColour) {
        this->idleColour = idleColour;
    };
    
    sf::Color getHoverColour() {
        return hoverColour;
    };
    
    void setHoverColour(const sf::Color& hoverColour) {
        this->hoverColour = hoverColour;
    };
    
    sf::Color getPressedColour() {
        return pressedColour;
    };
    
    void setPressedColour(const sf::Color& pressedColour) {
        this->pressedColour = pressedColour;
    };
    
    void setPosition(const sf::Vector2f& position) {
        text.setPosition(position);
    };
    
    void setPosition(float x, float y) {
        text.setPosition(x, y);
    };
    
    void setString(const std::string& text) {
        this->text.setString(text);
    };
    
    void setCharacterSize(unsigned int size) {
        text.setCharacterSize(size);
    };
    
    const bool isPressed() const;
    
    void setFont(const sf::Font& font);
};

