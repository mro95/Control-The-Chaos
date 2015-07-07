#ifndef _circle_H_
    #define _circle_H_

#include <cmath>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <GLFW/glfw3.h>
#include "../vec2.hpp"

# define PI           3.14159265358979323846  /* pi */
# define TAU          6.28318530717958647692  /* tau */

class Circle {
    public:
        vec2 v;
        int r;
        float lineWidth;

        Circle(int cx, int cy, int r);
        void setLineWidth( float w );
        void drawLineCircle();
        void drawFilledCircle();
        void setX( int x );
        void setY( int y );

    private:

};

#endif
