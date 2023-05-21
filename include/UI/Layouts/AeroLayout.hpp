/**
 * @file AeroLayout.hpp
 * @author Mustafa Malik
 * @brief 
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#ifndef __INCLUDE_AERO_LAYOUT_HPP__
#define __INCLUDE_AERO_LAYOUT_HPP__

namespace AeroUI {

class AeroLayoutManager {
public:
    AeroLayoutManager() = default;
    virtual ~AeroLayoutManager() = default;
public:
    // Widget controls
    virtual void add(); // param requires widget
    virtual void remove(); // param requires widget
    virtual void render(); // param required widget
};

}

#endif /* __INCLUDE_AERO_LAYOUT_HPP__ */