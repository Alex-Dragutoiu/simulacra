#pragma once

#include <iostream>
#include <memory>

#include "imgui.h"
#include "imgui-SFML.h"

#include "../states/State.hpp"
#include "../utilities/TextureLoader.hpp"
#include "../views/HierarchyView.hpp"

#include <SFML/Graphics.hpp>

class GameEngine {
private:
    std::vector<std::shared_ptr<State>> states;
    
    std::shared_ptr<sf::RenderWindow> window;
    
    sf::Clock clock;
    sf::Event event;
    
    sf::Time dt;
    int width;
    int height;
    std::string name;
    
public:
    std::shared_ptr<sf::RenderWindow> getWindow();
    
    // the game loop
    void run();
    
    // set current to new state
    void pushState(std::shared_ptr<State> nextState);
    void popState();
    
    /* gets the state at the top of the stack */
    std::shared_ptr<State> getCurrentState();
    
    void init();
    
    // game loop methods
    void eventHandler();
    void update();
    void draw();
    
    // constructors and destructors
    GameEngine(int w, int h, std::string name);
    ~GameEngine();
};
