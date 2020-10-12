//
//  StateManager.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 15/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include "State.hpp"
#include "StateEnums.h"
#include "../ResourceIdentifiers.h"

#include <SFML/System/NonCopyable.hpp>

#include <iostream>
#include <memory>
#include <vector>
#include <functional>

namespace simulacra {

    class StateManager : private sf::NonCopyable {
    public:
        enum class Action {
            PUSH,
            POP,
            CLEAR
        };
        
    public:
        struct PendingAction {
            explicit PendingAction(Action action, States id = States::NONE);
            
            Action action;
            States id;
        };
        
        template <typename T>
        void registerState(States stateID);
        
        void addState(States stateID);
        void removeState();
        void clearStates();
        
        void handleEvents(const sf::Event& event);
        void update(const float& dt);
        void draw(std::shared_ptr<sf::RenderWindow>& target);
        
        void applyChange();
        
        bool empty();
        
        StateManager(State::Context context);
        ~StateManager();
        
    private:
        std::vector<std::unique_ptr<State>> stack;
        std::vector<PendingAction> pendingActions;
        std::map<States, std::function<std::unique_ptr<State>()>> factories;
        State::Context context;
    
    private:
        std::unique_ptr<State> createState(States stateID);

    };
    
    template <typename T>
    void StateManager::registerState(States stateID) {
        factories[stateID] = [this] () {
            return std::unique_ptr<State>(new T(*this, context));
        };
    }
}
