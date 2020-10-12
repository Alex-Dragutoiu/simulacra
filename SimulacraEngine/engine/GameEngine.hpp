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

#include "../enums.h"
#include "../utilities/AssetLoader.hpp"
#include "../parsers/Parser.hpp"

#include "../ECS/ECS.h"

namespace simulacra {
    
    class GameEngine { 
    private:
        /* resource managers */
        TextureLoader textureLoader;
        FontLoader fontLoader;
        
        EngineStyleParser parser;
        
        /* manages states */
        std::shared_ptr<StateManager> stateManager;
        
        std::shared_ptr<sf::RenderWindow> window;
        
        /* Entity Component System */
        ECS::ECSManager manager;
        
        /* utils */
        sf::Clock clock;
        sf::Event event;
        sf::Time dt;
        
        /* name of application */
        std::string name;
        
    private:
        void registerStates();
        
    public:
        // the game loop
        void run();
        
        void init();
        void initWindow();
        void initResouces();
        void initImGui();
        
        // game loop methods
        void eventHandler();
        void update();
        void draw();
        
        // constructors and destructors
        GameEngine(std::string name);
        ~GameEngine();
    };
}
