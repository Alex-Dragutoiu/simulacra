#pragma once

#include <iostream>
#include <memory>

#include "imgui.h"
#include "imgui-SFML.h"

#include "../states/StateManager.hpp"

#include "../views/HierarchyView.hpp"

#include <SFML/Graphics.hpp>

#include "../states/EditorState.hpp"
#include "../states/MenuState.hpp"

class State;

class GameEngine {
private:
    /* manages states */
    StateManager stateManager;
    
    std::shared_ptr<sf::RenderWindow> window;
    
    sf::Clock clock;
    sf::Event event;
    sf::Time dt;
    
    /* window specifics */
    int width;
    int height;
    std::string name;
    
    /* views */
    HierarchyView statesView;
    
public:
    std::shared_ptr<sf::RenderWindow> getWindow();
    
    // the game loop
    void run();
    
    void init();
    
    // game loop methods
    void eventHandler();
    void update();
    void draw();
    
    // constructors and destructors
    GameEngine(int width, int height, std::string name);
    ~GameEngine();
};
