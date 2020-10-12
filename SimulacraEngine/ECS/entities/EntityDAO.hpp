//
//  EntityDAO.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 04/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include "Entity.hpp"

namespace ECS {
    
    class EntityDAO {
    public:
        virtual ~EntityDAO() { }
        
        virtual std::shared_ptr<Entity> get(EntityID id) = 0;
        virtual Entity& add(EntityID id) = 0;
        virtual void del(EntityID id) = 0;
        virtual EntityList getAll() = 0;
    };
    
    class EntityDAOImpl : EntityDAO {
    public:
        EntityDAOImpl();
        ~EntityDAOImpl() = default;
        
        /**
         * Get the Entity based on its id
         * @param id the id associated with the class
         * @return a pointer to the requested entity
         */
        std::shared_ptr<Entity> get(EntityID id) override;
        
        /**
         * Add an Entity with an associated id
         * @param id the id specified for the class
         * @return a reference to the newly created entity
         */
        Entity& add(EntityID id) override;
        
        /**
         * Delete an Entity based on its id
         * @param id the id associated with the class
         */
        void del(EntityID id) override;
        EntityList getAll() override;
        
        /**
         * Get all the entities with component T
         * @param T the Component
         * @return the list of all entities that have component T
         */
        template <typename T>
        EntityList withAll();
        
    private:
        
        /* holds the existing entities inside the game */
        EntityList entities;
    };

    template <typename T>
    EntityList EntityDAOImpl::withAll() {
        EntityList entitiesWithCompT;
        for (auto& entity : entities) {
            if (entity->hasComponent<T>()) {
                entitiesWithCompT.push_back(entity);
            }
        }
        return entitiesWithCompT;
    }
}



