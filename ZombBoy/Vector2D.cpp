// Vector2D.cpp

#include "Vector2D.h"
#include <cmath> // For sqrt

// Constructors
Vector2D::Vector2D() : x(0), y(0) {}
Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

// Vector operations
Vector2D Vector2D::add(const Vector2D& v) const {
    return Vector2D(x + v.x, y + v.y);
}

Vector2D Vector2D::subtract(const Vector2D& v) const {
    return Vector2D(x - v.x, y - v.y);
}

Vector2D Vector2D::multiply(float scalar) const {
    return Vector2D(x * scalar, y * scalar);
}

float Vector2D::magnitude() const {
    return std::sqrt(x * x + y * y);
}

Vector2D Vector2D::normalize() const {
    float mag = magnitude();
    if (mag > 0) {
        return multiply(1 / mag);
    }
    return Vector2D();
}

// Operator overloads
Vector2D Vector2D::operator+(const Vector2D& v) const {
    return add(v);
}

Vector2D Vector2D::operator-(const Vector2D& v) const {
    return subtract(v);
}

Vector2D Vector2D::operator*(float scalar) const {
    return multiply(scalar);
}

Vector2D Vector2D::operator+=(Vector2D& other) {
    x += other.x;
    y += other.y;

    // Return a reference to the current instance
    return *this;
}

Vector2D& Vector2D::operator+=(const Vector2D& other) {
    x += other.x;
    y += other.y;

    // Return a reference to the current instance
    return *this;
}
