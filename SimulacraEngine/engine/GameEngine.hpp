#pragma once

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

#include "imgui.h"
#include "imgui-SFML.h"

#include "../states/State.hpp"
#include "../states/MenuState.hpp"
#include "../states/GameState.hpp"
#include "../states/EditorState.hpp"

#include "../states/StateManager.hpp"

#include "../views/HierarchyView.hpp"
#include "../enums.h"
#include "../utilities/AssetLoader.hpp"

namespace simulacra {
    
    class GameEngine { 
    private:
        /* resource managers */
        TextureLoader textureLoader;
        FontLoader fontLoader;
        
        /* manages states */
        std::shared_ptr<StateManager> stateManager;
        
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
        
    private:
        void registerStates();
        
    public:
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
}
