#pragma once
#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <cmath>
#include <format>

/**
 * ### Vector2(x, y)
 * #### float x, float y
 * An object containing 2 numbers, x and y.
 * Used for 2D math operations.
 * - Magnitude, Length, Distance, Normal functions.
 * - Dot, Cross, and Mod functions, complete with operators.
 * - built-in formatting for string insertions
 */
struct Vector2 {
    /* Vector2 value x */
    float x = 0.f;
    /* Vector2 value y */
    float y = 0.f;

    /**
     * ### Create a new Vector2 object
     * - Vector2(0,0)
    */
    constexpr Vector2() = default;

    /* ### Create a Vector2 object and assign it values x and y */
    constexpr Vector2(float x, float y) : x(x), y(y) {}

    /* ### Create a Vector2 object with equal x and y values */
    constexpr Vector2(float s) : x(s), y(s) {}

    /**
     * Scalar operand
     * x+1, y+1
     */
    friend constexpr Vector2 operator++(Vector2 vec) {
        vec.x++;
        vec.y++;
        return vec;
    }

    /**
     * Scalar operand
     * x-1, y-1
     */
    friend constexpr Vector2 operator--(Vector2 vec) {
        vec.x--;
        vec.y--;
        return vec;
    }

    /**
     * Scalar, apply equal value to X and Y
     * - vec.x = s, vec.y = s
     */
    constexpr Vector2& operator=(float s) {
        x = y = s;
        return *this;
    }

    /* ( v1.x + v2.x ), (v1.y + v2.y )*/
    constexpr Vector2& operator+=(const Vector2& vec) {
        x += vec.x;
        y += vec.y;
        return *this;
    }

    /* ( v1.x - v2.x ), ( v1.y - v2.y ) */
    constexpr Vector2& operator-=(const Vector2& vec) {
        x -= vec.x;
        y -= vec.y;
        return *this;
    }

    /* ( v1.x * v2.x ), ( v1.y * v2.y ) */
    constexpr Vector2& operator*=(const Vector2& vec) {
        x *= vec.x;
        y *= vec.y;
        return *this;
    }

    /* ( v1.x / v2.x ), ( v1.y / v2.y ) */
    constexpr Vector2& operator/=(const Vector2& vec) {
        x /= vec.x;
        y /= vec.y;
        return *this;
    }

    /**
     * Scalar adder
     * - vec.x+s, vec.y+s
     */
    constexpr Vector2& operator+=(float s) {
        x += s;
        y += s;
        return *this;
    }

    /**
     * Scalar subtractor
     * - vec.x-s, vec.y-s
     */
    constexpr Vector2& operator-=(float s) {
        x -= s;
        y -= s;
        return *this;
    }

    /**
     * Scalar multiplier
     * - vec.x*s, vec.y*s
     */
    constexpr Vector2& operator*=(float s) {
        x *= s;
        y *= s;
        return *this;
    }

    /** 
     * Scalar divider
     * - vec.x/s, vec.y/s 
     */
    constexpr Vector2& operator/=(float s) {
        x /= s;
        y /= s;
        return *this;
    }

    /* ( v1.x + v2.x ), ( v1.y + v2.y ) */
    friend constexpr Vector2 operator+(Vector2 v1, const Vector2& v2) { return v1 += v2; }

    /* ( v1.x - v2.x ), ( v1.y - v2.y ) */
    friend constexpr Vector2 operator-(Vector2 v1, const Vector2& v2) { return v1 -= v2; }
    
    /* ( v1.x * v2.x ), ( v1.y * v2.y ) */
    friend constexpr Vector2 operator*(Vector2 v1, const Vector2& v2) { return v1 *= v2; }
    
    /* ( v1.x / v2.x ), ( v1.y / v2.y ) */
    friend constexpr Vector2 operator/(Vector2 v1, const Vector2& v2) { return v1 /= v2; }
    
    /**
     * Scalar adder
     * ( v1.x. + s ), ( v1.y + s )
     */
    friend constexpr Vector2 operator+(Vector2 vec, float s) { return vec += s; }

    /**
     * Scalar subtractor
     * ( v1.x - s ), ( v1.y - s )
     */
    friend constexpr Vector2 operator-(Vector2 vec, float s) { return vec -= s; }

    /**
     * Scalar multiplier
     * ( v1.x * s ), ( v1.y * s ) 
     */
    friend constexpr Vector2 operator*(Vector2 vec, float s) { return vec *= s; }
    
