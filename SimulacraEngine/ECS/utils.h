//
//  utils.h
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 03/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

namespace ECS {
    
    class Entity;
    class Component;
    class System;
    
    using ComponentTypeID = std::size_t;
    using ID = std::uint32_t;
    
    const std::uint32_t MAX_COMPONENTS = 10;
    const std::uint32_t MAX_ENTITIES = 10000;
    
    using EntityID = std::uint32_t;
    using EntityList = std::vector<std::shared_ptr<Entity>>;
    using Signature = std::bitset<MAX_COMPONENTS>;
    
    enum class Action {
        NONE,
        IDLE,
        IDLE_LEFT,
        IDLE_RIGHT,
        LEFT,
        RIGHT,
        ATTACK_RIGHT,
    };
    
    inline ComponentTypeID getUniqueComponentID() {
        static ComponentTypeID lastID = 0;
        return lastID++;
    }
        
    template <typename T>
    inline ComponentTypeID getComponentTypeID() noexcept {
        static_assert(std::is_base_of<Component, T>::value, "T does not derive from Component!");
        static const ComponentTypeID typeID = getUniqueComponentID();
        return typeID;
    }
}
