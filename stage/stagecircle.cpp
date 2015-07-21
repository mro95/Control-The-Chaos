#include <iostream>
#include "../shapes/circle.hpp"
#include "stagecircle.hpp"
#include "ball.hpp"
#include "../settings.hpp"

StageCircle::StageCircle()
{
    this->r = Settings::windowHeight/2-10;

    circle = new Circle(p,r);
    circle->setRGB(0,0,0);
    circle->setLineWidth(5.0);
}

void StageCircle::draw()
{
    circle->drawLineCircle();
}

bool StageCircle::ballCollision( Ball* ball )
{
    int x = ball->p.x;
    int y = ball->p.y;
    int r = this->r - ball->r;
    if( (x*x) + (y*y) > (r*r) ) {
        return true;
        std::cout << "yup" << std::endl;
    }
    return false;
}
