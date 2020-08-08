//
//  AnimationComponent.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 07/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include <SFML/Graphics.hpp>

#include "Animation.hpp"

#include "../Component.hpp"
#include "../SpriteComponent/SpriteComponent.hpp"

#include "../../enums.h"
#include "../../entities/GameObject.hpp"

#include <unordered_map>

namespace simulacra {
    class AnimationComponent : public Component {
    public:
        AnimationComponent(GameObject* owner, const double& delay);
        ~AnimationComponent();
        
        void addAnimation(Action action, sf::Texture* animation, const int& width, const int& height);
        Animation& getAnimation(Action action);
        
        bool isPlaying() {
            return isPlayingAnim;
        }
        
        void play(Action& action, const sf::Time& dt);
        void pause(Action action);
        void reset(Action action);
        
    private:
        double delay;
        double elapsedTime;
        
        bool isPlayingAnim;
        
        std::unordered_map<Action, std::unique_ptr<Animation>> animations;
        
        std::shared_ptr<SpriteComponent> sprite_c;
    };
}
