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

#include <vector>

#include "AeroTypes.hpp"
#include "AeroVector.hpp"
#include "UI/Layouts/AeroLayout.hpp"

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

// TODO: Requires documentation

class AeroWindow {
public:
    AUIui __window_id = 0;
    std::vector<AUIui> __intents;
    bool __polling = false;
public:
    AeroWindow();
    ~AeroWindow();

    AeroWindow(AeroWindow&);
    AeroWindow operator = (AeroWindow);
public:
// Window system
    bool initWindow(const int&, const int&, const char*);
    bool setWindowIcon(); // TODO: NEEDS KRISH'S IMAGE CODE
    bool shouldClose() const; 

    void closeWindow() const noexcept;
    void setCloseHandler(void*) noexcept;
    void setWindowIntent(const AUIui&) noexcept;

// Input system
    void pollAll() noexcept;
// Security Handler
    const bool requestCalls() noexcept;
    const bool checkAll() noexcept;
// UI Manager
    void applyLap() noexcept;
    void addLayout(const AeroLayoutManager&) noexcept;
public:
// Public operator methods
    bool operator == (const AeroWindow&);
    bool operator != (const AeroWindow&);
public:
// Public methods
    const AUIui getWindowID() const noexcept;
    const AeroWindow getWindow() const noexcept;

    const vector getWindowPos() const noexcept;
    const vector getWindowSize() const noexcept;

    const int getX() const noexcept;
    const int getY() const noexcept;

    const int getWindowWidth() const noexcept;
    const int getWindowHeight() const noexcept;

    const bool loadTheme(const char*); // load from file (e.g THEME.aui)

    const std::vector<AUIui> getWindowIntents() const noexcept;
};

}

#endif /* __INCLUDE_CORE_AEROWINDOW_HPP__ */
