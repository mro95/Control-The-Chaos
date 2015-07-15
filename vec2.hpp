#ifndef vec2_H
#define vec2_H

#include <cmath>

# define PI           3.14159265358979323846  /* pi */
# define TAU          6.28318530717958647692  /* tau */

class vec2 {

    public:
        double x;
        double y;

        vec2( double x, double y )
        {
            this->x = x;
            this->y = y;
        }

        // Addition
        vec2 operator+(const vec2& other)
        {
            return vec2(this->x + other.x,this->y + other.y);
        }

        vec2 operator+(const float other)
        {
            return vec2(this->x + other,this->y + other);
        }

        vec2 operator+=(const vec2& other)
        {
            this->x += other.x;
            this->y += other.y;
            return *this;
        }

        vec2 operator+=(const float other)
        {
            this->x += other;
            this->y += other;
            return *this;
        }

        // Subtraction
        vec2 operator-(const vec2& other)
        {
            return vec2(this->x - other.x,this->y - other.y);
        }

        vec2 operator-(const double other)
        {
            return vec2(this->x - other,this->y - other);
        }

        vec2 operator-=(const vec2& other)
        {
            this->x -= other.x;
            this->y -= other.y;
            return *this;
        }

        vec2 operator-=(const float other)
        {
            this->x -= other;
            this->y -= other;
            return *this;
        }

        // Multiplication
        vec2 operator*(const vec2& other)
        {
            return vec2(this->x * other.x ,this->y * other.y);
        }

        vec2 operator*(const double other)
        {
            return vec2(this->x * other,this->y * other);
        }

        vec2 operator*=(const vec2& other)
        {
            this->x *= other.x;
            this->y *= other.y;
            return *this;
        }

        vec2 operator*=(const float other)
        {
            this->x *= other;
            this->y *= other;
            return *this;
        }

        // Division
        vec2 operator/(const vec2& other)
        {
            return vec2(this->x / other.x ,this->y / other.y);
        }

        vec2 operator/(const double other)
        {
            return vec2(this->x / other,this->y / other);
        }

        vec2 operator/=(const vec2& other)
        {
            this->x /= other.x;
            this->y /= other.y;
            return *this;
        }

        vec2 operator/=(const float other)
        {
            this->x /= other;
            this->y /= other;
            return *this;
        }

        // Dot product
        double dot(vec2 other)
        {
            return this->x * other.x + this->y * other.y;
        }

        double static dot2(vec2 a, vec2 b)
        {
            return a.x * b.x + a.y * b.y;
        }

        double length()
        {
            return sqrt(length2());
        }

        double length2()
        {
            return x*x + y*y;
        }

        /** normalize the vector so that is has length unity
            returns the previous length of the vector */
        double normalize()
        {
            double norm = length();
            if(norm > 0.0) {
                double inv = 1.0/norm;
                *this *= inv;
            }
            return norm;
        }

        vec2 normalize2()
        {
            double norm = length();
            if(norm > 0.0) {
                double inv = 1.0/norm;
                *this *= inv;
            }
            return *this;
        }

        // Polar coordinates
        double getPhi() {
            return atan2(y,x);
        }
        double getR() {
            return length();
        }

        vec2 setPhi( double phi ) {
            return vec2(cos(phi), sin(phi)) * getR();
        }
        vec2 setR( double r ) {
            return (*this *= r / length());
        }

        vec2 reflect( vec2 other )
        {
            vec2 o = vec2(other.x, other.y);
            o.normalize2();
            vec2 v = *this;
            return v - (o * (vec2::dot2(v, o) * 2)) ;
        }

};

#endif
