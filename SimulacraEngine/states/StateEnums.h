//
//  StateEnums.h
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 21/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

#include <iostream>

namespace simulacra {
    enum class States {
        NONE,
        INTRO_STATE,
        MENU_STATE,
        EDITOR_STATE,
        SETTINGS_STATE,
        OPTIONS_STATE,
        GAME_STATE,
        PAUSE_STATE
    };
}
