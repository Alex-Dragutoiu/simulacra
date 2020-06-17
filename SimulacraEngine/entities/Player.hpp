//
//  Player.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../components/animation/Animation.hpp"
#include "../enums.h"

class Player {
private:
    std::shared_ptr<sf::Texture> texture;
	std::shared_ptr<sf::View> camera;
    sf::Sprite sprite;
    sf::VertexArray lines;
    
    Animation animation;
    simulacra::MovementState movement;
    
    float speed;
    
public:
    
    // gets position of the player on the map
    sf::Vector2f getPosition();
    sf::Vector2f getOrigin();
    
    // Constructors & Destructor
    Player(int x, int y);
    ~Player();
    
    void move(const float dt, const float xDir, const float yDir);
    void update(const float dt);
    void draw(sf::RenderTarget* target);
	void addCamera(std::shared_ptr<sf::View> cameraRef);
};
