//
//  enums.h
//  SimulacraEngine
//
//  Created by Alex Dragutoiu on 17/06/2020.
//  Copyright © 2020 Alex Dragutoiu. All rights reserved.
//
#pragma once

namespace simulacra {
    
    enum ButtonState {
        BTN_IDLE = 0,
        BTN_HOVER,
        BTN_PRESSED
    };
    
    enum class Action {
        NONE,
        IDLE,
        IDLE_LEFT,
        IDLE_RIGHT,
        LEFT,
        RIGHT,
        ATTACK_RIGHT,
    };
    
}
