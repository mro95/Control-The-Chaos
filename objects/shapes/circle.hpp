#ifndef _circle_H_
    #define _circle_H_

#include <cmath>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include "../../library/vec2.hpp"

# define PI           3.14159265358979323846  /* pi */
# define TAU          6.28318530717958647692  /* tau */

class Circle {
    public:
        vec2 p = vec2(0,0);
        int r;
        int rgb[3];
        float lineWidth;

        Circle(vec2 p, int r);
        void setLineWidth( float w );
        void drawLineCircle();
        void drawFilledCircle();
        void setRGB( int r, int g, int b );

    private:

};

#endif
