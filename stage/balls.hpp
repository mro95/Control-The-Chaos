#ifndef balls_h
#define balls_h

class Balls
{
    public:
    
        Ball* ball;

        void set( Ball* b )
        {
            ball = b;
        }

        Ball* get( )
        {
            return ball;
        }
}

#endif
