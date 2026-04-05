#pragma once
#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <cmath>
#include <format>

struct Vector2 {
    float x = 0.f;
    float y = 0.f;

    constexpr Vector2() = default;
    constexpr Vector2(float x, float y) : x(x), y(y) {}

    constexpr Vector2& operator+=(const Vector2& vec) {
        x += vec.x;
        y += vec.y;
        return *this;
    }
    constexpr Vector2& operator-=(const Vector2& vec) {
        x -= vec.x;
        y -= vec.y;
        return *this;
    }
    constexpr Vector2& operator*=(const Vector2& vec) {
        x *= vec.x;
        y *= vec.y;
        return *this;
    }
    constexpr Vector2& operator/=(const Vector2& vec) {
        x /= vec.x;
        y /= vec.y;
        return *this;
    }
    constexpr Vector2& operator*=(float s) {
        x *= s;
        y *= s;
        return *this;
    }
    constexpr Vector2& operator/=(float s) {
        x /= s;
        y /= s;
        return *this;
    }

    friend constexpr Vector2 operator+(Vector2 v1, const Vector2& v2) { return v1 += v2; }
    friend constexpr Vector2 operator-(Vector2 v1, const Vector2& v2) { return v1 -= v2; }
    friend constexpr Vector2 operator*(Vector2 v1, const Vector2& v2) { return v1 *= v2; }
    friend constexpr Vector2 operator/(Vector2 v1, const Vector2& v2) { return v1 /= v2; }

    friend constexpr Vector2 operator*(Vector2 vec, float s) { return vec *= s; }
    friend constexpr Vector2 operator/(Vector2 vec, float s) { return vec /= s; }

    constexpr float Magnitude() const { return x*x + y*y; }
    float Length() const { return std::sqrt(Magnitude()); }

    Vector2 Normalized() const {
        float len = Length();
        return (len == 0.f) ? Vector2{} : Vector2(x/len, y/len);
    }
    Vector2& Normalize() { return *this = Normalized(); }

    static float Distance(const Vector2& v1, const Vector2& v2) { return (v1 - v2).Length(); }
    constexpr float Distance(const Vector2& vec) { return (*this - vec).Length(); }

    static constexpr Vector2 Zero() { return Vector2(0.f, 0.f); }
    Vector2& New() { return *this = Vector2::Zero(); }

    static const char* c_str(const Vector2& vec) {
        thread_local static char buffer[64];
        std::snprintf(buffer, sizeof(buffer), "Vector2D(%f, %f)", vec.x, vec.y);
        return buffer;
    }
    const char* c_str() { return Vector2::c_str(*this); }
};

template<>
struct std::formatter<Vector2> : std::formatter<const char*> {
    auto format(const Vector2& vec, auto& ctx) const {
        return std::formatter<const char*>::format(Vector2::c_str(vec), ctx);
    }
};

#endif /* VECTOR2_HPP */