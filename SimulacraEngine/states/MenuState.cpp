//
//  MenuState.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#include "MenuState.hpp"
#include "GameState.hpp"

#define SIZE 128
#define X_POS 40
#define Y_POS 0
#define GAME_TITLE "SIMULACRA"
#define STUDIO_NAME "Gameopath Studios"

MenuState::MenuState(GameEngine* context) {
    this->context = context;
    init();
}

MenuState::~MenuState() { }

void MenuState::init() {
    texture = std::make_shared<sf::Texture>();
    texture->loadFromFile("Resources/backgrounds/main_menu/mainmenu.jpg");
    
    backgroundImage.setTexture(*texture);
    
    backgroundImage.setScale(2.5f, 3.f);

    /* set the font of the buttons */
    font = std::make_shared<sf::Font>();
    font->loadFromFile("Resources/fonts/TextPixelFont.ttf");
    
    gameTitle.setFont(*font);
    gameTitle.setCharacterSize(SIZE + SIZE);
    gameTitle.setOrigin((2 * gameTitle.getPosition().x + gameTitle.getGlobalBounds().width) / 2,
                        (2 * gameTitle.getPosition().y + gameTitle.getGlobalBounds().height) / 2);
    gameTitle.setPosition(context->getWindow()->getSize().x / 3, -100);
    gameTitle.setString(GAME_TITLE);
    gameTitle.setFillColor(sf::Color::White);
    
    start.setPosition(context->getWindow()->getSize().x / 3, X_POS + 128 * 2);
    start.setCharacterSize(SIZE);
    start.setString("Start");
    start.setIdleColour(sf::Color::White);
    start.setHoverColour(sf::Color::Red);
    start.setPressedColour(sf::Color::White);
    start.setFont(*font);
    
    options.setPosition(context->getWindow()->getSize().x / 3, X_POS + 128 * 3);
    options.setCharacterSize(SIZE);
    options.setString("Options");
    options.setIdleColour(sf::Color::White);
    options.setHoverColour(sf::Color::Red);
    options.setPressedColour(sf::Color::White);
    options.setFont(*font);
    
    credits.setPosition(context->getWindow()->getSize().x / 3, X_POS + 128 * 4);
    credits.setCharacterSize(SIZE);
    credits.setString("Credits");
    credits.setIdleColour(sf::Color::White);
    credits.setHoverColour(sf::Color::Red);
    credits.setPressedColour(sf::Color::White);
    credits.setFont(*font);
    
    quit.setPosition(context->getWindow()->getSize().x / 3, X_POS + 128 * 5);
    quit.setCharacterSize(SIZE);
    quit.setString("Quit");
    quit.setIdleColour(sf::Color::White);
    quit.setHoverColour(sf::Color::Red);
    quit.setPressedColour(sf::Color::White);
    quit.setFont(*font);
    
    /* Initialise textbox */
    //    textBox = new TextBox(10, sf::Color::White);
    //    textBox->setFont(*font);
    //    textBox->setCharacterSize(SIZE);
    //    textBox->setPosition(sf::Vector2f(X_POS, Y_POS + 128 * 6));
}

void MenuState::draw(std::shared_ptr<sf::RenderWindow>& target) {
    target->draw(backgroundImage);
    
    start.draw(target);
    options.draw(target);
    credits.draw(target);
    quit.draw(target);
    
    target->draw(gameTitle);
}

void MenuState::update(const sf::Time& dt) {
    // get the current mouse position in the window
    sf::Vector2i pixelPos = sf::Mouse::getPosition(*context->getWindow());
    
    // convert it to world coordinates
    sf::Vector2f worldPos = context->getWindow()->mapPixelToCoords(pixelPos);
    
    start.update(worldPos);
    options.update(worldPos);
    credits.update(worldPos);
    quit.update(worldPos);
}

void MenuState::handleEvents(sf::Event& event) {
    if (start.isPressed()) {
        context->pushState(std::make_shared<GameState>(context));
    }
    
    if (options.isPressed()) {
        
    }
    
    if (credits.isPressed()) {
        
    }
    
    if (quit.isPressed()) {
        context->getWindow()->close();
    }
}
