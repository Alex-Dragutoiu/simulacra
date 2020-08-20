//
//  ObjectManager.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 19/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include "GameObject.hpp"
#include <memory>

namespace simulacra {
    class ObjectManager : public sf::NonCopyable {
    public:
        ObjectManager() = default;
        ~ObjectManager() = default;
        
        GameObject& addObject();
        
        void update(const sf::Time& dt);
        void draw(sf::RenderTarget& target);
        
    private:
        inline ObjectID generateUniqueID();
        
    private:
        std::unordered_map<ObjectID, std::unique_ptr<GameObject>> objects;
    };
}
