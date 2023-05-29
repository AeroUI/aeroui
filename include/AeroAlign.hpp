/**
 * @file AeroAlign.hpp
 * @author your name (you@domain.com)
 * @brief Alignment functionalities
 * @version 0.1
 * @date 2023-05-29
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#pragma once

#include <cstdint>

namespace AeroUI {
    enum class HorizontalAlignment: uint8_t {
        Left,
        Center,
        Right
    };

    enum class VerticalAlignment: uint8_t {
        Top,
        Center,
        Bottom
    };

    const char* toString(HorizontalAlignment type);
}