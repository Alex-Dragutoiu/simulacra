//
//  GameState.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "GameState.hpp"

GameState::GameState(GameEngine* context) {
    this->context = context;
    init();
}

GameState::~GameState() {

}

void GameState::init() {
	view.setCenter(context->getWindow()->getSize().x / 2, context->getWindow()->getSize().y / 2);
}

void GameState::handleEvents(sf::Event& event) {
    /* process events for ImGUI */
    ImGui::SFML::ProcessEvent(event);
    
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::A:
                
                break;
            case sf::Keyboard::D:
                
                break;
            case sf::Keyboard::Escape:
                context->getWindow()->close();
                break;
            default:
                break;
        }
    }
}

void GameState::draw(std::shared_ptr<sf::RenderWindow>& target) {
    // get the current mouse position in the window
    sf::Vector2i pixelPos = sf::Mouse::getPosition(*context->getWindow());
    
    // convert it to world coordinates
    sf::Vector2f worldPos = context->getWindow()->mapPixelToCoords(pixelPos);
    
}

void GameState::update(const sf::Time& dt) {
    
}

std::string GameState::toString() {
    return "GameState";
}
