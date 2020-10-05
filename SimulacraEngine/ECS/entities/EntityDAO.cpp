//
//  EntityDAO.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 04/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "EntityDAO.hpp"

namespace ECS {
    EntityDAOImpl::EntityDAOImpl() {
    }
    
    std::shared_ptr<Entity> EntityDAOImpl::get(EntityID id) {
        assert(id < MAX_ENTITIES && id >= 0);
        return entities[id];
    }

    Entity& EntityDAOImpl::add(EntityID id) {
        assert(id < MAX_ENTITIES && id >= 0);
        std::shared_ptr<Entity> ent = std::make_shared<Entity>(id);
        entities.emplace(entities.begin() + id, ent);
        return *ent;
    }
    
    void EntityDAOImpl::del(EntityID id) {
        assert(id < MAX_ENTITIES && id >= 0);
        entities[id] = nullptr;
    }
    
    EntityList EntityDAOImpl::getAll()  {
        return entities;
    }
}

