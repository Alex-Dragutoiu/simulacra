//
//  GameState.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include "imgui.h"
#include "imgui-SFML.h"

#include "State.hpp"

#include "../entities/Entity.hpp"
#include "../entities/GameObject.hpp"

#include "../components/SpriteComponent/SpriteComponent.hpp"
#include "../components/AnimationComponent/AnimationComponent.hpp"
#include "../components/TransformationComponent/TransformationComponent.hpp"
#include "../components/MovementComponent/MovementComponent.hpp"
#include "../components/CameraComponent/CameraComponent.hpp"
#include "../map/Map.hpp"
#include "../map/GridMap.hpp"

#include "../views/HierarchyView.hpp"

namespace simulacra {
    
    class GameState : public State {
    private:
        std::shared_ptr<sf::View> view;
        sf::Texture background;
        
        ObjectManager objects;
        
        Map tileMap;
        GridMap gridMap;
        
        bool isGridActive;
        
        HierarchyView stats;
        
    public:
        void init() override;
        
        // The three important actions within a game loop
        void handleEvents(const sf::Event& event) override;
        void draw(std::shared_ptr<sf::RenderWindow>& target) override;
        void update(const sf::Time& dt) override;
        
        // Constructors & Destructors
        GameState(StateManager& stateManager, Context context);
        ~GameState();
    };
}
