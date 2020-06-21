//
//  FileSystemView.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 09/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#include "FileSystemView.hpp"

#define NONE ""

/* colours */
#define RED ImVec4(1.0f, 0.2f, 0.2f, 1.0f)
#define DARK ImVec4(0.80f, 0.80f, 0.83f, 0.31f)
#define DARK_GREEN ImVec4(0.07f, 0.22f, 0.14f, 0.99f)

FileSystemView::FileSystemView() {
    loadResourcePaths();
    itemCurrentIndex = flags = selected = 0;
    currentFile = resources.getRoot();
}

FileSystemView::~FileSystemView() { }

void FileSystemView::drawMenuBar() {
    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Open...", "Ctrl+O")) {
                
            }
            if (ImGui::MenuItem("Save", "Ctrl+S"))   {
                
            }
            if (ImGui::MenuItem("Close", "Ctrl+W"))  {
                
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
}



void FileSystemView::drawLeftPanel() {
    ImGui::BeginGroup();
    ImGui::BeginChild("left pane", ImVec2(20 * 16, -ImGui::GetFrameHeightWithSpacing()), true);
    for (int i = 0; i < currentFile->children.size(); i++) {
        if (currentFile->children[i]->type == DT_DIR) {
            ImGui::PushStyleColor(ImGuiCol_Text, DARK_GREEN);
            if (ImGui::Selectable(currentFile->children[i]->name.c_str(), selected == i, ImGuiSelectableFlags_AllowDoubleClick)) {
                selected = i;
                if (ImGui::IsMouseDoubleClicked(0)) {
                    /* change the current directory to the selected child directory */
                    currentFile = currentFile->children[i];
                    selected = 0;
                }
            }
            ImGui::PopStyleColor();
        } else {
            if (ImGui::Selectable(currentFile->children[i]->name.c_str(), selected == i)) {
                selected = i;
            }
        }
    }
    ImGui::EndChild();
    
    if (ImGui::Button("Back") && currentFile->hasParent()) {
        currentFile = currentFile->parent;
        comboLabel = currentFile->name.c_str();
        selected = 0;
    }
    
    ImGui::EndGroup();
}

void FileSystemView::drawRightPanel() {
    sf::Sprite workingSprite;
    
    if (currentFile->children[selected]->type != DT_DIR) {
        if (!tex.loadFromFile(resources.getPath(currentFile->children[selected]))) {
            std::cout << "[ERROR]: couldn't load texture from file '" << currentFile->children[selected]->getName() << "'" << std::endl;
        }
    }
    
    workingSprite.setTexture(tex);
    textureDimensions = workingSprite.getTextureRect();
    
    ImGui::BeginGroup();
    /* Leave room for 1line below us */
    ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()), true);
    ImGui::PushStyleColor(ImGuiCol_Text, DARK);
    ImGui::Text("path: %s", resources.getPath(currentFile->children[selected]).c_str());
    ImGui::PopStyleColor();
    ImGui::Separator();
    
    if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_None)) {
        if (!isDir(*currentFile->children[selected])) {
            if (ImGui::BeginTabItem("Preview")) {
                
                ImGui::BeginChild("image", ImVec2(416.f, 416.f), true);
                workingSprite.setScale(400.f / textureDimensions.width, 400.f / textureDimensions.height);
                ImGui::Image(workingSprite);
                ImGui::EndChild();
                
                ImGui::Text("Image Dimensions: %i x %i", textureDimensions.width, textureDimensions.height);
                
                ImGui::EndTabItem();
            }
        }
        
        /* This tab is display only for selected directories */
        if (isDir(*currentFile->children[selected])) {
            if (ImGui::BeginTabItem("Details")) {
                for (int i = 0; i < currentFile->children[selected]->children.size(); i++) {
                    ImGui::BulletText("%s", currentFile->children[selected]->children[i]->name.c_str());
                }
                ImGui::EndTabItem();
            }
        }
        
        
        if (!isDir(*currentFile->children[selected]) && ImGui::BeginTabItem("Edit")) {
            ImGui::PushItemWidth(300);
            
            if (ImGui::InputInt("width", &height)) {
                
            }
            
            if (ImGui::InputInt("height", &width)) {
                
            }
            
            ImGui::PopItemWidth();
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }
    
    ImGui::EndChild();
    
    if (ImGui::Button("Load")) { }
    
    ImGui::SameLine();
    
    if (ImGui::Button("Save")) { }
    
    ImGui::EndGroup();
}

