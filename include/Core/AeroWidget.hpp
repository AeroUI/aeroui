/**
 * @file AeroWidget.hpp
 * @author Mustafa Malik
 * @brief 
 * @version 0.1
 * @date 2023-05-17
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */
 
 #ifndef __INCLUDE_CORE_AEROWIDGET_HPP__
 #define __INCLUDE_CORE_AEROWIDGET_HPP__
 
 #include "AeroTypes.hpp"
 
 namespace AeroUI {
 
class AeroWidget {
public:
	AUIui __widget_id = 0;
public:
	AeroWidget() = default;
	virtual AeroWidget() = default;
public:
	virtual const AUIui getWidgetID() const noexcept;
};

}
 
 #endif /* __INCLUDE_CORE_AEROWIDGET_HPP__ */