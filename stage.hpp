#ifndef _stage_H_
    #define _stage_H_

#include <math.h>
#include <cmath>
#include <GLFW/glfw3.h>
#include "circle.hpp"

# define PI           3.14159265358979323846  /* pi */
# define TAU          6.28318530717958647692  /* tau */

class Stage {
    public:

        Stage();
        void render();
        void update( double dt );

    private:
};

#endif
