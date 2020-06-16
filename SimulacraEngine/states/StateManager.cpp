//
//  StateManager.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 15/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "StateManager.hpp"

StateManager::StateManager() { }

StateManager::~StateManager() { }

State& StateManager::getCurrentState() {
    return *states.back();
}

void StateManager::addState(state newState) {
    states.push_back(std::move(newState));
}

void StateManager::removeState() {
    if (!states.empty()) {
        states.pop_back();
    }
}
