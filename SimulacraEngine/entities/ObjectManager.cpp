//
//  ObjectManager.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 19/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "ObjectManager.hpp"

namespace simulacra {
    
    inline ObjectID ObjectManager::generateUniqueID() {
        static ObjectID lastID;
        
        return lastID++;
    }
    
    GameObject& ObjectManager::addObject() {
        GameObject* obj{new GameObject{}};
        std::unique_ptr<GameObject> objPtr(obj);
        objects.insert(std::make_pair(generateUniqueID(), std::move(objPtr)));
        
        return *obj;
    }
    
    void ObjectManager::draw(sf::RenderTarget& target) {
        for (auto& obj : objects) {
            obj.second->draw(target);
        }
    }
    
    void ObjectManager::update(const sf::Time& dt) {
    
        /* erases the inactive game objects from the vector */
        for (auto& obj : objects) {
            if (!obj.second->isAlive()) {
                objects.erase(obj.first);
            }
        }
        
        for (auto& obj : objects) {
            obj.second->update(dt);
        }
    }
}
