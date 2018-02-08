#ifndef PRAX02_VECTOR2D_HPP
#define PRAX02_VECTOR2D_HPP

/**
 * Create class Vector representing a 2-dimensional vector
 * Let the coordinates of the vector be private.
 * Create a constructor Vector(dX,dY) which constructs vector from two lateral translation values
 * Implement the following methods:
 *     getX() -- returns the x value of the vector
 *     getY() -- returns the y value of the vector
 *     length() -- returns the length of the vector as double--precision floating-point value
 *                 Hint: use Euclidean norm to get the length of the vector
 *     negate() -- apply a negation operator to the vector
 *     scalarProduct(a) -- apply a scalar product operation to the vector
 *     vectorSum(Vector) -- add another vector to self
 *     normalize() -- normalize the vector. Hint: normalized vector has unchanged direction, but has unity length
 */

class Vector {
public:
    Vector(float dX, float dY);
    int getX();
    int getY();
    float length();
    void negate();
    void scalarProduct(int a);
    void vectorSum(const Vector& other);
    void normalize();
private:
    float x, y;
};

#endif //PRAX02_VECTOR2D_HPP
