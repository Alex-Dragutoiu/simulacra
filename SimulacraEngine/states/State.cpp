//
//  State.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 05/07/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "State.hpp"
#include "StateManager.hpp"

namespace simulacra {
    
    State::Context::Context(sf::RenderWindow& window, TextureLoader& textures, FontLoader& fonts, ECS::ECSManager& ecs) : window(&window), textures(&textures), fonts(&fonts), ecs(&ecs) {
        
    }
    
    State::State(StateManager& stateManager, Context context) : stateManager(&stateManager), context(context) {
     
    }
    
    void State::reqClear() { 
        stateManager->clearStates();
    }
    
    
    void State::reqStatePop() { 
        stateManager->removeState();
    }
    
    
    void State::reqStatePush(States state) {
        stateManager->addState(state);
    }
    
    State::Context State::getContext() const {
        return context;
    }
}
