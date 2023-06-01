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

        bool Bool(bool Or = false) const;
        unsigned char byte(unsigned char Or = 0) const;
        int Int(int Or = 0) const;
        float Float(float Or = 0.0f) const;
        const char* String(const char* Or = "") const;
        vector Vector(const vector& Or = {}) const;
        color toColor(const color& Or = {}) const;

        bool isNull() const;
        bool isBool() const;
        bool isByte() const;
        bool isInt() const;
        bool isFloat() const;
        bool isString() const;
        bool isVector() const;
        bool isColor() const;

        Type getType() const;
        std::string toString() const;
    
    private:
        union Data {
            bool Bool;
            unsigned char byte;
            int Int;
            float Float; 
            std::string* String;
            vector Vector;
            color Col;
        };

        void copy(const json&);
        void copy(const variant&);
        void move(variant&&);
        void clear();

        Type m_type { Type::Null };
        Data m_Data {};


    };
}