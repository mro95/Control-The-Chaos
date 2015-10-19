#include "SinglePlayer.hpp"

SinglePlayer::SinglePlayer()
{
    initialize();
}

void SinglePlayer::initialize()
{
    b1 = new Ball( vec2(200,200) );
    b1->v = vec2(50, 0);
    b1->updateR(30);
    b1->mass = 30*30;
    b1->setRGB(0,0,255);
}

void SinglePlayer::render() 
{
    b1->draw();
}

void SinglePlayer::update( double dt )
{
    b1->update( dt );
}
