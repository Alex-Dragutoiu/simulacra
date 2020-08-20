//
//  CameraComponent.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 07/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include "../Component.hpp"

#include "../TransformationComponent/TransformationComponent.hpp"

namespace simulacra {
    
    class CameraComponent : public Component {
    public:
        CameraComponent(GameObject* owner, std::shared_ptr<sf::View> camera);
        ~CameraComponent();

        void update(const sf::Time& dt) override;

        void setCamera(const std::shared_ptr<sf::View>& camera);

    private:
        std::shared_ptr<sf::View> camera;
        std::shared_ptr<TransformationComponent> transformation;
    };
}
