//
//  Player.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#include "Player.hpp"

// Constructors & Destructor
Player::Player(int x, int y) : animation(.10f) /*, lines(sf::LinesStrip, 5) */ {
    movement = IDLE;
    texture = std::make_shared<sf::Texture>();
    texture->loadFromFile("Resources/entities/player/character_sheet.png");
    
    sprite.setTexture(*texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    sprite.setPosition(x, y);
    //    sprite.setScale(10.f, 10.f);
    
    //        lines[0].position = sprite.getPosition();
    //        lines[1].position = sf::Vector2f(sprite.getGlobalBounds().width, 0);
    //        lines[2].position = sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
    //        lines[3].position = sf::Vector2f(0, sprite.getGlobalBounds().height);
    //        lines[4].position = sprite.getPosition();
    
    
    //    sprite.setOrigin((2 * sprite.getPosition().x + sprite.getGlobalBounds().width) / 2,
    //                     (2 * sprite.getPosition().y + sprite.getGlobalBounds().height) / 2);
    
    speed = 295.f;
}

Player::~Player() { }

sf::Vector2f Player::getPosition() {
    return sprite.getPosition();
}

sf::Vector2f Player::getOrigin() {
    return sprite.getOrigin();
}

void Player::move(const float dt, const float xDir, const float yDir) {
    sprite.move(dt * xDir * speed, dt * yDir * speed);
}

void Player::update(const float dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        move(dt, -1.f, 0.f);
        sprite.setTextureRect(animation.update(dt, LEFT));
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        move(dt, 1.f, 0.f);
        sprite.setTextureRect(animation.update(dt, RIGHT));
    } else {
        sprite.setTextureRect(animation.update(dt, IDLE));
    }
    
}

void Player::draw(sf::RenderTarget* target) {
    target->draw(sprite);
    // target->draw(lines);
}
