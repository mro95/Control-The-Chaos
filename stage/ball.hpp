#ifndef BALL_H
#define BALL_H

#include "../vec2.hpp"
#include "../shapes/circle.hpp"

class Ball
{
    public:

        vec2 p = vec2(0,0);
        vec2 v = vec2(0,0);
        double r;
        Circle* circle;

        Ball( vec2 p );
        void draw();
        void update( double dt );
        void flip();
        void setRGB(int r, int g, int b);

        bool ballCollision( Ball* other );
        void bounce( vec2 other );


};

#endif // BALL_H
