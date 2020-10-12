//
//  QuadTree.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "QuadTree.hpp"

namespace ECS {
    QuadTree::QuadTree() : boundary({0, 0, 1920, 1080}), capacity(1), divided(false) {
        
    }
    
    QuadTree::QuadTree(const sf::FloatRect& boundary, const int& capacity) : boundary(boundary), capacity(capacity), divided(false) {
        for (int i = 0; i < 4; i++) {
            children[i] = nullptr;
        }
    }
    
    QuadTree::~QuadTree() { clear(); }
    
    // splits the quadrant in 4 smaller quadrants
    void QuadTree::subdivide() {
        const auto childWidth = boundary.width / 2.f;
        const auto childHeight = boundary.height / 2.f;
        
        children[NW] = std::make_shared<QuadTree>(sf::FloatRect(boundary.left, boundary.top, childWidth, childHeight), capacity);
        children[NE] = std::make_shared<QuadTree>(sf::FloatRect(boundary.left + childWidth, boundary.top, childWidth, childHeight), capacity);
        children[SW] = std::make_shared<QuadTree>(sf::FloatRect(boundary.left, boundary.top + childHeight, childWidth, childHeight), capacity);
        children[SE] = std::make_shared<QuadTree>(sf::FloatRect(boundary.left + childWidth, boundary.top + childHeight, childWidth, childHeight), capacity);
        divided = true;
    }
    
    const sf::FloatRect& QuadTree::getBoundary() const {
        return boundary;
    }

    bool QuadTree::insert(std::shared_ptr<ColliderComponent> object) {
        if (!boundary.contains(sf::Vector2f { object->getCollidable().left, object->getCollidable().top } )) {
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
    
    void QuadTree::clear() {
        objects.clear();
        for (int i = 0; i < 4; i++) {
            if (divided) {
                children[i]->clear();
                children[i] = nullptr;
            }
        }
    }
    
    std::vector<std::shared_ptr<ColliderComponent>> QuadTree::search(const sf::FloatRect& range) {
        std::vector<std::shared_ptr<ColliderComponent>> possibleOverlaps;
        search(range, possibleOverlaps);
        
        std::vector<std::shared_ptr<ColliderComponent>> returnList;
        
        for (auto collider : possibleOverlaps) {
            if (range.intersects(collider->getCollidable())) {
                returnList.emplace_back(collider);
            }
        }
        
        return returnList;
    }
    
    void QuadTree::search(const sf::FloatRect& area, std::vector<std::shared_ptr<ColliderComponent>>& overlappingObjects) {
        overlappingObjects.insert(overlappingObjects.end(), objects.begin(), objects.end()); // 1
        
        if(divided) {
            int index = getChildIndexForObject(area);
            
            if(index == THIS) {
                for(int i = 0; i < 4; i++) {
                    auto& bound = children[i]->getBoundary();
                    if(bound.intersects(area)) {
                        children[i]->search(area, overlappingObjects);
                    }
                }
            } else {
                children[index]->search(area, overlappingObjects);
            }
        }
    }
    
    int QuadTree::getChildIndexForObject(const sf::FloatRect& objectBounds) {
        int index = THIS;
        
        double verticalDividingLine = boundary.left + boundary.width * 0.5f;
        double horizontalDividingLine = boundary.top + boundary.height * 0.5f;
        
        bool north = objectBounds.top < horizontalDividingLine
        && (objectBounds.height + objectBounds.top < horizontalDividingLine);
        bool south = objectBounds.top > horizontalDividingLine;
        bool west = objectBounds.left < verticalDividingLine
        && (objectBounds.left + objectBounds.width < verticalDividingLine);
        bool east = objectBounds.left > verticalDividingLine;
        
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
}

//        std::vector<std::shared_ptr<ColliderComponent>> neighbours;
//
//        if (!boundary.intersects(range)) {
//            return neighbours; // empty vector
//        }
//
//        for (auto& object : objects) {
//            if (range.contains(sf::Vector2f { object->getCollidable().left, object->getCollidable().top })) {
//                neighbours.push_back(object);
//            }
//        }
//
//        if (!divided) {
//            return neighbours;
//        }
//
//        for (int i = 0; i < 4; i++) {
//            for (auto& val : children[i]->search(range)) {
//                neighbours.push_back(val);
//            }
//        }
//
//        //            neighbours.insert(neighbours.end(), v.begin(), v.end());
//        return neighbours;
