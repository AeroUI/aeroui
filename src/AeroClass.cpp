/**
 * @file AeroClass.cpp
 * @author Krisna Pranav
 * @brief AeroClass
 * @version 0.1
 * @date 2023-06-01
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#include "AeroClass.hpp"

namespace AeroUI {
    Class::Class() {}

    Class::~Class() {}

    const char* Class::getType() const {
        return "Class";
    }
}