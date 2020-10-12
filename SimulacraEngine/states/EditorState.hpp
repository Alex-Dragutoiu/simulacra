//
//  EditorState.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <iostream>
#include <memory>

#include "State.hpp"

namespace simulacra {
    
    class EditorState : public State {
    public:
        void init() override;
        
        // The three important actions within a game loop
        void handleEvents(const sf::Event& event) override;
        void draw(std::shared_ptr<sf::RenderWindow>& target) override;
        void update(const float& dt) override;
        
        // Constructors & Destructors
        EditorState(StateManager& stateManager, Context context);
        ~EditorState();
        
    private:
//        std::shared_ptr<QuadTree<Point>> tree;

    };
}
