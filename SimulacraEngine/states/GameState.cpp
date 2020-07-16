//
//  GameState.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "GameState.hpp"

namespace simulacra {
    
    GameState::GameState(StateManager& stateManager, Context context) : State(stateManager, context) {
        init();
    }

    GameState::~GameState() { }

    void GameState::init() {
        view.setCenter(getContext().window->getSize().x / 2, getContext().window->getSize().y / 2);
    }

    void GameState::handleEvents(const sf::Event& event) {
        /* process events for ImGUI */
        ImGui::SFML::ProcessEvent(event);
        
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::A:
                    
                    break;
                case sf::Keyboard::D:
                    
                    break;
                case sf::Keyboard::Escape:
                    getContext().window->close();
                    break;
                default:
                    break;
            }
        }
    }

    void GameState::draw(std::shared_ptr<sf::RenderWindow>& target) {
        // get the current mouse position in the window
        sf::Vector2i pixelPos = sf::Mouse::getPosition(*getContext().window);
        
        // convert it to world coordinates
        sf::Vector2f worldPos = getContext().window->mapPixelToCoords(pixelPos);
        
    }

    void GameState::update(const sf::Time& dt) {
        
    }

}
