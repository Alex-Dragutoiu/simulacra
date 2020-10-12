//
//  StateManager.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 15/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "StateManager.hpp"

namespace simulacra {
    
    StateManager::PendingAction::PendingAction(Action action, States id) : action(action), id(id) { }
    
    void StateManager::applyChange() {
        for (auto& pendingAction : pendingActions) {
            switch (pendingAction.action) {
                case Action::PUSH:
                    stack.push_back(createState(pendingAction.id));
                    break;
                case Action::POP:
                    if (!stack.empty()) {
                        stack.pop_back();
                    }
                    break;
                case Action::CLEAR:
                    stack.clear();
                    break;
                default:
                    break;
            }
        }
        pendingActions.clear();
    }
    
    StateManager::StateManager(State::Context context) : context(context) { }

    StateManager::~StateManager() {
        while(!stack.empty()) {
            stack.pop_back();
        }
    }
    
    void StateManager::addState(States stateId) {
        pendingActions.push_back(PendingAction(Action::PUSH, stateId));
    }

    void StateManager::removeState() {
        pendingActions.push_back(PendingAction(Action::POP));
    }
    
    void StateManager::clearStates() {
        pendingActions.push_back(PendingAction(Action::CLEAR));
    }
    
    std::unique_ptr<State> StateManager::createState(States stateID) {
        auto found = factories.find(stateID);
        assert(found != factories.end());
        
        return found->second();
    }
    
    void StateManager::handleEvents(const sf::Event& event) {
        if (!stack.empty()) {
            stack.back()->handleEvents(event);
        }
        applyChange();
    }
    
    void StateManager::draw(std::shared_ptr<sf::RenderWindow>& target) {
        for (auto& state : stack) {
            state->draw(target);
        }
    }
    
    void StateManager::update(const float& dt) {
        applyChange();
        if (!stack.empty()) {
            stack.back()->update(dt);
        } else {
            context.window->close();
        }
    }
    
    bool StateManager::empty() {
        return stack.empty();
    }
}


