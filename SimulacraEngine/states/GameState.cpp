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
        view = std::make_shared<sf::View>();
        view->setCenter(getContext().window->getSize().x / 2, getContext().window->getSize().y / 2);
        
        player = std::make_shared<Entity>();
        
        player->setHealth(100.f);
        player->setDamage(45.f);
        player->setArmor(4.f);
        player->setMana(100.f);
        player->setSpeed(295.f);
        
        /* add components to the player */
        player->addComponent<TransformationComponent>(100.f, 100.f);
        player->addComponent<SpriteComponent>(&getContext().textures->get(Textures::DEFAULT_ENTITY));
        player->addComponent<CameraComponent>(view);

        auto animation_c = player->addComponent<AnimationComponent>(.05f);
        animation_c->addAnimation(Action::IDLE_LEFT, &getContext().textures->get(Textures::PLAYER_IDLE_LEFT), 200, 200);
        animation_c->addAnimation(Action::IDLE_RIGHT, &getContext().textures->get(Textures::PLAYER_IDLE_RIGHT), 200, 200);
        animation_c->addAnimation(Action::LEFT, &getContext().textures->get(Textures::PLAYER_LEFT), 200, 200);
        animation_c->addAnimation(Action::RIGHT, &getContext().textures->get(Textures::PLAYER_RIGHT), 200, 200);
        animation_c->addAnimation(Action::ATTACK_RIGHT, &getContext().textures->get(Textures::PLAYER_ATTACK_RIGHT), 200, 200);
        
        player->addComponent<MovementComponent>(player->getSpeed());
        
    }

    void GameState::handleEvents(const sf::Event& event) {
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Escape:
                    getContext().window->close();
                    break;
                default:
                    break;
            }
        }
    }

    void GameState::draw(std::shared_ptr<sf::RenderWindow>& target) {
        player->draw(*target);
    }

    void GameState::update(const sf::Time& dt) {
        player->update(dt);
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
