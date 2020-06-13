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
#include <vector>
#include <map>
#include <dirent.h>
#include <stack>

#include <SFML/Graphics.hpp>

#include "imgui.h"
#include "imgui-SFML.h"

class HierarchyView {
    // Variables
private:
    const char* names[9] = {
        "A", "B", "C",
        "D", "E", "F",
        "G", "H", "I"
    };
    int mode = 0;
    int selected[4 * 4] = { 1, 0, 0, 0,
                            0, 1, 0, 0,
                            0, 0, 1, 0,
                            0, 0, 0, 1 };
    
    // Methods
private:
    void drawHierarchy();
    void drawListOfObjectsToAdd();
    
public:
    void draw();
    
    HierarchyView();
    ~HierarchyView();
};