    /**
     * Scalar divider
     * ( v1.x +/s ), ( v1.y / s )
     */
    friend constexpr Vector2 operator/(Vector2 vec, float s) { return vec /= s; }

    /**
     * ### Square size of the vector.
     * - x*x + y*y
     */
    constexpr float Magnitude() const { return x*x + y*y; }

    /**
     * ### Square root size of the vector.
     * sqrt(x*x + y*y)
     */
    constexpr float Length() const {
        if(float m = Magnitude(); m != 0.f) return std::sqrt(m);
        return 0.f;
    }


    /* v1.x*v2.x + v1.x*v2.x */
    static float Dot(const Vector2& v1, const Vector2& v2) { return v1.x*v2.x + v1.y*v2.y; }

    /* v1.x*v2.y - v2.x*v2.y */
    static float Cross(const Vector2& v1, const Vector2& v2) { return v1.x*v2.y - v1.y*v2.x; }

    /* len(v1) % len(v2) */
    static float Mod(const Vector2& v1, const Vector2& v2) { return std::fmod(v1.Length(), v2.Length());}

    /* v1.x*v2.x + v1.x*v2.x */
    constexpr float Dot(const Vector2& vec) const { return Vector2::Dot(*this, vec); }

    /* v1.x*v2.y - v2.x*v2.y */
    constexpr float Cross(const Vector2& vec) const { return Vector2::Cross(*this, vec); }

    /* len(v1) % len(v2) */
    constexpr float Mod(const Vector2& vec) const { return Vector2::Mod(*this, vec); }

    /** 
     * Dot product operator
     * - v1.x*v2.x + v1.x*v2.x 
    */
    friend constexpr float operator|(Vector2 v1, const Vector2& v2) { return Vector2::Dot(v1, v2); }

    /**
     * Cross product operator
     * - v1.x*v2.y - v1.y*v2.x
     */
    friend constexpr float operator^(Vector2 v1, const Vector2& v2) { return Vector2::Cross(v1, v2); }

    /**
     * Modulo of len(v1) and len(v2)
     * - sqrt(v1.x*v1.x + v1.y*v1.y) % sqrt(v2.x*v2.x + v2.y*v2.y)
     */
    friend constexpr float operator%(Vector2 v1, const Vector2& v2) { return Vector2::Mod(v1, v2); }

    /**
     * ### Get normalized length of the vector.
     * If len = 0, return the vector as-is
     * else x/len, y/len
     */
    Vector2 GetNormal() const {
        float len = Length();
        return (len == 0.f) ? Vector2{} : Vector2(x/len, y/len);
    }
    /**
     * ### Normalize the length of the vector
     * If len = 0, return the vector as-is
     * else x/len, y/len
     */
    Vector2& Normalize() { return *this = GetNormal(); }

    /**
     * ### Get distance between v1 and v2
     * len(v1 - v2)
     */
    static float Distance(const Vector2& v1, const Vector2& v2) { return (v1 - v2).Length(); }

    /**
     * ### Get distance between current vector and goal vector
     * len(v1 - v2)
     */
    constexpr float Distance(const Vector2& vec) { return (*this - vec).Length(); }

    /* ### Vector2(0,0) */
    static constexpr Vector2 Zero() { return Vector2(0.f, 0.f); }
    
    /* ### Set vector to (0,0) */
    Vector2& New() { return *this = Vector2::Zero(); }

    /**
     * Translates the Vector2 into a const char* string
     * - "Vector2(X, Y)"
     */
    static const char* c_str(const Vector2& vec) {
        thread_local static char buffer[64];
        std::snprintf(buffer, sizeof(buffer), "Vector2(%f, %f)", vec.x, vec.y);
        return buffer;
    }
    /**
     * "Vector2(X, Y)"
     */
    const char* c_str() { return Vector2::c_str(*this); }

};

/** 
 * Global c_str formatting. Drop a Vector2D object
 * into most strings and it should fit in.
 * #### format: "Vector2(X, Y)"
 * - std::ptintln("my vector: {}", myVector2);
 * - std::cout << myVector2 << std::endl;
 * - std::string str = {"my vector2 object: ", myVector2}; 
 */
template<>
struct std::formatter<Vector2> : std::formatter<const char*> {
    auto format(const Vector2& vec, auto& ctx) const {
        return std::formatter<const char*>::format(Vector2::c_str(vec), ctx);
    }
};

#endif /* VECTOR2_HPP */