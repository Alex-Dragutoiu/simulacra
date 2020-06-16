//
//  State.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

/* state interface */
class State {
public:
    virtual void init() = 0;
    
    /* The three important actions within a game loop */
    virtual void handleEvents(sf::Event& event) = 0;
    virtual void draw(std::shared_ptr<sf::RenderWindow>& target) = 0;
    virtual void update(const sf::Time& dt) = 0;
    
    virtual ~State() {
        
    };
    
    virtual std::string toString() {
        return "State";
    };
};

