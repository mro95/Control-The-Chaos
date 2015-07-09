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

        void setX( double x )
        {
            this->x = x;
        }

        void setY( double y )
        {
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

        vec2 operator-(const float other)
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

        vec2 operator*(const float other)
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

        // Dot product
        double dot(vec2 other)
        {
            return this->x * other.x + this->y * other.y;
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

        // Polar coordinates
        double getPhi()
        {
            return atan2(y,x);
        }
        double getR() {
            return length();
        }
        vec2 setR(double r) {
            return (*this *= r / length());
        }
        vec2 setPhi(double phi) {
            return getR() * vec2(cos(phi), sin(phi))
        }

};

#endif
