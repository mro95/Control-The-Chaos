#ifndef _stagecircle_H_
    #define _stagecircle_H_

#include <GLFW/glfw3.h>
#include "ball.hpp"

class StageCircle 
{
    public:
        int r;
        Circle* circle;

        StageCircle();
        void draw();
        bool ballCollision( Ball* ball );
};
#endif
