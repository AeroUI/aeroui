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
private:
    // Private variables
protected:
    AeroInternalWindow();
    ~AeroInternalWindow();
    
    AeroInternalWindow(AeroInternalWindow&);
    AeroInternalWindow operator= (AeroInternalWindow&);
protected:
    // Protected methods
public:
    // Public methods
};

}

#endif /* __INCLUDE_CORE_AEROWINDOW_HPP__ */
