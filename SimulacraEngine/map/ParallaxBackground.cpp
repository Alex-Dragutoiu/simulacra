//
//  ParallaxBackground.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "ParallaxBackground.hpp"

ParallaxBackground::ParallaxBackground() { }

ParallaxBackground::ParallaxBackground(std::shared_ptr<sf::View> camera) {
    this->camera = camera;
}

ParallaxBackground::~ParallaxBackground() {
    while (!layers.empty()) {
        layers.pop_back();
    }
}

void ParallaxBackground::update(const sf::Time& dt, const float& cameraMove) {
    for (auto& layer : layers) {
        layer->update(dt, cameraMove);
    }
}

void ParallaxBackground::draw(const std::shared_ptr<sf::RenderWindow>& target) {
    for (auto& layer : layers) {
        target->draw(layer->sprite);
    }
}

Layers ParallaxBackground::getLayers() {
    return layers;
}

void ParallaxBackground::addLayer(const std::string path, const sf::Vector2f& position, float factor) {
    assert(camera != nullptr);
    layers.push_back(std::make_shared<Layer>(path, position, factor, camera));
}

sf::View ParallaxBackground::getCamera() {
    return *camera;
}

void ParallaxBackground::addCamera(const std::shared_ptr<sf::View> camera) {
    this->camera = camera;
}

