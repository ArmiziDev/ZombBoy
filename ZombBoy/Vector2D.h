// Vector2D.h

#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D {
public:
    float x, y;

    // Constructors
    Vector2D();
    Vector2D(float x, float y);


    // Vector operations
    Vector2D add(const Vector2D& v) const;
    Vector2D subtract(const Vector2D& v) const;
    Vector2D multiply(float scalar) const;
    float magnitude() const;
    Vector2D normalize() const;

    // Operator overloads for convenience
    Vector2D operator+(const Vector2D& v) const;
    Vector2D operator-(const Vector2D& v) const;
    Vector2D operator*(float scalar) const;
    Vector2D operator+=(Vector2D& other);
};

#endif // VECTOR2D_H
