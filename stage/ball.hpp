#ifndef BALL_H
#define BALL_H

#include "../vec2.hpp"
#include "../shapes/circle.hpp"

class Ball
{
    public:

        vec2 p = vec2(0,0);  // Position
        vec2 v = vec2(0,0);  // Velocity
        vec2 pv = vec2(0,0); // Previous Velocity
        double r; // Radius
        double mass = 5.0;
        Circle* circle;

        Ball( vec2 p );
        void draw();
        void update( double dt );
        void updateR( double r );
        void flip();
        void setRGB(int r, int g, int b);

        bool ballCollision( Ball* other );
        vec2 drawCollision( Ball* other );
        void bounce( vec2 other );
        void ballBounce( Ball* other, double dt );


};

#endif // BALL_H
