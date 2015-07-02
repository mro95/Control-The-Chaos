#ifndef _circle_H_
    #define _circle_H_

#include <cmath>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <GLFW/glfw3.h>

# define PI           3.14159265358979323846  /* pi */
# define TAU          6.28318530717958647692  /* tau */

class Circle {
    public:
        int cx, cy, r;
        float lineWidth;

        Circle(int cx, int cy, int r);
        void setLineWidth( float w );
        void drawLineCircle();
        void drawFilledCircle();
        void setCx( int cx );
        void setCy( int cy );

    private:

};

#endif
