/**
 * @file AeroControl.hpp
 * @author Krisna Pranav
 * @brief AeroControl
 * @version 0.1
 * @date 2023-06-01
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#pragma once

#include "AeroCallbacks.hpp"
#include "Input/AeroInput.hpp"
#include "Input/AeroMouse.hpp"
#include "AeroRect.hpp"
#include "AeroClass.hpp"
// class, theme properties
#include <functional>
#include <memory>
#include <string>

namespace AeroUI {
    class json;
    class paint;
    class theme;
    class window;

    enum class Expand: uint8_t {
        None,
        Width,
        Height,
        Both
    };
}