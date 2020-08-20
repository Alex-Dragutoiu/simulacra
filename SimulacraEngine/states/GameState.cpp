//
//  GameState.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "GameState.hpp"

namespace simulacra {
    
    GameState::GameState(StateManager& stateManager, Context context) : State(stateManager, context), gridMap(22, 16, 2.f, sf::Vector2u(64, 63)), tileMap(22, 16) {
        init();
    }

    GameState::~GameState() { }

    void GameState::init() {
        isGridActive = false;
        
        view = std::make_shared<sf::View>(getContext().window->getDefaultView());
        
        auto& player = objects.addObject();
        
        /* add components to the player */
        player.addComponent<TransformationComponent>(100.f, 1100.f);
        player.addComponent<SpriteComponent>(&getContext().textures->get(Textures::DEFAULT_ENTITY));
        player.addComponent<CameraComponent>(view);

        auto animation_c = player.addComponent<AnimationComponent>(.05f);
        animation_c->addAnimation(Action::IDLE_LEFT, &getContext().textures->get(Textures::PLAYER_IDLE_LEFT), 200, 200);
        animation_c->addAnimation(Action::IDLE_RIGHT, &getContext().textures->get(Textures::PLAYER_IDLE_RIGHT), 200, 200);
        animation_c->addAnimation(Action::LEFT, &getContext().textures->get(Textures::PLAYER_LEFT), 200, 200);
        animation_c->addAnimation(Action::RIGHT, &getContext().textures->get(Textures::PLAYER_RIGHT), 200, 200);
        animation_c->addAnimation(Action::ATTACK_RIGHT, &getContext().textures->get(Textures::PLAYER_ATTACK_RIGHT), 200, 200);
        
        player.addComponent<MovementComponent>(295.f);
        
        stats.addModel(&player);
        
        tileMap.load(getContext().textures->get(Textures::MAP), sf::Vector2u(64, 63));
        tileMap.setScale(2.f, 2.f);
    }

    void GameState::handleEvents(const sf::Event& event) {
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Escape:
                    getContext().window->close();
                    break;
                case sf::Keyboard::G:
                    isGridActive = !isGridActive;
                    break;
                default:
                    break;
            }
        }
    }

    void GameState::draw(std::shared_ptr<sf::RenderWindow>& target) {
        target->draw(tileMap);
        gridMap.draw(*target, isGridActive);
        
        objects.draw(*target);
        stats.draw(true);
    }

    void GameState::update(const sf::Time& dt) {
        getContext().window->setView(*view);
        objects.update(dt);
    }

}

//        /* process events for ImGUI */
//        ImGui::SFML::ProcessEvent(event);
//
//        // get the current mouse position in the window
//        sf::Vector2i pixelPos = sf::Mouse::getPosition(*getContext().window);
//
//        // convert it to world coordinates
//        sf::Vector2f worldPos = getContext().window->mapPixelToCoords(pixelPos);
