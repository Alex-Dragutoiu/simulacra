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
        
        std::shared_ptr<Entity> get(EntityID id) override;
        Entity& add(EntityID id) override;
        void del(EntityID id) override;
        EntityList getAll() override;
        
    private:
        EntityList entities;
    };
}



