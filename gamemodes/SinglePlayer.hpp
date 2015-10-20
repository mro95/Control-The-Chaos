#ifndef _SinglePlayer_H_
    #define _SinglePlayer_H_

#include <list>
#include "../objects/ball.hpp"
#include "../library/vec2.hpp"

# define PI           3.14159265358979323846  /* pi */
# define TAU          6.28318530717958647692  /* tau */

using string = std::string;
class SinglePlayer {
    public:

        SinglePlayer();
        void initialize();
        void update( double dt );
        void render();

        Ball* b1 ;
        
        std::list<Ball*> Balls;


};
#endif
