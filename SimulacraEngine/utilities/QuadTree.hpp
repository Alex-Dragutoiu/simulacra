//
//  QuadTree.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 27/08/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../Utils.h"

namespace simulacra {
    
    struct Point {
    private:
        sf::Vector2f point;
        int id;
        
    public:
        int getID() {
            return id;
        }
        
        int generateUniqueID() {
            static int count = 0;
            
            return count++;
        }
        
        Point() : point(0, 0), id(generateUniqueID()) {
            
        }
        
        Point(sf::Vector2f point) : point(point), id(generateUniqueID()) {
            
        }
        
        Point(float x, float y) : point(x, y), id(generateUniqueID()) {
            
        }
        
        ~Point() { }
        
        void draw(sf::RenderTarget& target) {
            sf::CircleShape point;
        
            point.setPosition(this->point.x, this->point.y);
            point.setRadius(2.5f);
            point.setFillColor(sf::Color::Black);
            
            target.draw(point);
        }
        
        sf::Vector2f getPoint() {
            return point;
        }
    };

    
    template <typename T>
    class QuadTree {
    public:
        enum Quadrant {
            THIS = -1,
            NW = 0,
            NE = 1,
            SW = 2,
            SE = 3,
        };
        
        QuadTree();
        QuadTree(sf::FloatRect boundary, int capacity);
        ~QuadTree();
        
        const sf::FloatRect& getBoundary();
        int getCapacity();
        
        // splits the quadrant in 4 smaller quadrants
        void subdivide();
        
        bool insert(T object);
        void clear();
        std::vector<T> getObjects();
        std::vector<T> queryRange(const sf::FloatRect& range);
    
        // helper function that displays the quad tree and the objects inside each region
        void draw(sf::RenderTarget& target);
        
        int getQuadrant(Point obj);
        
    private:
        /* the number of objects that can be situated within the boundary before dividing */
        int capacity;
        
        /* a flag that tells whether the space was divided or not */
        bool divided;
        
        /* the space within which the objects are located */
        sf::FloatRect boundary;
        
        std::shared_ptr<QuadTree<T>> children[4];
        
        /* number of existing objects within the boundary */
        std::vector<T> objects;
    };
    
    template <typename T>
    QuadTree<T>::QuadTree() : boundary({0, 0, 1920, 1080}), capacity(1), divided(false) {
        
    }
    template <typename T>
    QuadTree<T>::QuadTree(sf::FloatRect boundary, int capacity) : boundary(boundary), capacity(capacity), divided(false) {
        for (int i = 0; i < 4; i++) {
            children[i] = nullptr;
        }
    }
    
    template <typename T>
    QuadTree<T>::~QuadTree() {
        
    }
    
    // splits the quadrant in 4 smaller quadrants
    template <typename T>
    void QuadTree<T>::subdivide() {
        const auto childWidth = boundary.width / 2.f;
        const auto childHeight = boundary.height / 2.f;
        
        children[NW] = std::make_shared<QuadTree>(sf::FloatRect(boundary.left, boundary.top, childWidth, childHeight), capacity);
        children[NE] = std::make_shared<QuadTree>(sf::FloatRect(boundary.left + childWidth, boundary.top, childWidth, childHeight), capacity);
        children[SW] = std::make_shared<QuadTree>(sf::FloatRect(boundary.left, boundary.top + childHeight, childWidth, childHeight), capacity);
        children[SE] = std::make_shared<QuadTree>(sf::FloatRect(boundary.left + childWidth, boundary.top + childHeight, childWidth, childHeight), capacity);
        divided = true;
    }
    template <typename T>
    const sf::FloatRect& QuadTree<T>::getBoundary() {
        return boundary;
    }
    
    template <typename T>
    bool QuadTree<T>::insert(T object) {
        for (auto obj : objects) {
            if (obj.getPoint().x == object.getPoint().x && obj.getPoint().y == object.getPoint().y) {
                return false;
            }
        }
        
        if (!boundary.contains(object.getPoint())) {
            return false;
        }
        
        if (divided) {
            for (int index = 0; index < 4; index++) {
                if (children[index]->insert(object)) { return true; }
            }
        }
        
        objects.push_back(object);
        
        if (objects.size() > capacity && !divided) {
            subdivide();
            for (auto it = objects.begin(); it != objects.end(); it++) {
                auto obj = *it;
                for (int index = 0; index < 4; index++) {
                    if (children[index]->insert(obj)) {
                        objects.clear();
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    template <typename T>
    void QuadTree<T>::clear() {
        objects.clear();
        for (int i = 0; i < 4; i++) {
            if (divided) {
                children[i]->clear();
                children[i] = nullptr;
            }
        }
    }
    
    template <typename T>
    std::vector<T> QuadTree<T>::queryRange(const sf::FloatRect& range) {
        std::vector<T> neighbours;
        
        if (!boundary.intersects(range)) {
            return neighbours; // empty vector
        }
        
        for (auto& object : objects) {
            if (range.contains(object.getPoint())) {
                neighbours.push_back(object);
            }
        }
        
        if (!divided) {
            return neighbours;
        }
        
        for (int i = 0; i < 4; i++) {
            std::vector<T> v = children[i]->queryRange(range);
            neighbours.insert(neighbours.end(), v.begin(), v.end());
        }
        
        return neighbours;
    }
    
    template <typename T>
    std::vector<T> QuadTree<T>::getObjects() {
        return objects;
    }
    
    template <typename T>
    int QuadTree<T>::getQuadrant(Point obj) {
        int index = THIS;
        
        auto verticalDividingLine = boundary.left + boundary.width * .5f;
        auto horizontalDividingLine = boundary.top + boundary.height * .5f;
        
        bool north = obj.getPoint().y < horizontalDividingLine;
        bool south =  obj.getPoint().y > horizontalDividingLine;
        bool west = obj.getPoint().x < verticalDividingLine;
        bool east = obj.getPoint().x > verticalDividingLine;
        
        if(east) {
            if(north) {
                index = NE;
            } else if(south) {
                index = SE;
            }
        } else if(west) {
            if(north) {
                index = NW;
            } else if(south) {
                index = SW;
            }
        }
        
        return index;
    }
    template <typename T>
    void QuadTree<T>::draw(sf::RenderTarget& target) {
        target.draw(rectangle(boundary.left, boundary.top, boundary.width, boundary.height, sf::Color::Red));
        
        if (divided) {
            for (int i = 0; i < 4; i++) {
                children[i]->draw(target);
            }
        }
        
        for (auto& object : objects) {
            object.draw(target);
            
        }
    }
}
    