void FileSystemView::draw() {
    bool open = true;
    
    ImGui::Begin("Assets", &open, ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowFontScale(2.f);
    
    drawMenuBar();
    
    ImGui::Text("Directory: ");
    ImGui::SameLine();
    
    ImGui::PushStyleColor(ImGuiCol_Text, DARK);
    ImGui::Text("%s", currentFile->name.c_str());
    ImGui::PopStyleColor();
    
    drawLeftPanel();
    ImGui::SameLine();
    drawRightPanel();
    ImGui::End();
}

/* ------------------------
 * | dirent.h MACROS      |
 * ------------------------
 * | DT_DIR => directory  |
 * | DT_REG => file       |
 * ------------------------
 *  This method loads the directories and files from root './res'
 * and adds them in a tree according to the system's hierarchy
 */
void FileSystemView::loadResourcePaths() {
    dirent* entry;
    DIR* dir;
    
    resources.insert("Resources", DT_DIR, NONE);
    
    std::stack<std::pair<std::string, std::string>> q;
    q.push(std::make_pair("Resources", "Resources/"));
    
    // Level order traversal.
    while (!q.empty()) {
        // Dequeue an item from queue and print it
        std::string item = q.top().first;
        std::string path = q.top().second;
        
        q.pop();
        
        if ((dir = opendir(path.c_str()))) {
            while ((entry = readdir(dir))) {
                std::string path_to_push = "";
                if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..") && strcmp(entry->d_name, ".DS_Store")) {
                    resources.insert(entry->d_name, entry->d_type, item.c_str());
                    if (entry->d_type == DT_DIR) {
                        path_to_push = path + static_cast<std::string>(entry->d_name) + "/";
                        q.push(std::make_pair(entry->d_name, path_to_push));
                    }
                }
            }
            closedir(dir);
        }
    }
}

bool FileSystemView::isDir(FileItem& file) const {
    return file.type == DT_DIR;
}


//                        {
//                            ImVec2 vMin = ImGui::GetWindowContentRegionMin();
//                            ImVec2 vMax = ImGui::GetWindowContentRegionMax();
//
//                            vMin.x += ImGui::GetWindowPos().x;
//                            vMin.y += ImGui::GetWindowPos().y;
//
//                            vMax.x += ImGui::GetWindowPos().x;
//                            vMax.y += ImGui::GetWindowPos().y;
//
//                            ImGui::GetForegroundDrawList()->AddRect(vMin, vMax, IM_COL32(179, 179, 179, 255));
//                        }
/* This is a combo that displays the current selected directory
 * you switch to the contents of other directories that are currently inside
 * the current selected directory
 */
//void FileSystemView::drawCombo() {
//    if (ImGui::BeginCombo("files", comboLabel, flags)) {
//        for (int i = 0; i < currentFile->children.size(); i++) {
//            if (currentFile->children[i]->type == DT_DIR) {
//                const bool is_selected = i;
//                if (ImGui::Selectable(currentFile->children[i]->name.c_str(), is_selected)) {
//                    itemCurrentIndex = i;
//                    comboLabel = currentFile->children[i]->name.c_str();
//                }
//
//                // Set the initial focus when opening the combo (scrolling + keyboardnavigation focus)
//                if (is_selected) {
//                    ImGui::SetItemDefaultFocus();
//                }
//            }
//        }
//        ImGui::EndCombo();
//    }
//}
