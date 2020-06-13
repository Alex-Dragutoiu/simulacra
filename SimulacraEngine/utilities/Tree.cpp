//
//  Tree.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#include "Tree.hpp"

Tree::Tree() {
    root = nullptr;
}

/* This is for debugging purposes */
void Tree::display() {
    /* If the tree is empty there is no way of traversing
     * the tree.
     */
    if (root == NULL) {
        std::cout << "No files or directories in the tree!" << std::endl;
        return;
    }
    
    root->show(0);
}


std::string Tree::getPath(std::shared_ptr<FileItem> item) {
    if (item->name.compare(root->name) == 0) {
        return "" + root->name;;
    }
    return getPath(item->parent) + "/" + item->name;
}

std::shared_ptr<FileItem> Tree::getRoot() {
    return root;
}

void Tree::insert(std::string name, short type, std::string parent) {
    
    /// if the tree is empty
    if (root == nullptr) {
        root = std::make_shared<FileItem>(name, type);
        root->parent = nullptr;
        return;
    }
    
    std::stack<std::shared_ptr<FileItem>> q;
    q.push(root);
    
    // Depth First Traversal
    while (!q.empty()) {
        // Dequeue an item from queue and print it
        std::shared_ptr<FileItem> item = q.top();
        q.pop();
        
        if (parent.compare(item->name) == 0) {
            std::shared_ptr<FileItem> add = std::make_shared<FileItem>(name, type);
            add->parent = item;
            
            item->children.push_back(add);
            return;
        }
        
        // Enqueue all children of the dequeued item
        for (int i = 0; i < item->children.size(); i++) {
            q.push(item->children[i]);
        }
    }
}

Tree::~Tree() { }


