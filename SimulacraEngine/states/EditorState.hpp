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

#include "../utilities/Axis.hpp"

#include "../engine/GameEngine.hpp"

#include "../views/FileSystemView.hpp"
#include "../views/HierarchyView.hpp"
#include "../views/DebugView.hpp"

#include "../entities/Player.hpp"
#include "../map/ParallaxBackground.hpp"

class GameEngine;

class EditorState : public State {
/* Variables */
private:
    /* Views */
    FileSystemView fileView;
//    HierarchyView hierView;
    DebugView debugView;
    
    /* context of the state */
    GameEngine* context;
    
    Player player;
    std::shared_ptr<sf::View> camera;
    
    float limit = 0;
    
    std::unique_ptr<ParallaxBackground> parallax;
    
/* Methods */
private:
    
public:
    void init() override;
    
    // The three important actions within a game loop
    void handleEvents(sf::Event& event) override;
    void draw(std::shared_ptr<sf::RenderWindow>& target) override;
    void update(const sf::Time& dt) override;
    
    std::string toString() override;
    
    EditorState(GameEngine* context);
    ~EditorState();
};

