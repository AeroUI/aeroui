/**
 * @file vector.h
 * @author AeroUI developers
 * @brief 
 * @version 0.1
 * @date 2023-05-17
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#ifndef __INCLUDE_RECT_HPP__
#define __INCLUDE_RECT_HPP__

#include "vector.hpp"

namespace AeroUI {

struct Rect {
public:
    static Rect fromJson(const AeroUI::json& root, const Rect& Default = {});
    static AeroUI::json toJson(const Rect& value);

    vector min, max;

    Rect();
    Rect(float minX, float minY, float maxX, float maxy);
    Rect(const vector& inMin, const vector& inMax);

    bool operator==(const Rect& other) const;

    float width() const;
    float height() const;
    vector getSize() const;
    vector getCenter() const;

    bool isZero() const;

    bool contains(float x, float y) const;
    bool contains(const vector& point) const;

    Rect& move(float x, float y);
    Rect& move(const vector& delta);

    Rect& setPosition(float x, float y);
    Rect& setPosition(const vector& delta);

    Rect& setSize(const vector& size);

    Rect& expand(float width, float height);
    Rect& expand(const vector& size);

    Rect& shrink(float width, float height);
    Rect& shrink(const vector& size);

    bool intersects(const Rect& other) const;
    bool encompasses(const Rect& other) const;

    Rect intersection(const Rect& other) const;
};

}

#endif /* __INCLUDE_RECT_HPP__ */