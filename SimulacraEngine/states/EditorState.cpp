//
//  EditorState.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "EditorState.hpp"
#include <cstdlib>

namespace simulacra {
    
    EditorState::EditorState(StateManager& stateManager, Context context) : State(stateManager, context) {
        init();
    }

    EditorState::~EditorState() { }

    void EditorState::init() {
        tree = std::make_shared<QuadTree<Point>>(sf::FloatRect{0, 0, static_cast<float>(getContext().window->getSize().x), static_cast<float>(getContext().window->getSize().y)}, 4);
    }
    
    void EditorState::handleEvents(const sf::Event& event) {
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Escape: {
                    getContext().window->close();
                    break;
                }
                default: {
                    break;
                }
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i position = sf::Mouse::getPosition(*getContext().window);
            tree->insert({static_cast<float>(position.x), static_cast<float>(position.y)});
        }
    }

    void EditorState::draw(std::shared_ptr<sf::RenderWindow>& target) {
        tree->draw(*target);
    }

    void EditorState::update(const sf::Time& dt) {
        
    }
}

//        for (int i = 0; i < 100; i++) {
//            auto pointX = static_cast<float>(rand() % getContext().window->getSize().x);
//            auto pointY = static_cast<float>(rand() % getContext().window->getSize().y);
//            tree->insert(Point{ pointX, pointY });
//        }
