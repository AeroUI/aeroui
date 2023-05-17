/**
 * @file colors.h
 * @author Krisna Pranav
 * @brief Colors
 * @version 0.1
 * @date 2023-05-17
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#pragma once

#include <cstdint>

namespace AeroUI {

class json;

struct color {
public:
    /**
     * @brief colors
     * 
     */
    static const color white;
    static const color black;
    static const color yellow;
    static const color red;

    static color parse(const json& root);
    static json toJson(const color& value);

    /**
     * @brief RGBA
     * 
     */
    uint8_t R { 0 };
    uint8_t G { 0 };
    uint8_t B { 0 };
    uint8_t A { 0 };

    /**
     * @brief Construct a new color object
     * 
     */
    color();
    color(uint8_t inR, uint8_t inG, uint8_t inB, uint8_t inA);

    /**
     * @brief operators
     * 
     * @param other 
     * @return true 
     * @return false 
     */
    bool operator==(const color& other) const;
    bool operator!=(const color& other) const;
}

}