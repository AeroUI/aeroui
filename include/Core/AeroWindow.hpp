/**
 * @file window.hpp
 * @author Mustafa Malik
 * @brief windowing
 * @version 0.1
 * @date 2023-05-17
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#ifndef __INCLUDE_CORE_WINDOW_HPP__
#define __INCLUDE_CORE_WINDOW_HPP__

#include "AeroInternalWindow.hpp"

namespace AeroUI {

class AeroInternalWindow;

class AeroWindow : private AeroInternalWindow { };

}

#endif /* __INCLUDE_CORE_WINDOW_HPP__ */