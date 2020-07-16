//
//  MenuState.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#include "MenuState.hpp"
namespace simulacra {
    
    MenuState::MenuState(StateManager& stateManager, Context context) : State(stateManager, context) {
        init();
        initButtons();
    }

    MenuState::~MenuState() { }

    void MenuState::initButtons() {
        sf::Font& font = getContext().fonts->get(Fonts::MENU_FONT);
        
        Button start(getContext().window->getSize().x / 3, MAIN_MENU_X_POS + 128 * 2,
                                CHARACTER_SIZE, "Start",
                                sf::Color::White, sf::Color::Red, sf::Color::White);
        
        start.setFont(font);
        buttons[Options::START] = start;
        
        
        Button settings(getContext().window->getSize().x / 3, MAIN_MENU_X_POS + 128 * 3,
                                   CHARACTER_SIZE, "Settings",
                                   sf::Color::White, sf::Color::Red, sf::Color::White);
        settings.setFont(font);
        buttons[Options::SETTINGS] = settings;
        
        
        Button credits(getContext().window->getSize().x / 3, MAIN_MENU_X_POS + 128 * 4,
                                  CHARACTER_SIZE, "Credits",
                                  sf::Color::White, sf::Color::Red, sf::Color::White);
        credits.setFont(font);
        buttons[Options::CREDITS] = credits;
        
        Button quit(getContext().window->getSize().x / 3, MAIN_MENU_X_POS + 128 * 5,
                               CHARACTER_SIZE, "Quit",
                               sf::Color::White, sf::Color::Red, sf::Color::White);
        quit.setFont(font);
        buttons[Options::QUIT] = quit;
    }

    void MenuState::init() {
        sf::Texture& text = getContext().textures->get(Textures::MENU_BACKGROUND);
        sf::Font& font = getContext().fonts->get(Fonts::MENU_FONT);
        
        backgroundImage.setTexture(text);
        backgroundImage.setScale(2.5f, 3.f);

        gameTitle.setFont(font);
        gameTitle.setCharacterSize(CHARACTER_SIZE * 2);
        gameTitle.setOrigin((2 * gameTitle.getPosition().x + gameTitle.getGlobalBounds().width) / 2,
                            (2 * gameTitle.getPosition().y + gameTitle.getGlobalBounds().height) / 2);
        gameTitle.setPosition(getContext().window->getSize().x / 3, -100);
        gameTitle.setString(GAME_TITLE);
        gameTitle.setFillColor(sf::Color::White);
    }

    void MenuState::draw(std::shared_ptr<sf::RenderWindow>& target) {
        target->draw(backgroundImage);
        
        for (auto& button : buttons) {
            button.second.draw(target);
        }
        
        target->draw(gameTitle);
    }

    void MenuState::update(const sf::Time& dt) {
        // get the current mouse position in the window
        sf::Vector2i pixelPos = sf::Mouse::getPosition(*getContext().window);
        
        // convert it to world coordinates
        sf::Vector2f worldPos = getContext().window->mapPixelToCoords(pixelPos);
        
        for (auto& button : buttons) {
            button.second.update(worldPos);
        }
    }

    void MenuState::handleEvents(const sf::Event& event) {
        if (buttons[Options::QUIT].isPressed()) {
            reqStatePop();
        }
    }

}
