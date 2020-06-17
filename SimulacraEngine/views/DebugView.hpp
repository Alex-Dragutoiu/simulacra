//
//  DebugView.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"
#include "../entities/Player.hpp"

#include "../map/ParallaxBackground.hpp"

class DebugView {
private: /* Variables */
    /* Model */
    std::shared_ptr<sf::View> camera;
    ParallaxBackground parallax;
	Player player;
    
    
public: /* Methods */
    void draw();
    void addModel(const ParallaxBackground& parallax, const Player& player);
    
    DebugView();
    DebugView(const ParallaxBackground &parallax, const Player& player);
    ~DebugView();
    
};

