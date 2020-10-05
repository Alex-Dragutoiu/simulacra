//
//  RenderSystem.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 05/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "RenderSystem.hpp"

namespace ECS {
    RenderSystem::RenderSystem(const EntityList& list) : DrawSystem(list) { }
    
    void RenderSystem::draw(sf::RenderTarget& target) {
        for (auto& entity : entities) {
            if (entity->hasComponent<SpriteComponent>() && entity->hasComponent<TransformationComponent>()) {
                auto transComp = entity->getComponent<TransformationComponent>();
                auto spriteComp = entity->getComponent<SpriteComponent>();
                
                spriteComp->m_sprite.setPosition(transComp->position);
                spriteComp->m_sprite.setScale(transComp->scale);
                
                target.draw(spriteComp->m_sprite);
            }
        }
    }
}
