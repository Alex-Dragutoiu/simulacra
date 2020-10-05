#include "GameEngine.hpp"
#include <iostream>


namespace simulacra {
    
    GameEngine::GameEngine(std::string name) : name(name) {
        init();
    }

    GameEngine::~GameEngine() {
        ImGui::SFML::Shutdown();
    }

    void GameEngine::initWindow() {
        std::vector<sf::VideoMode> VideoModes = sf::VideoMode::getFullscreenModes();
        window = std::make_shared<sf::RenderWindow>(sf::VideoMode(VideoModes[0].width,
                                                                  VideoModes[0].height,
                                                                  VideoModes[0].bitsPerPixel),
                                                    name,
                                                    sf::Style::Fullscreen);
        /* Set window's frame limit */
        window->setFramerateLimit(30);
    }
    
    void GameEngine::initResouces() {
        /* initalise fonts */
        fontLoader.load(Fonts::MENU_FONT, "Resources/fonts/TextPixelFont.ttf");
        
        /* initalise textures */
        textureLoader.load(Textures::MENU_BACKGROUND, "Resources/backgrounds/main_menu/mainmenu.jpg");
        textureLoader.load(Textures::DEFAULT_ENTITY, "Resources/entities/default.png");
        textureLoader.load(Textures::PLAYER_IDLE_LEFT, "Resources/entities/player/idle_left.png");
        textureLoader.load(Textures::PLAYER_IDLE_RIGHT, "Resources/entities/player/idle_right.png");
        textureLoader.load(Textures::PLAYER_LEFT, "Resources/entities/player/run_left.png");
        textureLoader.load(Textures::PLAYER_RIGHT, "Resources/entities/player/run_right.png");
        textureLoader.load(Textures::PLAYER_ATTACK_RIGHT, "Resources/entities/player/attack_right.png");
        
        textureLoader.load(Textures::MAP, "Resources/tileset.png");
    }
    
    void GameEngine::initImGui() {
        ImGui::SFML::Init(*window);
        
        ImGuiStyle* style = &ImGui::GetStyle();
        
        style->WindowRounding = 9.0f;
        
        style->FramePadding = ImVec2(10, 10);
        style->FrameRounding = 4.0f;
        
        style->ItemSpacing = ImVec2(12, 8);
        style->ItemInnerSpacing = ImVec2(8, 6);
        
        style->IndentSpacing = 25.0f;
        
        style->ScrollbarSize = 15.0f;
        style->ScrollbarRounding = 15.0f;
        
        style->GrabMinSize = 5.0f;
        style->GrabRounding = 3.0f;
        
        style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
        style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
        
        style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
        style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
        
        style->Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
        style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
        
        style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
        style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
        
        style->Colors[ImGuiCol_TitleBg] = ImColor(38, 115, 77);
        style->Colors[ImGuiCol_TitleBgCollapsed] = ImColor(51, 153, 102);
        style->Colors[ImGuiCol_TitleBgActive] = ImColor(38, 115, 77);
        
        style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        
        style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
        style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
        style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
        style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
        
        style->Colors[ImGuiCol_Tab] = ImColor(38, 115, 77);
        style->Colors[ImGuiCol_TabHovered] = ImColor(51, 153, 102);
        style->Colors[ImGuiCol_TabActive] = ImColor(38, 115, 77);
        
        style->Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
        style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
        style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
        
        style->Colors[ImGuiCol_Button] = ImColor(38, 115, 77);
        style->Colors[ImGuiCol_ButtonHovered] = ImColor(51, 153, 102);
        style->Colors[ImGuiCol_ButtonActive] = ImColor(38, 115, 77);
        
        style->Colors[ImGuiCol_Header] = ImColor(38, 115, 77);
        style->Colors[ImGuiCol_HeaderHovered] = ImColor(51, 153, 102);
        style->Colors[ImGuiCol_HeaderActive] = ImColor(38, 115, 77);
        
        style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        style->Colors[ImGuiCol_ResizeGripHovered] = ImColor(51, 153, 102);
        style->Colors[ImGuiCol_ResizeGripActive] = ImColor(38, 115, 77);
        
        style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
        style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
        style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
        style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
        
        style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
        style->Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);
    }
    
    void GameEngine::init() {
        initWindow();
        initResouces();
        
        /* initialise the state manager */
        stateManager = std::make_shared<StateManager>(State::Context(*window, textureLoader, fontLoader, manager));
        stateManager->clearStates();
        registerStates();
        
        /* add the initial state to the state manager */
        stateManager->addState(States::MENU_STATE);
        
        /* initialise ImGui */
        initImGui();

    }

    /* This method runs the game loop */
    void GameEngine::run() {
        
        // game loop
        while (window->isOpen()) {
            eventHandler();
            update();
            
            if (stateManager->empty()) {
                window->close();
            }
            
            draw();
        }
    }

    void GameEngine::eventHandler() {
        /* process events for ImGUI */
        ImGui::SFML::ProcessEvent(event);
        
        while (window->pollEvent(event)) {
            
            stateManager->handleEvents(event);
            
            if(event.type == event.Closed) {
                window->close();
            }
        }
    }
    
    void GameEngine::update() {
        dt = clock.getElapsedTime();
        
        ImGui::SFML::Update(*window, dt);
        
        manager.update(dt.asSeconds());
        stateManager->update(dt);
        
        clock.restart();
    }

    void GameEngine::draw() {
        // clear the window
        window->clear(sf::Color(214, 245, 214));
        
        /* draw the current state */
        stateManager->draw(window);
        manager.draw(*window);
        
        /* draw Views */
        
        ImGui::SFML::Render(*window);
        
        // display on window
        window->display();
    }
    
    void GameEngine::registerStates() {
        stateManager->registerState<EditorState>(States::EDITOR_STATE);
        stateManager->registerState<MenuState>(States::MENU_STATE);
        stateManager->registerState<GameState>(States::GAME_STATE);
    }
}
