//
//  DebugView.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#include "DebugView.hpp"

DebugView::DebugView() : parallax(nullptr) { }

DebugView::DebugView(const ParallaxBackground& parallax) : parallax(parallax) { }

DebugView::~DebugView() { }

void DebugView::addModel(const ParallaxBackground &parallax) {
    this->parallax = parallax;
}

void DebugView::draw() {
    /* Transparent background */
    ImGui::SetNextWindowBgAlpha(0.8f);
    
    Layers layers = parallax.getLayers();
    
    /* begin the DEBUG overlay */
    if (ImGui::Begin("Debug")) {
        ImGui::SetWindowFontScale(2.f);
        ImGui::Text("Camera");
        ImGui::BulletText("Dimensions: X:%.2f, Y:%.2f", parallax.getCamera().getSize().x, parallax.getCamera().getSize().y);
        ImGui::BulletText("Center Position: X:%.2f, Y:%.2f", parallax.getCamera().getCenter().x, parallax.getCamera().getCenter().y);
        
        ImGui::Separator();
        
        for (int i = 0; i < layers.size(); i++) {
            ImGui::Text("Layer %d", i + 1);
            ImGui::BulletText("Dimensions: X:%2.f, Y:%2.f", layers[i]->getDimension().x, layers[i]->getDimension().y);
            ImGui::BulletText("Sprites Rendered: %.2f", layers[i]->getDimension().x / 384);
            
            ImGui::Separator();
        }
    }
    ImGui::End();
}

