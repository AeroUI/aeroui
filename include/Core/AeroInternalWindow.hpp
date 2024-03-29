/**
 * @file AeroInternalWindow.hpp
 * @author Mustafa Malik
 * @brief 
 * @version 0.1
 * @date 2023-05-17
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#ifndef __INCLUDE_CORE_AEROWINDOW_HPP__
#define __INCLUDE_CORE_AEROWINDOW_HPP__

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "AeroTypes.hpp"
#include "vector.hpp"

#ifdef AUI_NO_DEPRECATION
#   define GL_SILENCE_DEPRECATION
#else
#   warning Deprecations warnings may appear, to silence, define AUI_NO_DEPRECATION
#endif

#ifdef AUI_DEBUG_MODE
// TODO: Window Logging
#   define AUI_WINDOW_LOG(__msg)
#else
#   define AUI_WINDOW_LOG(__msg)
#endif

#if __cplusplus < 201103
#   error Please use a modern C++ compiler from C++11 or above
#endif

#define DEFAULT_WINDOW_WIDTH    1080
#define DEFAULT_WINDOW_HEIGHT   720

#define RENDER_THRESHOLD_RATE   60
#define RENDER_DEFAULT_COLOUR   0x000000 // RR GG BB format

namespace AeroUI {

class AeroInternalWindow {
protected:
    AUIui __window_id = 0;
    bool __polling = false;
protected:
    AeroInternalWindow();
    ~AeroInternalWindow();
    
    AeroInternalWindow(AeroInternalWindow&);
    AeroInternalWindow operator = (AeroInternalWindow);
protected:
    // Window system
    bool aero_init_window(const int&, const int&, const char*);
    bool aero_set_window_icon(); // TODO: NEEDS KRISH'S IMAGE CODE
    bool aero_should_close() const;
    void aero_close_window() const noexcept;
    // Input system
    void aero_poll_all() noexcept;
public:
    // Public operator methods
    bool operator == (const AeroInternalWindow&);
    bool operator != (const AeroInternalWindow&);
public:
    // Public methods
    const AUIui get_window_id() const noexcept;
    const AeroInternalWindow get_window() const noexcept;

    const vector get_window_pos() const noexcept;
    const vector get_window_size() const noexcept;

    const int get_x_pos() const noexcept;
    const int get_y_pos() const noexcept;

    const int get_window_width() const noexcept;
    const int get_window_height() const noexcept;
};

}

#endif /* __INCLUDE_CORE_AEROWINDOW_HPP__ */
