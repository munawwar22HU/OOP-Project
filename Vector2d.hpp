#pragma once
#include <iostream>

class Vector2d
{
public:
    float x;
    float y;

    Vector2d();
    Vector2d(float x, float y);

    Vector2d &Add(const Vector2d &vec);
    Vector2d &Subtract(const Vector2d &vec);
    Vector2d &Multiply(const Vector2d &vec);
    Vector2d &Divide(const Vector2d &vec);
    //v1.Add(v2) we write it as const as we don't want to change v2 and reference as we only want to read v2

    // Vector Overloading Funtcions used to perform basic vector arithmetic funtions
    friend Vector2d &operator+(Vector2d v1, const Vector2d &v2);
    friend Vector2d &operator-(Vector2d v1, const Vector2d &v2);
    friend Vector2d &operator*(Vector2d v1, const Vector2d &v2);
    friend Vector2d &operator/(Vector2d v1, const Vector2d &v2);

    Vector2d &operator+=(const Vector2d &vec);
    Vector2d &operator-=(const Vector2d &vec);
    Vector2d &operator*=(const Vector2d &vec);
    Vector2d &operator/=(const Vector2d &vec);

    friend std::ostream &operator<<(std::ostream &stream, const Vector2d vec);  // Prints vector class objects
};