//
//  Axis.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#include "Axis.hpp"

Axis::Axis(int x, int y) {
    std::string text = "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    
    font.loadFromFile("fonts/TextPixelFont.ttf");
    coord.setFont(font);
    coord.setString(text);
    coord.setPosition(x, y);
    coord.setCharacterSize(32);
    coord.setFillColor(sf::Color::White);
    
    // Set X Axis
    X.setSize(sf::Vector2f(1600, 2));
    X.setPosition(x, y);
    X.setFillColor(sf::Color::Red);
    
    // Set Y Axis
    Y.setSize(sf::Vector2f(2, -1600));
    Y.setPosition(x, y);
    Y.setFillColor(sf::Color::Blue);
}

void Axis::move(const float dt, const float xDir, const float yDir) {
    X.move(dt * xDir, dt * yDir);
    Y.move(dt * xDir, dt * yDir);
    
    std::string text = "(" + std::to_string(X.getPosition().x) + ", " + std::to_string(X.getPosition().x) + ")";
    coord.setString(text);
}

void Axis::update(const float dt) {
    
}

void Axis::draw(sf::RenderTarget *target) {
    target->draw(coord);
    target->draw(X);
    target->draw(Y);
    
}

Axis::~Axis() {
    
}
