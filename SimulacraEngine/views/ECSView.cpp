//
//  ECSView.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 08/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "ECSView.hpp"

namespace simulacra {
    ECSView::ECSView(ECS::ECSManager& manager) : manager(manager) {
        selected = 0;
    }
    
    void ECSView::draw(bool isOpen) {
        /* Transparent background */
        ImGui::SetNextWindowBgAlpha(0.8f);
        
        ImGui::Begin("Entities", &isOpen);
        ImGui::SetWindowFontScale(2.f);
            drawLeftPanel();
            ImGui::SameLine();
            drawRightPanel();
        ImGui::End();
    }
    
    void ECSView::drawLeftPanel() {
        ImGui::BeginGroup();
            ImGui::Text("Hierarchy");
            ImGui::BeginChild("left pane", ImVec2(20 * 16, -ImGui::GetFrameHeightWithSpacing()), true);
                for (auto& entity : manager.getAllEntities()) {
                    std::string text = "Entity " + std::to_string(entity->getInstanceID());
                    if (ImGui::Selectable(text.c_str(), selected == entity->getInstanceID())) {
                        selected = entity->getInstanceID();
                    }
                }
            ImGui::EndChild();
    
            if (ImGui::Button("Add")) {
                std::queue<ECS::EntityID> ids = manager.getAvailableIDs();
                manager.addEntity(ids.front());
            }
        
        ImGui::EndGroup();
    }
    
    void ECSView::drawRightPanel() {
        
        auto entity = manager.getEntity(selected);
    
        ImGui::BeginGroup();
            ImGui::Text("Components");
            /* Leave room for 1line below us */
            ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()), true);
        //        ImGui::PushStyleColor(ImGuiCol_Text, DARK);
                ImGui::Text("Entity %d", entity->getInstanceID());
        //        ImGui::PopStyleColor();
                ImGui::Separator();
                if (entity->hasComponent<ECS::TransformationComponent>()) {
                    if (ImGui::CollapsingHeader("Transformation")) {
                        ImGui::InputFloat("x##", &entity->getComponent<ECS::TransformationComponent>()->position.x, 1.f, 2000.f, "%.2f");
                        ImGui::InputFloat("y##", &entity->getComponent<ECS::TransformationComponent>()->position.y, 1.f, 2000.f, "%.2f");
                        ImGui::Separator();
                    }
                }
        
                if (entity->hasComponent<ECS::VelocityComponent>()) {
                    if (ImGui::CollapsingHeader("Velocity")) {
                        ImGui::InputFloat("velocity", &entity->getComponent<ECS::VelocityComponent>()->velocity, 1.f, 2000.f, "%.2f");
                        ImGui::Separator();
                    }
                }
        
                if (entity->hasComponent<ECS::ColliderComponent>()) {
                    if (ImGui::CollapsingHeader("Collider")) {
                        if (ImGui::Checkbox("draw", &entity->getComponent<ECS::ColliderComponent>()->isDrawable())) { }
                        
                        ImGui::InputFloat("x", &entity->getComponent<ECS::ColliderComponent>()->getCollidable().left, 1.f, 1000.f, "%.2f");
                        ImGui::InputFloat("y", &entity->getComponent<ECS::ColliderComponent>()->getCollidable().top, 1.f, 1000.f, "%.2f");
                        ImGui::Separator();
                        
                        ImGui::InputFloat("width", &entity->getComponent<ECS::ColliderComponent>()->getCollidable().width, 1.f, 800.f, "%.2f");
                        ImGui::InputFloat("height", &entity->getComponent<ECS::ColliderComponent>()->getCollidable().height, 1.f, 800.f, "%.2f");
                        ImGui::Separator();
                    }
                }
        
                if (entity->hasComponent<ECS::SpriteComponent>()) {
                    if (ImGui::CollapsingHeader("Sprite")) {
                        sf::IntRect textureDimensions = entity->getComponent<ECS::SpriteComponent>()->m_sprite.getTextureRect();
                        auto sprite = entity->getComponent<ECS::SpriteComponent>()->m_sprite;
                        ImGui::BeginChild("image", ImVec2(416.f, 416.f), true);
                            sprite.setScale(401.f / textureDimensions.width, 401.f / textureDimensions.height);
                            ImGui::Image(sprite);
                        ImGui::EndChild();
                    }
                }
            ImGui::EndChild();
            //        for (int i = 0; i < 10; i++) {
            //            if (ImGui::ImageButton(entity->getComponent<ECS::SpriteComponent>()->m_sprite, ImVec2(15, 15))) {
            //            }
            //        }

            if (ImGui::Button("Add")) { }
        
        ImGui::EndGroup();
    }
}



