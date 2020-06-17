//
//  StatesController.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 16/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <iostream>
#include <memory>

#include "../states/StateManager.hpp"

class StatesController {
private:
    /* Model */
    StateManager model;

public:
    void addModel(const StateManager& model);

    StatesController();
    StatesController(const StateManager& model);
    
    ~StatesController();
};
