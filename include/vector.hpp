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
    vector(float inX, float inY);

    vector operator-() const;
    vector operator+(const vector& Other) const;
    vector operator-(const vector& Other) const;
    vector operator*(const vector& Other) const;
    vector operator/(const vector& Other) const;

    vector operator+(float Other) const;
    vector operator-(float Other) const;
    vector operator*(float Other) const;
    vector operator/(float Other) const;

    vector& operator+=(const vector& Other);
    vector& operator-=(const vector& Other);
    vector& operator*=(const vector& Other);
    vector& operator/=(const vector& Other);

    float X { 0.0f };
    float Y { 0.0f };

    bool operator==(const vector& Other) const;
    bool operator!=(const vector& Other) const;

    float length() const;
    float lengthSq() const;
    bool isZero() const;

    vector invert() const;
    vector floor() const;

};
}

#endif /* __INCLUDE_VECTOR_HPP__ */