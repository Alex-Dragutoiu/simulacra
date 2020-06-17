//
//  MenuState.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#include "MenuState.hpp"

MenuState::MenuState(GameEngine* context) {
    this->context = context;
    /* set the font of the buttons */
    font = AssetLoader::loadFont(FONT);
    
    init();
    initButtons();
}

MenuState::~MenuState() { }

void MenuState::initButtons() {
    simulacra::Button start(context->getWindow()->getSize().x / 3, MAIN_MENU_X_POS + 128 * 2,
                            SIZE, "Start",
                            sf::Color::White, sf::Color::Red, sf::Color::White);
    start.setFont(*font);
    buttons["START"] = start;
    
    
    simulacra::Button settings(context->getWindow()->getSize().x / 3, MAIN_MENU_X_POS + 128 * 3,
                               SIZE, "Settings",
                               sf::Color::White, sf::Color::Red, sf::Color::White);
    settings.setFont(*font);
    buttons["SETTINGS"] = settings;
    
    
    simulacra::Button credits(context->getWindow()->getSize().x / 3, MAIN_MENU_X_POS + 128 * 4,
                              SIZE, "Credits",
                              sf::Color::White, sf::Color::Red, sf::Color::White);
    credits.setFont(*font);
    buttons["CREDITS"] = credits;
    
    simulacra::Button quit(context->getWindow()->getSize().x / 3, MAIN_MENU_X_POS + 128 * 5,
                           SIZE, "Quit",
                           sf::Color::White, sf::Color::Red, sf::Color::White);
    quit.setFont(*font);
    buttons["QUIT"] = quit;
}

void MenuState::init() {
    texture = AssetLoader::loadTexture(MAIN_MENU_BACKGROUND);
    
    backgroundImage.setTexture(*texture);
    
    backgroundImage.setScale(2.5f, 3.f);

    gameTitle.setFont(*font);
    gameTitle.setCharacterSize(SIZE + SIZE);
    gameTitle.setOrigin((2 * gameTitle.getPosition().x + gameTitle.getGlobalBounds().width) / 2,
                        (2 * gameTitle.getPosition().y + gameTitle.getGlobalBounds().height) / 2);
    gameTitle.setPosition(context->getWindow()->getSize().x / 3, -100);
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
    sf::Vector2i pixelPos = sf::Mouse::getPosition(*context->getWindow());
    
    // convert it to world coordinates
    sf::Vector2f worldPos = context->getWindow()->mapPixelToCoords(pixelPos);
    
    for (auto& button : buttons) {
        button.second.update(worldPos);
    }
}

void MenuState::handleEvents(sf::Event& event) {
    if (buttons["QUIT"].isPressed()) {
        context->getWindow()->close();
    }
}

std::string MenuState::toString() {
    return "MenuState";
}
