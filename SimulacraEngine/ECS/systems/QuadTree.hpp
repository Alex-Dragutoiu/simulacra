//
//  QuadTree.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <SFML/Graphics.hpp>

#include "../components/Component.hpp"

namespace ECS {

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
        QuadTree(const sf::FloatRect& boundary, const int& capacity);
        ~QuadTree();
        
        const sf::FloatRect& getBoundary() const;
        int getCapacity();
        
        // splits the quadrant in 4 smaller quadrants
        void subdivide();
        
        bool insert(std::shared_ptr<ColliderComponent> object);
        void clear();
        
        std::vector<std::shared_ptr<ColliderComponent>> search(const sf::FloatRect& range);
        void search(const sf::FloatRect& area, std::vector<std::shared_ptr<ColliderComponent>>& overlappingObjects);
        
        int getChildIndexForObject(const sf::FloatRect& objectBounds);
        
    private:
        /* the number of objects that can be situated within the boundary before dividing */
        int capacity;
        
        /* a flag that tells whether the space was divided or not */
        bool divided;
        
        /* the space within which the objects are located */
        sf::FloatRect boundary;
        
        std::shared_ptr<QuadTree> children[4];
        
        /* number of existing objects within the boundary */
        std::vector<std::shared_ptr<ColliderComponent>> objects;
    };
}
