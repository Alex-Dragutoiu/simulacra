//
//  TextBox.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

#include "../defines.h"

namespace simulacra {
    class TextBox {
    private:
        sf::Text textBox;
        std::ostringstream textBuffer;
        
        int maxLength;
        bool isSelected;
        
    private:
        void deleteLastChar();
        void handleInput(int charTyped);
        
    public:
        TextBox(int maxLength, sf::Color textColour);
        ~TextBox();
        
        void setFont(const sf::Font& font);
        void setCharacterSize(const int size);
        void setPosition(const sf::Vector2f pos);
        std::string getText();
        
        void draw(const std::shared_ptr<sf::RenderWindow>& target);
        void typed(const sf::Vector2f& mousePos, const sf::Event& event);
    };
}
