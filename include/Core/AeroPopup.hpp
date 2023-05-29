/**
 * @file AeroPopup.hpp
 * @author Krisna Pranav
 * @brief Popup Functionalities
 * @version 0.1
 * @date 2023-05-29
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#pragma once

#include "AeroCallbacks.hpp"
#include "AeroMouse.hpp"
#include <cstdint>
#include <functional>
#include <memory>

namespace AeroUI {
    class Container;
    class Control;
    class Paint;
    struct Vector2;

    class Popup {
    public:
        enum class State: uint8_t {
            None,
            Opening,
            Opened
        };

        Popup();
        ~Popup();
    };
}