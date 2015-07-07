#ifndef BALL_H
#define BALL_H

#include "../shapes/circle.hpp"

class Ball
{
    public:

        int x;
        int y;
        int dx;
        int dy;
        double r;
        Circle* circle;

        Ball();
        void draw();
        void update( double dt );
        void flipY();


};

#endif // BALL_H
