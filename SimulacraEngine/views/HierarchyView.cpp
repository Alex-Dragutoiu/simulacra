//
//  HierarchyView.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#include "HierarchyView.hpp"

HierarchyView::HierarchyView() { }

HierarchyView::~HierarchyView() { }

void HierarchyView::drawListOfObjectsToAdd() {
    ImGui::BeginChild("AddObjects", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()), true);
    
    ImGui::EndChild();
    
    ImGui::Button("Add");
}

void HierarchyView::drawHierarchy() {
    ImGui::BeginChild("states", ImVec2(0, 600), true);
    
    
    //    if (ImGui::TreeNode("Grid")) {
    //        for (int i = 0; i < 4 * 4; i++) {
    //            ImGui::PushID(i);
    //            if (ImGui::Selectable("A", selected[i] != 0, 0, ImVec2(30, 30))) {
    //                // Toggle
    //                selected[i] = !selected[i];
    //            }
    //            if ((i % 4) < 3) ImGui::SameLine();
    //            ImGui::PopID();
    //        }
    //        ImGui::TreePop();
    //    }
    
    
    ImGui::EndChild();
}

void HierarchyView::draw() {
    bool open = true;
    ImGui::Begin("hierarchy", &open);
        ImGui::SetWindowFontScale(2.f);
    
        drawHierarchy();
    
        //    ImGui::Text("Add Objects to Hierarchy");
        //    drawListOfObjectsToAdd();
    ImGui::End();
}

//if (ImGui::TreeNode("Drag and Drop")) {
//    if (ImGui::TreeNode("Drag and drop to copy/swap items")) {
//        enum Mode {
//            Mode_Copy,
//            Mode_Move,
//            Mode_Swap
//        };
//
//        if (ImGui::RadioButton("Copy", mode == Mode_Copy)) { mode = Mode_Copy; } ImGui::SameLine();
//        if (ImGui::RadioButton("Move", mode == Mode_Move)) { mode = Mode_Move; } ImGui::SameLine();
//        if (ImGui::RadioButton("Swap", mode == Mode_Swap)) { mode = Mode_Swap; }
//        for (int n = 0; n < IM_ARRAYSIZE(names); n++) {
//            ImGui::PushID(n);
//            if ((n % 3) != 0)
//                ImGui::SameLine();
//            ImGui::Button(names[n], ImVec2(60,60));
//
//            // Our buttons are both drag sources and drag targets here!
//            if (ImGui::BeginDragDropSource(ImGuiDragDropFlags_None)) {
//                // Set payload to carry the index of our item (could be anything)
//                ImGui::SetDragDropPayload("DND_DEMO_CELL", &n, sizeof(int));
//
//                // Display preview (could be anything, e.g. when dragging an image we could decide to display
//                // the filename and a small preview of the image, etc.)
//                if (mode == Mode_Copy) { ImGui::Text("Copy %s", names[n]); }
//                if (mode == Mode_Move) { ImGui::Text("Move %s", names[n]); }
//                if (mode == Mode_Swap) { ImGui::Text("Swap %s", names[n]); }
//                ImGui::EndDragDropSource();
//            }
//            if (ImGui::BeginDragDropTarget()) {
//                if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("DND_DEMO_CELL")) {
//                    IM_ASSERT(payload->DataSize == sizeof(int));
//                    int payload_n = *(const int*)payload->Data;
//                    if (mode == Mode_Copy) {
//                        names[n] = names[payload_n];
//                    }
//                    if (mode == Mode_Move) {
//                        names[n] = names[payload_n];
//                        names[payload_n] = "";
//                    }
//                    if (mode == Mode_Swap) {
//                        const char* tmp = names[n];
//                        names[n] = names[payload_n];
//                        names[payload_n] = tmp;
//                    }
//                }
//                ImGui::EndDragDropTarget();
//            }
//            ImGui::PopID();
//        }
//        ImGui::TreePop();
//    }
//
//    if (ImGui::TreeNode("Drag to reorder items (simple)")) {
//        static const char* item_names[] = { "Item One", "Item Two", "Item Three", "Item Four", "Item Five" };
//        for (int n = 0; n < IM_ARRAYSIZE(item_names); n++) {
//            const char* item = item_names[n];
//            ImGui::Selectable(item);
//
//            if (ImGui::IsItemActive() && !ImGui::IsItemHovered()) {
//                int n_next = n + (ImGui::GetMouseDragDelta(0).y < 0.f ? -1 : 1);
//                if (n_next >= 0 && n_next < IM_ARRAYSIZE(item_names)) {
//                    item_names[n] = item_names[n_next];
//                    item_names[n_next] = item;
//                    ImGui::ResetMouseDragDelta();
//                }
//            }
//        }
//        ImGui::TreePop();
//    }
//    ImGui::TreePop();
//}
