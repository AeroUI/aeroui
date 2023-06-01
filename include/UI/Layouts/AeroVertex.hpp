/**
 * @file AeroVertex.hpp
 * @author Krisna Pranav
 * @brief Aero Vertext
 * @version 0.1
 * @date 2023-06-01
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#pragma once

#include "AeroColour.hpp"
#include "AeroVector.hpp"

namespace AeroUI {
    struct vertex {
    public:
        vector position;
        vector texCoords;
        color col;

        vertex();
        vertex(const vector& inPosition);
        vertex(const vector& inPosition, const color& inCol);
        vertex(const vector& inPosition, const vector& inTextCoords, const color& inCol);

    };
}