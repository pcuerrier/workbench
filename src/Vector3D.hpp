#pragma once

#include <cmath>

struct Vector3D
{
    float x = 0, y = 0, z = 0;

    Vector3D() = default;
    Vector3D(float x1, float y1, float z1) : x(x1), y(y1), z(z1) {}
    Vector3D(const Vector3D& other) : x(other.x), y(other.y), z(other.z) {}

    float& operator [](int i)
    {
        return ((&x)[i]);
    }

    const float& operator [](int i) const
    {
        return ((&x)[i]);
    }

    Vector3D& operator *=(float scalar)
    {
        x *= scalar; y *= scalar; z *= scalar;
        return (*this);
    }

    Vector3D& operator /=(float scalar)
    {
        scalar = 1.0f / scalar;
        x *= scalar; y *= scalar; z *= scalar;
        return (*this);
    }

    Vector3D& operator +=(const Vector3D& other)
    {
        x += other.x; y += other.y; z += other.z;
        return (*this);
    }

    Vector3D& operator -=(const Vector3D& other)
    {
        x -= other.x; y -= other.y; z -= other.z;
        return (*this);
    }
};

inline Vector3D operator +(const Vector3D& vectorA, const Vector3D& vectorB)
{
    return (Vector3D(vectorA.x + vectorB.x, vectorA.y + vectorB.y, vectorA.z + vectorB.z));
}

inline Vector3D operator -(const Vector3D& vectorA, const Vector3D& vectorB)
{
    return (Vector3D(vectorA.x - vectorB.x, vectorA.y - vectorB.y, vectorA.z - vectorB.z));
}

inline Vector3D operator *(const Vector3D& vector, float scalar)
{
    return (Vector3D(vector.x * scalar, vector.y * scalar, vector.z * scalar));
}

inline Vector3D operator /(const Vector3D& vector, float scalar)
{
    scalar = 1.0f / scalar;
    return (Vector3D(vector.x * scalar, vector.y * scalar, vector.z * scalar));
}

inline Vector3D operator -(const Vector3D& vector)
{
    return (Vector3D(-vector.x, -vector.y, -vector.z));
}

inline float Magnitude(const Vector3D& vector)
{
    return (sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z));
}

inline Vector3D Normalize(const Vector3D& vector)
{
    return (vector / Magnitude(vector));
}
