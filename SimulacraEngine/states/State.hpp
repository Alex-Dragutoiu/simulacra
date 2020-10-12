//
//  State.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <memory>

#include "StateEnums.h"
#include "../ResourceIdentifiers.h"
#include "../utilities/AssetLoader.hpp"
#include "../ECS/ECS.h"

#include <SFML/Graphics.hpp>

namespace simulacra {
    
    class StateManager;
    
    class State {
    public:
        struct Context {
            Context(sf::RenderWindow& window, TextureLoader& textures, FontLoader& fonts, ECS::ECSManager& ecs);
            
            sf::RenderWindow* window;
            TextureLoader* textures;
            FontLoader* fonts;
            ECS::ECSManager* ecs;
        };
        
    public:
        virtual void init() = 0;
        
        /* The three important actions within a game loop */
        virtual void handleEvents(const sf::Event& event) = 0;
        virtual void draw(std::shared_ptr<sf::RenderWindow>& target) = 0;
        virtual void update(const float& dt) = 0;
        
        State(StateManager& stateManager, Context context);
        virtual ~State() { };
        
    protected:
        Context getContext() const;
        
        void reqStatePush(States state);
        void reqStatePop();
        void reqClear();
        
    private:
        StateManager* stateManager;
        Context context;
    };
}
