//
//  AssetLoader.hpp
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 15/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#define WARNING(message, filename) fprintf(stderr, "[WARNING]: %s: %s\n", message, filename)

#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "../enums.h"

namespace simulacra {
    
    template <typename Resource, typename Identifier>
    class AssetLoader {
    private:
        std::unordered_map<Identifier, std::unique_ptr<Resource>> resources;
        
    private:
        void insertResource(Identifier id, std::unique_ptr<Resource> resource);
        
    public:
        void load(Identifier id, const std::string& filename);
        
        Resource& get(Identifier id);
        const Resource& get(Identifier id) const;
    };
    
    
    template <typename Resource, typename Identifier>
    void AssetLoader<Resource, Identifier>::load(Identifier id, const std::string& filename) {
        std::unique_ptr<Resource> resource = std::make_unique<Resource>();
        if (!resource->loadFromFile(filename)) {
            WARNING("[ERROR]: Couldn't load file! ", filename.c_str());
        }
        
        insertResource(id, std::move(resource));
    }
    
    template<typename Resource, typename Identifier>
    Resource& AssetLoader<Resource, Identifier>::get(Identifier id) {
        auto found = resources.find(id);
        assert(found != resources.end());
        
        return *found->second;
        //        return resources.at(id);
    }
    
    template<typename Resource, typename Identifier>
    const Resource& AssetLoader<Resource, Identifier>::get(Identifier id) const {
        auto found = resources.find(id);
        assert(found != resources.end());
        
        return *found->second;
        //        return resources.at(id);
    }
    
    template <typename Resource, typename Identifier>
    void AssetLoader<Resource, Identifier>::insertResource(Identifier id, std::unique_ptr<Resource> resource) {
        // Insert and check success
        auto inserted = resources.insert(std::make_pair(id, std::move(resource)));
        assert(inserted.second);
    }
}
