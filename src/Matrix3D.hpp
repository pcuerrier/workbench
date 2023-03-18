#pragma once

#include "Vector3D.hpp"

struct Matrix3D
{
private:
    float n[3][3] = {{0, 0, 0},
                     {0, 0, 0},
                     {0, 0, 0}};

public:
    Matrix3D() = default;
    Matrix3D(float n00, float n01, float n02,
             float n10, float n11, float n12,
             float n20, float n21, float n22)
    {
        n[0][0] = n00; n[0][1] = n01; n[0][2] = n02;
        n[1][0] = n10; n[1][1] = n11; n[1][2] = n12;
        n[2][0] = n20; n[2][1] = n21; n[2][2] = n22;
    }
    Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c)
    {
        n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
        n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
        n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
    }
    Matrix3D(const Matrix3D& other)
    {
        n[0][0] = other.n[0][0]; n[0][1] = other.n[0][1]; n[0][2] = other.n[0][2];
        n[1][0] = other.n[1][0]; n[1][1] = other.n[1][1]; n[1][2] = other.n[1][2];
        n[2][0] = other.n[2][0]; n[2][1] = other.n[2][1]; n[2][2] = other.n[2][2];
    }

    float& operator ()(int i, int j)
    {
        return (n[j][i]);
    }

    const float& operator ()(int i, int j) const
    {
        return (n[j][i]);
    }

    Vector3D& operator [](int column)
    {
        return (*reinterpret_cast<Vector3D *>(n[column]));
    }

    const Vector3D& operator [](int column) const
    {
        return (*reinterpret_cast<const Vector3D *>(n[column]));
    }
};

Matrix3D operator *(const Matrix3D& A, const Matrix3D& B)
{
    return (Matrix3D(A(0,0) * B(0,0) + A(0,1) * B(1,0) + A(0,2) * B(2,0),
                     A(0,0) * B(0,1) + A(0,1) * B(1,1) + A(0,2) * B(2,1),
                     A(0,0) * B(0,2) + A(0,1) * B(1,2) + A(0,2) * B(2,2),
                     A(1,0) * B(0,0) + A(1,1) * B(1,0) + A(1,2) * B(2,0),
                     A(1,0) * B(0,1) + A(1,1) * B(1,1) + A(1,2) * B(2,1),
                     A(1,0) * B(0,2) + A(1,1) * B(1,2) + A(1,2) * B(2,2),
                     A(2,0) * B(0,0) + A(2,1) * B(1,0) + A(2,2) * B(2,0),
                     A(2,0) * B(0,1) + A(2,1) * B(1,1) + A(2,2) * B(2,1),
                     A(2,0) * B(0,2) + A(2,1) * B(1,2) + A(2,2) * B(2,2)));
}

Vector3D operator *(const Matrix3D& M, const Vector3D& v)
{
    return (Vector3D(M(0,0) * v.x + M(0,1) * v.y + M(0,2) * v.z,
                     M(1,0) * v.x + M(1,1) * v.y + M(1,2) * v.z,
                     M(2,0) * v.x + M(2,1) * v.y + M(2,2) * v.z));
}
