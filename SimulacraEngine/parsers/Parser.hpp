//
//  Parser.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 10/10/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

#include "imgui.h"
#include "imgui-SFML.h"

using json = nlohmann::json;

namespace simulacra {
    class Parser {
    public:
        virtual ~Parser() {
            
        }
        
        virtual void loadFromJSON(const std::string& filepath) = 0;
        
    protected:
        json serializableObject;
    };

    class EngineStyleParser : public Parser {
    public:
        virtual void loadFromJSON(const std::string& filepath);
        
    };
}
