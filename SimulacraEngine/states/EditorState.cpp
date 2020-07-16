////
////  EditorState.cpp
////  SimulacraEngine
////
////  Created by Alex Dragutoiu on 09/06/2020.
////  Copyright © 2020 Alex Dragutoiu. All rights reserved.
////
//
//#include "EditorState.hpp"
//
//EditorState::EditorState(GameEngine* context) : player(0, -1000) {
//    this->context = context;
//    init();
//
//    /* attach camera to the player */
//    player.addCamera(camera);
//
//}
//
//EditorState::~EditorState() { }
//
//void EditorState::init() {
//    /* initialise the camera */
//    camera = std::make_shared<sf::View>(sf::FloatRect(0, 0, context->getWindow()->sf::Window::getSize().x
//                                                          , context->getWindow()->sf::Window::getSize().y));
//    /* initialise parallax scrolling */
//    parallax = std::make_unique<ParallaxBackground>(camera);
//    parallax->addLayer("Resources/backgrounds/parallax/plx-2.png", sf::Vector2f(0, 0), .9f);
//    parallax->addLayer("Resources/backgrounds/parallax/plx-3.png", sf::Vector2f(0, 0), .5f);
//    parallax->addLayer("Resources/backgrounds/parallax/plx-4.png", sf::Vector2f(0, 0), .3f);
//    parallax->addLayer("Resources/backgrounds/parallax/plx-5.png", sf::Vector2f(0, 0), .1f);
//    
//    debugView.addModel(*parallax, player);
//    
//}
//
//void EditorState::handleEvents(sf::Event& event) {
//    if (event.type == sf::Event::KeyPressed) {
//        switch (event.key.code) {
//            case sf::Keyboard::Escape:
//                context->getWindow()->close();
//                break;
//            default:
//                break;
//        }
//    } else if (event.type == sf::Event::Resized) {
//        // resize my view
//        camera->setSize({
//            static_cast<float>(event.size.width),
//            static_cast<float>(event.size.height)
//        });
//        context->getWindow()->setView(*camera);
//    }
//}
//
//void EditorState::draw(std::shared_ptr<sf::RenderWindow>& target) {
//    context->getWindow()->setView(*camera);
//    
//    debugView.draw();
//    
//    //    axis.draw(target.get());
//    //    player.draw(target.get());
//    //    hierView.draw();
//    //    fileView.draw();
//    
//    parallax->draw(target);
//    
//    player.draw(target.get());
//    
//    // set view to default so you can draw HUDs
//    context->getWindow()->setView(context->getWindow()->getDefaultView());
//
//    /** \todo draw HUD */
//}
//
//void EditorState::update(const sf::Time& dt) {
//    float cameraMove = 0;
//    
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//        if (limit > 0) {
//            cameraMove = -250.f;
//            limit += cameraMove;
//            camera->move(cameraMove * dt.asSeconds(), 0);
//        }
//    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//        cameraMove = 250.f;
//        limit += cameraMove;
//        camera->move(cameraMove * dt.asSeconds(), 0);
//    }
//    
//    parallax->update(dt, cameraMove);
//    
//    player.update(dt.asSeconds());
//}
//
//std::string EditorState::toString() {
//    return "EditorState";
//}
