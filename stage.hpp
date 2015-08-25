#ifndef _stage_H_
    #define _stage_H_

#include <deque>
#include <map>
#include <list>

#include <math.h>
#include <cmath>
#include <GLFW/glfw3.h>

#include "shapes/circle.hpp"
#include "stage/stagecircle.hpp"
#include "stage/balls.hpp"

# define PI           3.14159265358979323846  /* pi */
# define TAU          6.28318530717958647692  /* tau */

class Stage {
    public:

        Stage();
        void render();
        void update( double dt );
        void checkCollisions( double dt );
        int constraints( double dt );
        void dirtyCollisionHack( double dt );
        std::list<vec2> cols;
        std::deque<std::map<int, Ball*>> collisions;

    private:

        StageCircle* stageCircle;
        Ball* ball1;
        Balls balls[];
        void situation1();
        void situation2();
        void situation3();
        void situation4();
};

#endif
