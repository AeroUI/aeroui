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
    
    virtual const int getLayoutX() const noexcept;
    virtual const int getLayoutY() const noexcept;
    
    virtual const int getLayoutWidth() const noexcept;
    virtual const int getLayoutHeight() const noexcept;
    
    virtual const int getWidgetX(const AeroWidget&) const noexcept;
    virtual const int getWidgetY(const AeroWidget&) const noexcept;
    
    virtual const int getWidgetWidthInLayout(const AeroWidget&) const noexcept;
    virtual const int getWidgetHeightInLayout(const AeroWidget&) const noexcept;
};

}

#endif /* __INCLUDE_AERO_LAYOUT_HPP__ */