
#ifndef arc_H
    #define arc_H

#include <cmath>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <GLFW/glfw3.h>
#include "../vec2.hpp"

# define PI           3.14159265358979323846  /* pi */
# define TAU          6.28318530717958647692  /* tau */

class Arc 
{
    public:

        vec2 p = vec2(0,0);
        double a;
        double r;

        int rgb[3];
        double lineWidth = 5;

        void setRgb( double r, double g, double b )
        {
            rgb[0] = r;
            rgb[1] = g;
            rgb[2] = b;
        }

        void draw(float cx, float cy, float r, float start_angle, float arc_angle, int num_segments)
        {
            float theta = arc_angle / float(num_segments - 1);//theta is now calculated from the arc angle instead, the - 1 bit comes from the fact that the arc is open

            float tangetial_factor = tanf(theta);

            float radial_factor = cosf(theta);


            float x = r * cosf(start_angle);//we now start at the start angle
            float y = r * sinf(start_angle); 

            glBegin(GL_LINE_STRIP);//since the arc is not a closed curve, this is a strip now
            for(int ii = 0; ii < num_segments-1; ii++)
            { 
                glVertex2f(x + cx, y + cy);

                float tx = -y; 
                float ty = x; 

                x += tx * tangetial_factor; 
                y += ty * tangetial_factor; 

                x *= radial_factor; 
                y *= radial_factor; 
            } 
            glEnd(); 
        }

    private:

};

#endif
