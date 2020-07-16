//
//  GameState.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include "imgui.h"
#include "imgui-SFML.h"

#include "State.hpp"

namespace simulacra {
    
    class GameState : public State {
    private:
        sf::View view;
        sf::Texture background;
        
    public:
        void init() override;
        
        // The three important actions within a game loop
        void handleEvents(const sf::Event& event) override;
        void draw(std::shared_ptr<sf::RenderWindow>& target) override;
        void update(const sf::Time& dt) override;
        
        // Constructors & Destructors
        GameState(StateManager& stateManager, Context context);
        ~GameState();
    };
}
