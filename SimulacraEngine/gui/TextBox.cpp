//
//  TextBox.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#include "TextBox.hpp"

namespace simulacra {
    TextBox::TextBox(int maxLength, sf::Color textColour) {
        this->maxLength = maxLength - 1;
        isSelected = true;
        textBox.setFillColor(textColour);
        textBox.setString("");
    }

    TextBox::~TextBox() {
        
    }

    void TextBox::draw(const std::shared_ptr<sf::RenderWindow>& target) {
        target->draw(textBox);
    }

    //void TextBox::draw(sf::RenderTarget* target) {
    //    target->draw(textBox);
    //}


    void TextBox::typed(const sf::Vector2f& mousePos, const sf::Event& event) {
        if (isSelected) { /* if the textbox was clicked by the user */
            int charTyped = event.text.unicode;
            if (charTyped < 128) {
                if (textBuffer.str().length() <= maxLength) {
                    if (charTyped == ENTER) {
                        isSelected = false;
                        textBox.setString(textBuffer.str());
                    } else if (charTyped == BACKSPACE) {
                        deleteLastChar();
                    } else {
                        handleInput(charTyped);
                    }
                } else {
                    /* if we reached the capicity of the textbox,
                     * we should be a able to delete characters
                     */
                    if (charTyped == BACKSPACE) {
                        deleteLastChar();
                    }
                }
            }
        }
    }

    void TextBox::setFont(const sf::Font& font) {
        textBox.setFont(font);
    }

    void TextBox::setPosition(const sf::Vector2f pos) {
        textBox.setPosition(pos);
    }

    std::string TextBox::getText() {
        return textBuffer.str();
    }

    void TextBox::deleteLastChar() {
        if (textBuffer.str().length() > 0) {
            std::string text = textBuffer.str();
            std::string newText = "";
            
            for (int i = 0; i < text.length() - 1; i++) {
                newText += text[i];
            }
            
            textBuffer.str("");
            textBuffer << newText;
            textBox.setString(textBuffer.str() + "_");
        }
    }

    void TextBox::handleInput(int charTyped) {
        textBuffer << static_cast<char>(charTyped);
        textBox.setString(textBuffer.str() + "_");
    }

    void TextBox::setCharacterSize(const int size) {
        textBox.setCharacterSize(size);
    }
}
