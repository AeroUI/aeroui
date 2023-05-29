/**
 * @file AeroMouse.hpp
 * @author Krisna Pranav
 * @brief Aero Mouse Functionalities
 * @version 0.1
 * @date 2023-05-29
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#pragma once

#include <cstdint>

namespace AeroUI {
    class Mouse {
    public:
        enum class Button: uint8_t {
            Left,
            Middle,
            Right
        };

        enum class Count: uint8_t {
            Single,
            Double,
            Triple
        };

        enum class Cursor: uint8_t {
            Arrow,
            IBeam,
            SizeWE,
            SizeNS
        };
    };
}