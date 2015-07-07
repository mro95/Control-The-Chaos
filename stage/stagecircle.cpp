#include <iostream>
#include "../shapes/circle.hpp"
#include "stagecircle.hpp"
#include "ball.hpp"
#include "../settings.hpp"

StageCircle::StageCircle()
{
    this->r = Settings::windowHeight/2-10;
    circle = new Circle(0,0,r);
    circle->setRGB(0,0,0);
    circle->setLineWidth(5.0);
}

void StageCircle::draw()
{
    circle->drawLineCircle();
}

bool StageCircle::ballCollision( Ball* ball )
{
    int x = ball->x;
    int y = ball->y;
    int r = this->r - ball->r * 2 ;
    if( (x*x) + (y*y) > (r*r) ) {
        return true;
    }
    return false;
}
