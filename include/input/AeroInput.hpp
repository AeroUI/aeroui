/**
 * @file AeroInputTypes.hpp
 * @author Mustafa Malik
 * @brief 
 * @version 0.1
 * @date 2023-05-18
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#include <functional>
#include "AeroInputTypes.hpp"

#ifndef __INCLUDE_AERO_INPUT_HPP__
#define __INCLUDE_AERO_INPUT_HPP__

namespace AeroUI {

enum class AeroInputTypes {

    MOUSE_RELEASE,
    MOUSE_PRESS,

    MOUSE_MOVE,
    MOUSE_WHEEL_SCROLL_UP,
    MOUSE_WHEEL_SCROLL_DOWN,

    KEYBOARD_PRESS,
    KEYBOARD_RELEASE,

    KEYBOARD_KEY_HOLD,
    KEYBOARD_KEY_HOLD_RELEASE,

    MOUSE_CLICK_HOLD,
    MOUSE_CLICK_HOLD_RELEASE,

};

enum class AeroActionType {
    PRESS,
    RELEASE,
    REPEAT,
};

struct AeroInputResult {
    AeroInputTypes input_type;
    int code;
    bool is_triggered;
};

// Singleton
class AeroInputControl {
public:
    AeroInputTypes input_state;
private:
    AeroInputControl() = delete;
    ~AeroInputControl() = delete;
public:
    struct AeroInputResult aero_is_key_input() noexcept;
    struct AeroInputResult aero_is_mouse_input() noexcept;

    /**
     * @brief Set the input callback for a window
     * @param void* window - The window pointer
     * @param int key - The key triggered
     * @param int scancode - unique identifier for a key
     * @param int action - The action triggered from the key
     * @param int mods - extras
     * @note void* will be automatically casted to a `AeroInternalWindow`
     */
    void aero_set_input_cb(std::function<void(void*, int, int, int, int)>) noexcept;

    AeroInputTypes aero_get_key(const int&) noexcept;

    AeroActionType aero_get_action(const int&) noexcept;
};
}

#endif /* __INCLUDE_AERO_INPUT_HPP__ */