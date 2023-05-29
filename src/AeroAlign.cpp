/**
 * @file AeroAlign.cpp
 * @author Krisna Pranav
 * @brief Aero Alignment Functionalities
 * @version 0.1
 * @date 2023-05-29
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#include "AeroAlign.hpp"

namespace AeroUI {
    const char* toString(HorizontalAlignment type) {
        switch (type) {
            case HorizontalAlignment::Center: return "Center";
            case HorizontalAlignment::Right: return "right";
            case HorizontalAlignment::Left:
            default: break;
        }

        return "Left";
    }
}