//
//  CollisionSystem.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 07/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "CollisionSystem.hpp"

namespace ECS {
    
    CollisionSystem::CollisionSystem(const EntityList& list) : UpdateSystem(list), collidables() {
        collision = std::make_shared<QuadTree>();
    }
    
    void CollisionSystem::update(const float& dt) {
        collidables.clear();
    
        for (auto& entity : entities) {
            if (entity->hasComponent<ColliderComponent>() && entity->hasComponent<TransformationComponent>()) {
                collidables.push_back(entity);
            }
        }
        
        for (int i = 0; i < collidables.size(); ++i) {
            for (int j = 0; j < collidables.size(); ++j) {
                if (i != j) {
                    auto iColComp = collidables[i]->getComponent<ColliderComponent>();
                    auto iTransComp = collidables[i]->getComponent<TransformationComponent>();
                    
                    auto jColComp = collidables[j]->getComponent<ColliderComponent>();
                    
                    if (iColComp->intersects(jColComp)) {
                        sf::Vector2f resolve = iColComp->resolveOverlap(jColComp);
                        iColComp->move(resolve.x, resolve.y);
                        iTransComp->move(resolve.x, resolve.y);
                    }
                }
            }
        }
    }
}

//            auto collider = collidable->getComponent<ColliderComponent>();
//            auto transComp = collidable->getComponent<TransformationComponent>();
//
//            std::vector<std::shared_ptr<ColliderComponent>> neighbours = collision->search(collider->getCollidable());
//            std::cout << neighbours.empty() << std::endl;
//            for (auto& neighbour : neighbours) {
//                auto& collidable = neighbour->getCollidable();
//                std::cout << "neighbour: " << "x = " << collidable.left << ",y = " << collidable.top << std::endl;
//            }

//            for (auto& neighbour : neighbours) {
//                if (neighbour->intersects(collider)) {
//                    std::cout << "INTERACTED\n";
//                    sf::Vector2f resolve = collider->resolveOverlap(&*neighbour);
//                    transComp->move(resolve.x, resolve.y);
//                }
//            }s
