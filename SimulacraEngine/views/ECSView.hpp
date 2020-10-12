//
//  ECSView.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 08/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
//
#pragma once

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>
#include "../ECS/ECS.h"

#include "imgui.h"
#include "imgui-SFML.h"

namespace simulacra {
    class ECSView {
    public:
        ECSView(ECS::ECSManager& manager);

        void draw(bool isOpen);
        
    private:
        int selected;
    
        void drawLeftPanel();
        void drawRightPanel();
        
        ECS::ECSManager& manager;
    };
}
