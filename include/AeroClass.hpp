/**
 * @file AeroClass.hpp
 * @author Krisna Pranav
 * @brief AeroClass
 * @version 0.1
 * @date 2023-06-01
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#pragma once

namespace AeroUI {

    class Class {
    public:
        Class();
        virtual ~Class();

        virtual const char* getType() const;
    };

    #define CLASS(Name)                              \
    public:                                          \
        virtual const char* getType() const override \
        {                                            \
            return #Name;                            \
        }                                            \
        static const char* typeName()                \
        {                                            \
            return #Name;                            \
        }

}