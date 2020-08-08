//
//  MenuState.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <memory>

#include "State.hpp"
#include "GameState.hpp"

#include "../gui/Button.hpp"
#include "../gui/TextBox.hpp"

#include "../utilities/AssetLoader.hpp"

#include "../defines.h"

namespace simulacra {
    
    class MenuState : public State {
    public:
        /* menu options */
        enum class Options {
            START,
            SETTINGS,
            CREDITS,
            QUIT
        };
        
    private:
        sf::Text gameTitle;
        sf::Text studioTitle;
        
        sf::Sprite backgroundImage;
        
        std::unordered_map<Options, Button> buttons;
        
    private:
        void initButtons();
        
    public:
        void init() override;
        
        // The three important actions within a game loop
        void handleEvents(const sf::Event& event) override;
        void draw(std::shared_ptr<sf::RenderWindow>& target) override;
        void update(const sf::Time& dt) override;
        
        MenuState(StateManager& stateManager, Context context);
        ~MenuState();
    };
}
