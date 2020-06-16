//
//  ParallaxBackground.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <iostream>
#include <memory>
#include <cassert>

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <cmath>

struct Layer {
private:
    std::shared_ptr<sf::Texture> image;
    std::shared_ptr<sf::View> camera;
    
    /* the speed at which each sprite moves respective to the camera */
    float factor;
    
    /* the dimensions of the texture */
    int xDim, yDim;
    
    int xOffset;
    
public:
    sf::Sprite sprite;
    
    Layer(std::string path, sf::Vector2f position, float factor, std::shared_ptr<sf::View> camera) {
        this->camera = camera;
        xOffset = 0;
        image = std::make_shared<sf::Texture>();
        image->loadFromFile(path);
        
        /* this repeats the texture horizontally */
        image->setRepeated(true);
        sprite.setTexture(*image);
        
        xDim = sprite.getTextureRect().width;
        yDim = sprite.getTextureRect().height;
        
//        /* scale the background so that it fits the view */
//        sprite.setScale(camera->getSize().x / sprite.getTextureRect().width * 1.6f,
//                        camera->getSize().y / sprite.getTextureRect().height);
        
        
        sprite.setTextureRect(sf::IntRect(0, 0, xDim, yDim));
        sprite.setPosition(position);
        
        this->factor = factor;
    }
    
    void update(const sf::Time& dt, const float& cameraMove) {
        xOffset += cameraMove;
        if (abs(xOffset) >= camera->getSize().x) {
            xDim += xOffset / 100.f * factor;
            sprite.setTextureRect(sf::IntRect(0, 0, xDim, yDim));
            xOffset = 0;
        }
        sprite.move(cameraMove * factor * dt.asSeconds(), 0);
    }
    
    /* This is mostly used by the VIEW */
    int getOffset() {
        return xOffset;
    }
    
    /* This is mostly used by the VIEW */
    sf::Vector2f getDimension() {
        
        /* returns the dimensions of the texture */
        return sf::Vector2f(xDim, yDim);
    }
};

typedef std::vector<std::shared_ptr<Layer>> Layers;

class ParallaxBackground {
private:
    Layers layers;
    std::shared_ptr<sf::View> camera;
    
public:
    void update(const sf::Time& dt, const float& cameraMove);
    void draw(const std::shared_ptr<sf::RenderWindow>& target);
    
    /** \brief adds another layer to the parallax background
     *         when you add a new layer it gets pushed further back
     *         on the background
     */
    void addLayer(const std::string path, const sf::Vector2f& position, float factor);
    void addCamera(const std::shared_ptr<sf::View> camera);
    
    /* Getters */
    sf::View getCamera();
    Layers getLayers();
    
    ParallaxBackground();
    ParallaxBackground(std::shared_ptr<sf::View> camera);
    ~ParallaxBackground();
};
