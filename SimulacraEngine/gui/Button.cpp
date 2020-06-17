//
//  Button.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#include "Button.hpp"

namespace simulacra {
    Button::Button() {

    }

    Button::Button(float x, float y, int size, std::string text, sf::Color idleColour, sf::Color hoverColour, sf::Color pressedColour) {
        state = BTN_IDLE;
        
        this->text.setString(text);
        this->text.setCharacterSize(size);
        this->text.setPosition(x + this->text.getGlobalBounds().width / 2, y);
        
        this->idleColour = idleColour;
        this->hoverColour = hoverColour;
        this->pressedColour = pressedColour;
        
        this->text.setFillColor(idleColour);
    }

    Button::~Button() {
        
    }

    void Button::update(const sf::Vector2f mousePos) {
        state = BTN_IDLE;
        
        if (text.getGlobalBounds().contains(mousePos)) {
            state = BTN_HOVER;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                state = BTN_PRESSED;
            }
        }
        
        switch (state) {
            case BTN_IDLE:
                text.setFillColor(this->idleColour);
                break;
            case BTN_HOVER:
                text.setFillColor(this->hoverColour);
                break;
            case BTN_PRESSED:
                text.setFillColor(this->pressedColour);
                break;
            default:
                text.setFillColor(sf::Color::Red);
                break;
        }
    }

    void Button::setFont(const sf::Font& font) {
        this->text.setFont(font);
    }

    const bool Button::isPressed() const {
        if (state == BTN_PRESSED) {
            return true;
        }
        return false;
    }

    void Button::draw(const std::shared_ptr<sf::RenderWindow>& target) {
        target->draw(text);
    }
}
