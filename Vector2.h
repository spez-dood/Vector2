#pragma once
#ifndef VECTOR2_H
#define VECTOR2_H

#ifdef __cplusplus
#include <cmath>
#else
#include <math.h>
#include <stdbool.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define Num_Len(t, m) ( (m) > 0 ? (t)sqrtf((m)) : 0 )

#define V2_SqMag(v) ( (v).x * (v).x + (v).y * (v).y )
#define V2_Len(t, v) ( Num_Len(t, V2_SqMag(v)) )

#define V2_Dot(a, b) ( (a).x * (b).x + (a).y * (b).y )
#define V2_Cross(a, b) ( (a).x * (b).y - (a).y * (b).x )

#define V2_InBounds(v, size, pos) ( ((v).x >= (pos).x) && ((v).x <= (pos).x + (size).x) && \
                                    ((v).y >= (pos).y) && ((v).y <= (pos).y + (size).y) )

#define V2_InRect(v, rect) ( ((v).x >= (rect).x) && ((v).x <= (rect).x + (rect).w) && \
                             ((v).y >= (rect).y) && ((v).y <= (rect).y + (rect).h) )

#define V2_Add(t, a, b) ( (t){(a).x + (b).x, (a).y + (b).y} )
#define V2_Sub(t, a, b) ( (t){(a).x - (b).x, (a).y - (b).y} )
#define V2_Mul(t, a, b) ( (t){(a).x * (b).x, (a).y * (b).y} )
#define V2_Div(t, a, b) ( (t){(a).x / (b).x, (a).y / (b).y} )

#define V2_Normal(t, v, len) ( (len) > 0 ? (t){(v).x / len, (v).y / len} : (t){0, 0} )
#define V2_Dist(t, tt, a, b) ( V2_Len(tt, V2_Sub(t, a, b)) )

typedef struct { int x; int y; } Vector2Int;
typedef struct { float x; float y; } Vector2Float;

inline Vector2Int V2_AddI(Vector2Int a, Vector2Int b) { return V2_Add(Vector2Int, a, b); }
inline Vector2Int V2_SubI(Vector2Int a, Vector2Int b) { return V2_Sub(Vector2Int, a, b); }
inline Vector2Int V2_MulI(Vector2Int a, Vector2Int b) { return V2_Mul(Vector2Int, a, b); }
inline Vector2Int V2_DivI(Vector2Int a, Vector2Int b) { return V2_Div(Vector2Int, a, b); }

inline Vector2Int V2_NormalI(Vector2Int vec) { return V2_Normal(Vector2Int, vec, V2_Len(int, vec)); }
inline float V2_DistI(Vector2Int a, Vector2Int b) { return V2_Dist(Vector2Int, int, a, b); }

inline Vector2Float V2_AddF(Vector2Float a, Vector2Float b) { return V2_Add(Vector2Float, a, b); }
inline Vector2Float V2_SubF(Vector2Float a, Vector2Float b) { return V2_Sub(Vector2Float, a, b); }
inline Vector2Float V2_MulF(Vector2Float a, Vector2Float b) { return V2_Mul(Vector2Float, a, b); }
inline Vector2Float V2_DivF(Vector2Float a, Vector2Float b) { return V2_Div(Vector2Float, a, b); }

inline Vector2Float V2_NormalF(Vector2Float vec) { return V2_Normal(Vector2Float, vec, V2_Len(float, vec)); }
inline float V2_DistF(Vector2Float a, Vector2Float b) { return V2_Dist(Vector2Float, float, a, b); }

#ifdef __cplusplus
}

struct Vector2 : public Vector2Float {
    static Vector2 GetNormal(const Vector2& vec) { return V2_Normal(Vector2, vec, V2_Len(float, vec)); }
    Vector2 GetNormal() { return V2_Normal(Vector2, *this, V2_Len(float, *this)); }
    static float GetDistance(const Vector2& a, const Vector2& b) { return V2_Dist(Vector2, float, a, b); }
    float GetDistance(const Vector2& vec) { return V2_Dist(Vector2, float, *this, vec); }

    inline Vector2() : Vector2Float{0.0f, 0.0f} {}
    inline Vector2(float x, float y) : Vector2Float{x, y} {}
    inline Vector2(const Vector2& v) : Vector2Float{v.x, v.y} {}
    inline Vector2(Vector2&& v) noexcept : Vector2Float{v.x, v.y} {}

    inline Vector2& operator=(const Vector2& v) {
        x = v.x; y = v.y;
        return *this;
    }
};

inline constexpr Vector2& operator+=(Vector2& a, const Vector2& b) { return a = V2_Add(Vector2, a, b); }
inline constexpr Vector2& operator-=(Vector2& a, const Vector2& b) { return a = V2_Sub(Vector2, a, b); }
inline constexpr Vector2& operator*=(Vector2& a, const Vector2& b) { return a = V2_Mul(Vector2, a, b); }
inline constexpr Vector2& operator/=(Vector2& a, const Vector2& b) { return a = V2_Div(Vector2, a, b); }

inline constexpr Vector2& operator*=(Vector2& v, float s) { v.x *= s; v.y *= s; return v; }
inline constexpr Vector2& operator/=(Vector2& v, float s) { v.x /= s; v.y /= s; return v; }

inline constexpr Vector2 operator+(Vector2 a, const Vector2& b) { return a += b; }
inline constexpr Vector2 operator-(Vector2 a, const Vector2& b) { return a -= b; }
inline constexpr Vector2 operator*(Vector2 a, const Vector2& b) { return a *= b; }
inline constexpr Vector2 operator/(Vector2 a, const Vector2& b) { return a /= b; }

inline constexpr Vector2 operator*(Vector2 vec, float s) { return vec *= s; }
inline constexpr Vector2 operator/(Vector2 vec, float s) { return vec /= s; }

inline constexpr bool operator==(const Vector2& a, const Vector2& b) { return a.x == b.x && a.y == b.y; }
inline constexpr bool operator!=(const Vector2& a, const Vector2& b) { return !(a == b); }

inline constexpr float operator|(const Vector2& a, const Vector2& b) { return V2_Dot(a, b); }
inline constexpr float operator^(const Vector2& a, const Vector2& b) { return V2_Cross(a, b); }

#endif // __cplusplus

#endif /* VECTOR2_H */