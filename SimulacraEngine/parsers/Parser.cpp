//
//  Parser.cpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 10/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#include "Parser.hpp"

#define CHECK_KEY(key, parent) if (key == parent->end()) throw std::runtime_error("key not found!")

namespace simulacra {
    
    void EngineStyleParser::loadFromJSON(const std::string &filepath) {
        std::ifstream file;
        file.open("Resources/" + filepath);
        
        if (!file) {
            throw std::runtime_error("file not found!");
        }
        
        file >> serializableObject;
        file.close();
        
        ImGuiStyle* style = &ImGui::GetStyle();

        auto const windowRounding = serializableObject.find("window-rounding");
        auto const framePadding = serializableObject.find("frame-padding");
        auto const frameRounding = serializableObject.find("frame-rounding");
        auto const itemSpacing = serializableObject.find("item-spacing");
        auto const itemInnerSpacing = serializableObject.find("item-inner-spacing");
        auto const indentSpacing = serializableObject.find("indent-spacing");
        auto const scrollbarSize = serializableObject.find("scrollbar-size");
        auto const scrollbarRounding = serializableObject.find("scrollbar-rounding");
        auto const grabMinSize = serializableObject.find("grab-min-size");
        auto const grabRounding = serializableObject.find("grab-rounding");
        
        style->WindowRounding = windowRounding.value();
        
        style->FramePadding = ImVec2(framePadding.value()[0], framePadding.value()[1]);
        style->FrameRounding = frameRounding.value();
        
        style->ItemSpacing = ImVec2(itemSpacing.value()[0], itemSpacing.value()[1]);
        style->ItemInnerSpacing = ImVec2(itemInnerSpacing.value()[0], itemInnerSpacing.value()[1]);
        
        style->IndentSpacing = indentSpacing.value();
        
        style->ScrollbarSize = scrollbarSize.value();
        style->ScrollbarRounding = scrollbarRounding.value();
        
        style->GrabMinSize = grabMinSize.value();
        style->GrabRounding = grabRounding.value();
        
        // COLOUR SCHEME //
        try {
            auto const colourScheme = serializableObject.find("colour-scheme");
            if (colourScheme == serializableObject.end()) {
                throw std::runtime_error("colour-scheme key not found!");
            }
            
            auto const text = colourScheme->find("text"); CHECK_KEY(text, colourScheme);
            auto const textDisabled = colourScheme->find("text-disabled"); CHECK_KEY(textDisabled, colourScheme);
            auto const windowBackground = colourScheme->find("window-background"); CHECK_KEY(windowBackground, colourScheme);
            auto const popupBackground = colourScheme->find("popup-background"); CHECK_KEY(popupBackground, colourScheme);
            auto const border = colourScheme->find("border");  CHECK_KEY(border, colourScheme);
            auto const borderShadow = colourScheme->find("border-shadow"); CHECK_KEY(borderShadow, colourScheme);
            auto const frameBackground = colourScheme->find("frame-background"); CHECK_KEY(frameBackground, colourScheme);
            auto const frameBackgroundHovered = colourScheme->find("frame-background-hovered"); CHECK_KEY(frameBackgroundHovered, colourScheme);
            auto const frameBackgroundActive = colourScheme->find("frame-background-active"); CHECK_KEY(frameBackgroundActive, colourScheme);
            auto const titleBackground = colourScheme->find("title-background"); CHECK_KEY(titleBackground, colourScheme);
            auto const titleBackgroundCollapsed = colourScheme->find("title-background-collapsed"); CHECK_KEY(titleBackgroundCollapsed, colourScheme);
            auto const titleBackgroundActive = colourScheme->find("title-background-active"); CHECK_KEY(titleBackgroundActive, colourScheme);
            auto const menubarBackground = colourScheme->find("menubar-background"); CHECK_KEY(menubarBackground, colourScheme);
            auto const scrollbarBackground = colourScheme->find("scrollbar-background"); CHECK_KEY(scrollbarBackground, colourScheme);
            auto const scrollBarGrab = colourScheme->find("scrollbar-grab"); CHECK_KEY(scrollBarGrab, colourScheme);
            auto const scrollBarGrabHovered = colourScheme->find("scrollbar-grab-hovered"); CHECK_KEY(scrollBarGrabHovered, colourScheme);
            auto const scrollBarGrabActive = colourScheme->find("scrollbar-grab-active"); CHECK_KEY(scrollBarGrabActive, colourScheme);
            auto const tab = colourScheme->find("tab"); CHECK_KEY(tab, colourScheme);
            auto const tabHovered = colourScheme->find("tab-hovered"); CHECK_KEY(tabHovered, colourScheme);
            auto const tabActive = colourScheme->find("tab-active"); CHECK_KEY(tabActive, colourScheme);
            auto const checkmark = colourScheme->find("checkmark"); CHECK_KEY(checkmark, colourScheme);
            auto const sliderGrab = colourScheme->find("slider-grab"); CHECK_KEY(sliderGrab, colourScheme);
            auto const sliderGrabActive = colourScheme->find("slider-grab-active"); CHECK_KEY(sliderGrabActive, colourScheme);
            auto const button = colourScheme->find("button"); CHECK_KEY(button, colourScheme);
            auto const buttonHovered = colourScheme->find("button-hovered"); CHECK_KEY(buttonHovered, colourScheme);
            auto const buttonActive = colourScheme->find("button-active"); CHECK_KEY(buttonActive, colourScheme);
            auto const header = colourScheme->find("header"); CHECK_KEY(header, colourScheme);
            auto const headerHovered = colourScheme->find("header-hovered"); CHECK_KEY(headerHovered, colourScheme);
            auto const headerActive = colourScheme->find("header-active"); CHECK_KEY(headerActive, colourScheme);
            auto const resizeGrip = colourScheme->find("resize-grip"); CHECK_KEY(resizeGrip, colourScheme);
            auto const resizeGripHovered = colourScheme->find("resize-grip-hovered"); CHECK_KEY(resizeGripHovered, colourScheme);
            auto const resizeGripActive = colourScheme->find("resize-grip-active"); CHECK_KEY(resizeGripActive, colourScheme);
            auto const plotlines = colourScheme->find("plotlines"); CHECK_KEY(plotlines, colourScheme);
            auto const plotlinesHovered = colourScheme->find("plotlines-hovered"); CHECK_KEY(plotlinesHovered, colourScheme);
            auto const plotHistogram = colourScheme->find("plot-histogram"); CHECK_KEY(plotlinesHovered, colourScheme);
            auto const plotHistogramHovered = colourScheme->find("plot-histogram-hovered"); CHECK_KEY(plotHistogramHovered, colourScheme);
            auto const textSelectedBackground = colourScheme->find("text-selected-background"); CHECK_KEY(textSelectedBackground, colourScheme);
            auto const modalWindowDarkening = colourScheme->find("modal-window-darkening"); CHECK_KEY(modalWindowDarkening, colourScheme);

            style->Colors[ImGuiCol_Text] = ImVec4(text.value()[0], text.value()[1], text.value()[2], text.value()[3]);
            style->Colors[ImGuiCol_TextDisabled] = ImVec4(textDisabled.value()[0],
                                                          textDisabled.value()[1],
                                                          textDisabled.value()[2],
                                                          textDisabled.value()[3]);
            style->Colors[ImGuiCol_WindowBg] = ImVec4(windowBackground.value()[0],
                                                      windowBackground.value()[1],
                                                      windowBackground.value()[2],
                                                      windowBackground.value()[3]);
            style->Colors[ImGuiCol_PopupBg] = ImVec4(popupBackground.value()[0],
                                                     popupBackground.value()[1],
                                                     popupBackground.value()[2],
                                                     popupBackground.value()[3]);
            style->Colors[ImGuiCol_Border] = ImVec4(border.value()[0],
                                                    border.value()[1],
                                                    border.value()[2],
                                                    border.value()[3]);
            style->Colors[ImGuiCol_BorderShadow] = ImVec4(borderShadow.value()[0],
                                                          borderShadow.value()[1],
                                                          borderShadow.value()[2],
                                                          borderShadow.value()[3]);
            style->Colors[ImGuiCol_FrameBg] = ImVec4(frameBackground.value()[0],
                                                     frameBackground.value()[1],
                                                     frameBackground.value()[2],
                                                     frameBackground.value()[3]);
            style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(frameBackgroundHovered.value()[0],
                                                            frameBackgroundHovered.value()[1],
                                                            frameBackgroundHovered.value()[2],
                                                            frameBackgroundHovered.value()[3]);
            style->Colors[ImGuiCol_FrameBgActive] = ImVec4(frameBackgroundActive.value()[0],
                                                           frameBackgroundActive.value()[1],
                                                           frameBackgroundActive.value()[2],
                                                           frameBackgroundActive.value()[3]);
            style->Colors[ImGuiCol_TitleBg] = ImVec4(titleBackground.value()[0],
                                                     titleBackground.value()[1],
                                                     titleBackground.value()[2],
                                                     titleBackground.value()[3]);
            style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(titleBackgroundCollapsed.value()[0],
                                                              titleBackgroundCollapsed.value()[1],
                                                              titleBackgroundCollapsed.value()[2],
                                                              titleBackgroundCollapsed.value()[3]);
            style->Colors[ImGuiCol_TitleBgActive] = ImVec4(titleBackgroundActive.value()[0],
                                                           titleBackgroundActive.value()[1],
                                                           titleBackgroundActive.value()[2],
                                                           titleBackgroundActive.value()[3]);
            style->Colors[ImGuiCol_MenuBarBg] = ImVec4(menubarBackground.value()[0],
                                                       menubarBackground.value()[1],
                                                       menubarBackground.value()[2],
                                                       menubarBackground.value()[3]);
            style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(scrollbarBackground.value()[0],
                                                         scrollbarBackground.value()[1],
                                                         scrollbarBackground.value()[2],
                                                         scrollbarBackground.value()[3]);
            style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(scrollBarGrab.value()[0],
                                                           scrollBarGrab.value()[1],
                                                           scrollBarGrab.value()[2],
                                                           scrollBarGrab.value()[3]);
            style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(scrollBarGrabHovered.value()[0],
                                                                  scrollBarGrabHovered.value()[1],
                                                                  scrollBarGrabHovered.value()[2],
                                                                  scrollBarGrabHovered.value()[3]);
            style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(scrollBarGrabActive.value()[0],
                                                                 scrollBarGrabActive.value()[1],
                                                                 scrollBarGrabActive.value()[2],
                                                                 scrollBarGrabActive.value()[3]);
            
            style->Colors[ImGuiCol_Tab] = ImVec4(tab.value()[0],
                                                 tab.value()[1],
                                                 tab.value()[2],
                                                 tab.value()[3]);
            style->Colors[ImGuiCol_TabHovered] = ImVec4(tabHovered.value()[0],
                                                        tabHovered.value()[1],
                                                        tabHovered.value()[2],
                                                        tabHovered.value()[3]);
            style->Colors[ImGuiCol_TabActive] = ImVec4(tabActive.value()[0],
                                                       tabActive.value()[1],
                                                       tabActive.value()[2],
                                                       tabActive.value()[3]);
            
            style->Colors[ImGuiCol_CheckMark] = ImVec4(checkmark.value()[0],
                                                       checkmark.value()[1],
                                                       checkmark.value()[2],
                                                       checkmark.value()[3]);
            style->Colors[ImGuiCol_SliderGrab] = ImVec4(sliderGrab.value()[0],
                                                        sliderGrab.value()[1],
                                                        sliderGrab.value()[2],
                                                        sliderGrab.value()[3]);
            style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(sliderGrabActive.value()[0],
                                                              sliderGrabActive.value()[1],
                                                              sliderGrabActive.value()[2],
                                                              sliderGrabActive.value()[3]);
            
            style->Colors[ImGuiCol_Button] = ImVec4(button.value()[0],
                                                    button.value()[1],
                                                    button.value()[2],
                                                    button.value()[3]);
            style->Colors[ImGuiCol_ButtonHovered] = ImVec4(buttonHovered.value()[0],
                                                           buttonHovered.value()[1],
                                                           buttonHovered.value()[2],
                                                           buttonHovered.value()[3]);
            style->Colors[ImGuiCol_ButtonActive] = ImVec4(buttonActive.value()[0],
                                                          buttonActive.value()[1],
                                                          buttonActive.value()[2],
                                                          buttonActive.value()[3]);
            
            style->Colors[ImGuiCol_Header] = ImVec4(header.value()[0],
                                                    header.value()[1],
                                                    header.value()[2],
                                                    header.value()[3]);
            style->Colors[ImGuiCol_HeaderHovered] = ImVec4(headerHovered.value()[0],
                                                           headerHovered.value()[1],
                                                           headerHovered.value()[2],
                                                           headerHovered.value()[3]);
            style->Colors[ImGuiCol_HeaderActive] = ImVec4(headerActive.value()[0],
                                                          headerActive.value()[1],
                                                          headerActive.value()[2],
                                                          headerActive.value()[3]);
            
            style->Colors[ImGuiCol_ResizeGrip] = ImVec4(resizeGrip.value()[0],
                                                        resizeGrip.value()[1],
                                                        resizeGrip.value()[2],
                                                        resizeGrip.value()[3]);
            style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(resizeGripHovered.value()[0],
                                                               resizeGripHovered.value()[1],
                                                               resizeGripHovered.value()[2],
                                                               resizeGripHovered.value()[3]);
            style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(resizeGripActive.value()[0],
                                                              resizeGripActive.value()[1],
                                                              resizeGripActive.value()[2],
                                                              resizeGripActive.value()[3]);
            
            style->Colors[ImGuiCol_PlotLines] = ImVec4(plotlines.value()[0],
                                                       plotlines.value()[1],
                                                       plotlines.value()[2],
                                                       plotlines.value()[3]);
            style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(plotlinesHovered.value()[0],
                                                              plotlinesHovered.value()[1],
                                                              plotlinesHovered.value()[2],
                                                              plotlinesHovered.value()[3]);
            style->Colors[ImGuiCol_PlotHistogram] = ImVec4(plotHistogram.value()[0],
                                                           plotHistogram.value()[1],
                                                           plotHistogram.value()[2],
                                                           plotHistogram.value()[3]);
            style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(plotHistogramHovered.value()[0],
                                                                  plotHistogramHovered.value()[1],
                                                                  plotHistogramHovered.value()[2],
                                                                  plotHistogramHovered.value()[3]);
            
            style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(textSelectedBackground.value()[0],
                                                            textSelectedBackground.value()[1],
                                                            textSelectedBackground.value()[2],
                                                            textSelectedBackground.value()[3]);
            style->Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(modalWindowDarkening.value()[0],
                                                                  modalWindowDarkening.value()[1],
                                                                  modalWindowDarkening.value()[2],
                                                                  modalWindowDarkening.value()[3]);
        } catch (const std::exception& e) {
            std::cout << e.what();
        }
        
    }
    
    
}
