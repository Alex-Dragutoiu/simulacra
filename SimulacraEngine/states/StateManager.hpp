//
//  StateManager.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 15/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "State.hpp"

typedef std::unique_ptr<State> state;

class StateManager {
private:
    std::vector<state> states;
    
public:
    void addState(state newState);
    void removeState();
    State& getCurrentState();
    
    StateManager();
    ~StateManager();
};
