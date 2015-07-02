#ifndef BALL_H
#define BALL_H


class Ball
{
    public:

        int x;
        int y;
        int dx;
        int dy;
        double r;

        Ball();
        void draw();
        void update( double dt );


};

#endif // BALL_H
