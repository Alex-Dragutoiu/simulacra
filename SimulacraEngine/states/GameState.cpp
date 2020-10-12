//
//  GameState.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "GameState.hpp"

namespace simulacra {
    
    GameState::GameState(StateManager& stateManager, Context context) : State(stateManager, context), gridMap(22, 16, 2.f, sf::Vector2u(64, 63)), map(*context.textures) {
        init();
    }

    GameState::~GameState() { }

    void GameState::init() {
        isGridActive = false;
        
        view = std::make_shared<sf::View>(getContext().window->getDefaultView());
        auto ecs = getContext().ecs;
        
        ecs->addEntity(0);
        ecs->addComponent<ECS::TransformationComponent>(0, sf::Vector2f { 100.f, 1100.f }, sf::Vector2f { 10.f, 10.f }, 1.5f);
        ecs->addComponent<ECS::SpriteComponent>(0, getContext().textures->get(Textures::DEFAULT_ENTITY));
        ecs->addComponent<ECS::VelocityComponent>(0, 295.f);
        ecs->addComponent<ECS::ColliderComponent>(0, sf::FloatRect(361.f, 1240.f, 99.f, 281.f));
    
        ecs->addEntity(1);
        ecs->addComponent<ECS::TransformationComponent>(1, sf::Vector2f { 700.f, 1100.f }, sf::Vector2f { 10.f, 10.f }, 1.5f);
        ecs->addComponent<ECS::SpriteComponent>(1, getContext().textures->get(Textures::DEFAULT_ENTITY));
        ecs->addComponent<ECS::ColliderComponent>(1, sf::FloatRect(960.f, 1240.f, 99.f, 281.f));
        
//        animComp->addAnimation("IDLE", &getContext().textures->get(Textures::PLAYER_IDLE_LEFT), 200, 200);
//        animComp->addAnimation("IDLE", &getContext().textures->get(Textures::PLAYER_IDLE_RIGHT), 200, 200);
//        animComp->addAnimation("LEFT", &getContext().textures->get(Textures::PLAYER_LEFT), 200, 200);
//        animComp->addAnimation("RIGHT", &getContext().textures->get(Textures::PLAYER_RIGHT), 200, 200);
//        animComp->addAnimation("ATTACK_RIGHT", &getContext().textures->get(Textures::PLAYER_ATTACK_RIGHT), 200, 200);
        
        ecs->addUpdateSystem<ECS::MovementSystem>();
        ecs->addUpdateSystem<ECS::CollisionSystem>();
        ecs->addDrawSystem<ECS::RenderSystem>();
        
        ecsView = std::make_shared<ECSView>(*ecs);
        
        map.loadFromJSON("map.json");
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
        ecsView->draw(true);
        map.draw(*target);
        gridMap.draw(*target, isGridActive);
        
    }

    void GameState::update(const float& dt) {
        getContext().window->setView(*view);
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


//        auto& player = objects.addObject();
//        /* add components to the player */
//        player.addComponent<TransformationComponent>(100.f, 1100.f);
//        player.addComponent<SpriteComponent>(getContext().textures->get(Textures::DEFAULT_ENTITY));
//        player.addComponent<CameraComponent>(view);
//
//        auto collider_c = player.addComponent<CollisionComponent>(sf::Vector2u(550, 1450), sf::Vector2u(100, 250));
//
//        auto animation_c = player.addComponent<AnimationComponent>(.05f);
//        animation_c->addAnimation(Action::IDLE_LEFT, &getContext().textures->get(Textures::PLAYER_IDLE_LEFT), 200, 200);
//        animation_c->addAnimation(Action::IDLE_RIGHT, &getContext().textures->get(Textures::PLAYER_IDLE_RIGHT), 200, 200);
//        animation_c->addAnimation(Action::LEFT, &getContext().textures->get(Textures::PLAYER_LEFT), 200, 200);
//        animation_c->addAnimation(Action::RIGHT, &getContext().textures->get(Textures::PLAYER_RIGHT), 200, 200);
//        animation_c->addAnimation(Action::ATTACK_RIGHT, &getContext().textures->get(Textures::PLAYER_ATTACK_RIGHT), 200, 200);
//
//        player.addComponent<MovementComponent>(295.f);

//        stats.addModel(&player);
