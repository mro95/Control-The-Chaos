#ifndef Vec2D_H
#define Vec2D_H

#include <cmath>

# define PI           3.14159265358979323846  /* pi */
# define TAU          6.28318530717958647692  /* tau */

class Vec2D {

    public:
        double x;
        double y;

        Vec2D( double x, double y )
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

        // Addittion
        Vec2D operator+(const Vec2D& other)
        {
            return Vec2D(this->x + other.x,this->y + other.y);
        }

        Vec2D operator+(const float other)
        {
            return Vec2D(this->x + other,this->y + other);
        }


        // Subtraction
        Vec2D operator-(const Vec2D& other)
        {
            return Vec2D(this->x - other.x,this->y - other.y);
        }

        Vec2D operator-(const float other)
        {
            return Vec2D(this->x - other,this->y - other);
        }

        // Multiplication
        Vec2D operator*(const Vec2D& other)
        {
            return Vec2D(this->x * other.x ,this->y * other.y);
        }

        Vec2D operator*(const float other)
        {
            return Vec2D(this->x * other,this->y * other);
        }


        // Dot product
        double dot(Vec2D other)
        {
            return this->x * other.x + this->y * other.y;
        }


        // Length
        double length()
        {
            return sqrt(x*x + y*y);
        }

        double length2()
        {
            return x*x + y*y;
        }


        /** normalize the vector so that is has length unity
            returns the previous length of the factor */
        double normalize()
        {
            double norm = length();
            if(norm > 0.0) {
                double inv = 1.0/norm;
                x *= inv;
                y *= inv;
            }
            return norm;
        }




        // Phi
        double getPhi()
        {
            return atan2(y,x);
        }
};

#endif
