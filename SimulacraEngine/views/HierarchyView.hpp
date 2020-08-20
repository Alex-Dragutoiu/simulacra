//
//  HierarchyView.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

#include "../entities/GameObject.hpp"
#include "../components/TransformationComponent/TransformationComponent.hpp"

#include "imgui.h"
#include "imgui-SFML.h"

namespace simulacra {
    class HierarchyView {
    // Variables
    private:
        GameObject* player;
        int selected;
        
        // Methods
    private:
        void drawHierarchy();
        void drawListOfObjectsToAdd();
        
    public:
        void draw(bool isOpen);
        
        void addModel(GameObject* player) {
            this->player = player;
        };
        
        HierarchyView();
        ~HierarchyView();
    };
}
//    const char* names[9] = {
//        "A", "B", "C",
//        "D", "E", "F",
//        "G", "H", "I"
//    };
//    int mode = 0;
//    int selected[4 * 4] = { 1, 0, 0, 0,
//                            0, 1, 0, 0,
//                            0, 0, 1, 0,
//                            0, 0, 0, 1 };
