#include "SinglePlayer.hpp"

SinglePlayer::SinglePlayer()
{
    initialize();
}

void SinglePlayer::initialize()
{

    Ball* b1 = new Ball( vec2(200,200) );
    b1->v = vec2(50, 0);
    b1->updateR(30);
    b1->mass = 30*30;
    b1->setRGB(0,0,255);
    Balls.push_back( b1 );

    Ball* b2 = new Ball( vec2(200,200) );
    b2->v = vec2(0, 50);
    b2->updateR(30);
    b2->mass = 30*30;
    b2->setRGB(255,0,0);
    Balls.push_back( b2 );
}

void SinglePlayer::render() 
{
    for (std::list<Ball*>::iterator b=Balls.begin(); b != Balls.end(); ++b) {
        Ball* ball = (*b);
        ball->draw();
    }
}

void SinglePlayer::update( double dt )
{
    for (std::list<Ball*>::iterator b=Balls.begin(); b != Balls.end(); ++b) {
        Ball* ball = (*b);
        ball->update( dt );
    }
}
