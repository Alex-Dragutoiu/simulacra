//
//  RenderSystem.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 05/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include "System.hpp"

namespace ECS {
    class RenderSystem : public DrawSystem {
    public:
        RenderSystem(const EntityList& list);
        virtual void draw(sf::RenderTarget& target) override;
    };
}
