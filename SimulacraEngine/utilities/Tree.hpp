//
//  Tree.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include <iostream>
#include <list>
#include <queue>
#include <stack>

#define DT_DIR 4

struct FileItem {
    std::string name;
    short type;
    
    std::shared_ptr<FileItem> parent;
    std::vector<std::shared_ptr<FileItem>> children;
    
    /// \brief for DEBUGGING purposes ///
    void show(int n) {
        std::cout << std::string(n * 2, '-') << name << std::endl;
        for (auto &x : children) {
            x->show(n + 1);
        }
    }
    
    FileItem(std::string name, short type) {
        this->name = name;
        this->type = type;
    }
    
    const char* getCharName() const {
        return name.c_str();
    }
    
    std::string getName() const {
        return name;
    }
    
    bool hasParent() {
        return parent != nullptr;
    }
};

class Tree {
private:
    std::shared_ptr<FileItem> root;
    
public:
    void insert(std::string name, short type, std::string parent);
    std::string getPath(std::shared_ptr<FileItem> item);
    std::shared_ptr<FileItem> getRoot();
    void display();
    
    Tree();
    ~Tree();
};

