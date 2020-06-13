//
//  FileSystemView.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <map>

#include "imgui.h"
#include "imgui-SFML.h"

#include "../utilities/Tree.hpp"

#include <dirent.h>
#include <stack>
#include <SFML/Graphics.hpp>

class FileSystemView {
private:
    /* Model */
    sf::Texture tex;
    sf::IntRect textureDimensions;
    
    Tree resources;
    std::shared_ptr<FileItem> currentFile;
    
    const char* comboLabel;
    int itemCurrentIndex;
    int flags;
    int selected;
    
    int width = 0;
    int height = 0;
    
private:
    void drawMenuBar();
    void drawCombo();
    void drawRightPanel();
    void drawLeftPanel();
    
    void loadResourcePaths();
    bool isDir(FileItem& file) const;
public:
    void draw();
    
    FileSystemView();
    ~FileSystemView();
};



