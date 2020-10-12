//
//  Entity.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 02/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include "../components/Component.hpp"
#include "../utils.h"

#include <array>
#include <queue>

namespace ECS {
    
    class Entity {
    public:
        
        // Entity destruction always happens through EntityDAO
        void operator delete(void*) = delete;
        void operator delete[](void*) = delete;
        
        Entity() { } 
        Entity(EntityID id);
        ~Entity();
        
    public:
        template <typename T, typename... TArgs>
        inline std::shared_ptr<T> addComponent(TArgs&&... args) {
            static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

            if (hasComponent<T>()) {
                return getComponent<T>();
            }
            
            // The object does not have this component so we create it and
            // add it to our list.
            std::shared_ptr<T> newComponent = std::make_shared<T>(this->getInstanceID(), std::forward<TArgs>(args)...);
            components[getComponentTypeID<T>()] = newComponent;
            compBitmask[getComponentTypeID<T>()] = true;
            
            newComponent->toString();
            
            return newComponent;
        };
        
        template <typename T>
        inline std::shared_ptr<T> getComponent() {
            static_assert(std::is_base_of<Component, T>::value, "T must derive from Component!");
            return std::dynamic_pointer_cast<T>(components[getComponentTypeID<T>()]);
        };
        
        template <typename T>
        inline bool delComponent() {
            static_assert(std::is_base_of<Component, T>::value, "T must derive from Component!");
            
            for (size_t i = 0; i < components.size(); ++i) {
                if (std::dynamic_pointer_cast<T>(components[i])) {
                    components[getComponentTypeID<T>()] = nullptr;
                    compBitmask[getComponentTypeID<T>()] = false;
                    std::cout << "Deleted Component " << typeid(T).name() << " of Entity " << getInstanceID() << std::endl;
                    return true;
                }
            }
            
            return false;
        }
        
        template <typename T>
        inline bool hasComponent() const {
            return compBitmask[getComponentTypeID<T>()];
        }
        
        EntityID getInstanceID();
        
        const Signature getSignature() const;
        
    private:
        std::string name;
        
        Signature compBitmask;
        std::array<std::shared_ptr<Component>, MAX_COMPONENTS> components;
        
        EntityID id;
    };
}

//            // Check that we don't already have a component of this type.
//            for (auto& component : components) {
//                // Currently we prevent adding the same component twice.
//                // This may be something we will change in future.
//                if (std::dynamic_pointer_cast<T>(component)) {
//                    return std::dynamic_pointer_cast<T>(component);
//                }
//            }
