#ifndef _stagecircle_H_
    #define _stagecircle_H_

#include <GLFW/glfw3.h>
#include "ball.hpp"

class StageCircle 
{
    public:
        vec2 p = vec2(0,0);
        int r;
        Circle* circle;

        StageCircle();
        void draw();
        bool ballCollision( Ball* ball, double dt );
};
#endif
