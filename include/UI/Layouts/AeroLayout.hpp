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

#include <vector>
#include "Core/AeroWidget.hpp"

namespace AeroUI {

class AeroLayoutManager {
public:
    AeroLayoutManager() = default;
    virtual ~AeroLayoutManager() = default;
public:
    // Widget controls
    virtual void add(const AeroWidget&);
    virtual void remove(const AeroWidget&);
    virtual void render(const AeroWidget&);
    
    virtual const std::vector<AeroWidget> getWidgets();
};

}

#endif /* __INCLUDE_AERO_LAYOUT_HPP__ */