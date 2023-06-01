/**
 * @file AeroVariant.hpp
 * @author Krisna Pranav
 * @brief Aero Variant
 * @version 0.1
 * @date 2023-06-01
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#pragma once

#include "AeroColour.hpp"
#include "AeroVector.hpp"
#include <string>

namespace AeroUI {
    class json;

    class variant {
    public:
        enum class Type : unsigned char {
            Null,
            Bool,
            Byte,
            Int,
            Float,
            String,
            Vector,
            Color
        };

        variant();
        variant(bool);
        variant(unsigned char);
        variant(int);
        variant(float);
        variant(const char*);
        variant(const std::string&);
        variant(const vector&);
        variant(const color&);
        variant(const json&);
        variant(const variant&);
        variant(variant&&);
        ~variant();

        variant& operator=(bool value);
        variant& operator=(unsigned char value);
        variant& operator=(int value);
        variant& operator=(float value);
        variant& operator=(const char* value);
        variant& operator=(const std::string& value);
        variant& operator=(const variant& value);
        variant& operator=(const color& value);
        variant& operator=(const json& value);
        variant& operator=(const variant& value);
        variant& operator=(variant&& value);

    };
}