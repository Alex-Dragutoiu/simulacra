//
//  AnimationSystem.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 05/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "AnimationSystem.hpp"

namespace ECS {
    
    AnimationSystem::AnimationSystem(const EntityList& list) : UpdateSystem(list) { }
    
    void AnimationSystem::update(const float& dt) {
        for (auto& entity : entities) {
            if (entity->hasComponent<SpriteComponent>() && entity->hasComponent<AnimationComponent>()) {
                auto spriteComp = entity->getComponent<SpriteComponent>();
                auto animComp = entity->getComponent<AnimationComponent>();
                
                spriteComp->texture = *animComp->getAnimation("IDLE").getAnimSheet();
                spriteComp->m_sprite.setTexture(spriteComp->texture);
                spriteComp->m_sprite.setTextureRect(animComp->getAnimation("IDLE").play(dt));
            }
            
            //        isPlayingAnim = true;
            //        auto& animation = getAnimation(action);
            //        elapsedTime += dt.asSeconds();
            //        if (elapsedTime >= delay) {
            //            elapsedTime = 0;
            //        }
            //        if (animation.getRect().left == animation.getTexture()->getSize().x - 200) {
            //            isPlayingAnim = false;
            //        }
        }
    }
}
