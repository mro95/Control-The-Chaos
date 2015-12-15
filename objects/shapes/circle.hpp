#ifndef _circle_H_
    #define _circle_H_

#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <cmath>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include "../../library/vec2.hpp"

# define PI           3.14159265358979323846  /* pi */
# define TAU          6.28318530717958647692  /* tau */
# define toRadians(d) (d*PI/180)

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

        //static GLfloat vertices[]( int segments );
        static void vertices( GLfloat* v, int seg2 )
        {
            int seg = 64;
            double step = (PI*2) / seg;
            double r = 0.5;
            v[0] = 0.0f; v[1] = 0.0f;
            int n = 2;
            for(double i = 0; i <= TAU; i += step)  {
                v[n+0] = r * cos(i);
                v[n+1] = r * sin(i);
                n+=2;
            }
            v[n+0] = r;
            v[n+1] = 0;
        }

    private:

};

#endif
