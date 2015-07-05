#ifndef _stagecircle_H_
    #define _stagecircle_H_

#include <GLFW/glfw3.h>
#include "ball.hpp"

class StageCircle 
{
    public:

        StageCircle();
        void draw();
        void ballCollision( Ball* ball );
};
#endif
