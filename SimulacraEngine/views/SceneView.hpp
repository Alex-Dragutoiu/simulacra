//
//  SceneView.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>
#include "../states/StateManager.hpp"

#include "imgui.h"
#include "imgui-SFML.h"

namespace simulacra {
    class SceneView {
    public:
        SceneView(StateManager& manager);
        
        void draw(bool isOpen);
        
    private:
        
        StateManager& manager;
    };
}
