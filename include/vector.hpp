/**
 * @file vector.h
 * @author Krisna Pranav, AeroUI developers
 * @brief 
 * @version 0.1
 * @date 2023-05-17
 * 
 * @copyright Copyright (c) 2023 AeroUI
 * 
 */

#ifndef __INCLUDE_VECTOR_HPP__
#define __INCLUDE_VECTOR_HPP__

namespace AeroUI {
class json;

struct vector {
public:
    static vector zero;
    static json toJson(const vector& value);
    static vector fromJson(const json& value, const vector& Default = {});

    vector();
    vector(float intX, float inY);

    float length() const;
    float lengthSq() const;
    bool isZero() const;

};
}

#endif /* __INCLUDE_VECTOR_HPP__ */