//
//  GameObject.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 19/07/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>

#include "../components/Component.hpp"

namespace simulacra {
    
    class Component;
    
    using ObjectID = uint32_t;
    
    class GameObject {
    public:
        GameObject() { };
        
        virtual ~GameObject() { }
        
        template <typename T, typename... U>
        std::shared_ptr<T> addComponent(U... args) {
            static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
                          
            // Check that we don't already have a component of this type.
            for (auto& component : components) {
                // Currently we prevent adding the same component twice.
                // This may be something we will change in future.
                if (std::dynamic_pointer_cast<T>(component)) {
                        return std::dynamic_pointer_cast<T>(component);
                }
            }
                          
            // The object does not have this component so we create it and
            // add it to our list.
            std::shared_ptr<T> newComponent = std::make_shared<T>(this, args...);
            components.push_back(newComponent);
            
            return newComponent;
        };
        
        template <typename T>
        std::shared_ptr<T> getComponent() {
            static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
                                            
            // Check that we don't already have a component of this type.
            for (auto& component : components) {
                if (std::dynamic_pointer_cast<T>(component)) {
                    return std::dynamic_pointer_cast<T>(component);
                }
            }
                                            
            return nullptr;
        };
        
        virtual void update(const sf::Time& dt);
        virtual void draw(sf::RenderTarget& target);
        
        bool isAlive() const;
        void dispose();
        
        ObjectID getInstanceID();
        
    protected:
        std::vector<std::shared_ptr<Component>> components;
        
    private:
        ObjectID id;
        
        bool alive { true };
    };
}
