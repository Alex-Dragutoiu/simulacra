//
//  ECS.h
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 02/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include "entities/EntityDAO.hpp"
#include "components/Component.hpp"
#include "systems/Systems.h"

namespace ECS {

    class Component;
    class EntityDAO;
    class System;
    
    class ECSManager : public sf::NonCopyable {
    public:
        ECSManager() {
            entityDAO = std::make_unique<EntityDAOImpl>();
        }
        
        inline Entity& addEntity(EntityID entityID) {
            return entityDAO->add(entityID);
        }
        
        inline std::shared_ptr<Entity> getEntity(EntityID entityID) {
            return entityDAO->get(entityID);
        }
        
        inline void delEntity(EntityID entityID) {
            entityDAO->del(entityID);
        }
        
        inline EntityList getAllEntities() {
            return entityDAO->getAll();
        }
        
        template <typename T, typename... TArgs>
        inline std::shared_ptr<T> addComponent(EntityID entityID, TArgs&&... args) {
            static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
            
            assert(entityDAO->get(entityID) != nullptr && "Entity already exists");
            infoLog("Added Component to Entity", entityID);
            
            return entityDAO->get(entityID)->addComponent<T>(std::forward<TArgs>(args)...);
        };
        
        template <typename T>
        inline std::shared_ptr<T> getComponent(EntityID entityID) {
            static_assert(std::is_base_of<Component, T>::value, "T must derive from Component!");
            return entityDAO->get(entityID)->getComponent<T>();
        };
        
        template <typename T>
        inline bool delComponent(EntityID entityID) {
            static_assert(std::is_base_of<Component, T>::value, "T must derive from Component!");
            infoLog("Deleted Component from Entity", entityID);
            return entityDAO->get(entityID)->delComponent<T>();
        }
        
        template <typename T>
        inline constexpr bool hasComponent(EntityID entityID) const {
            return entityDAO->get(entityID)->hasComponent<T>();
        }
        
        template <typename T>
        void addUpdateSystem() {
            static_assert(std::is_base_of<UpdateSystem, T>::value, "T must derive from System");
            EntityList list = entityDAO->getAll();
            std::unique_ptr<UpdateSystem> sys(new T(list));
    
            updateSystems.emplace_back(std::move(sys));
        }
        
        template <typename T>
        void addDrawSystem() {
            static_assert(std::is_base_of<DrawSystem, T>::value, "T must derive from System");
            EntityList list = entityDAO->getAll();
            std::unique_ptr<DrawSystem> sys(new T(list));
            drawSystems.emplace_back(std::move(sys));
        }
        
        void draw(sf::RenderTarget& target) const {
            for (auto& drawSys : drawSystems) {
                drawSys->draw(target);
            }
        }
        
        void update(const float& dt) {
            for (auto& updateSys : updateSystems) {
                updateSys->update(dt);
            }
        }

    private:
        std::unique_ptr<EntityDAOImpl> entityDAO;

        std::vector<std::unique_ptr<DrawSystem>> drawSystems;
        std::vector<std::unique_ptr<UpdateSystem>> updateSystems;
    };
}
