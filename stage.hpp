#ifndef _stage_H_
    #define _stage_H_

#include "shapes/circle.hpp"
#include "stage/stagecircle.hpp"
#include <math.h>
#include <cmath>
#include <GLFW/glfw3.h>

# define PI           3.14159265358979323846  /* pi */
# define TAU          6.28318530717958647692  /* tau */

class Stage {
    public:

        Stage();
        void render();
        void update( double dt );

    private:

        StageCircle* stageCircle;
        Ball* ball1;
};

#endif
