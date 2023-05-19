/**
 * @file AeroTypes.hpp
 * @author Mustafa Malik
 * @brief 
 * @version 0.1
 * @date 2023-05-17
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#ifndef __INCLUDE_AERO_TYPES_HPP__
#define __INCLUDE_AERO_TYPES_HPP__

#define AUIui unsigned int

namespace AeroUI {
struct AeroEnumHelper {
    template<typename T>
    static int aero_etoi(T*); // Enum to Integer

    template<typename T>
    static std::string aero_etos(T*); // Enum to String

    template<typename T, V>
    static T aero_vtoe(V*); // Value to Enum
};
}

#endif /* __INCLUDE_AERO_TYPES_HPP__ */