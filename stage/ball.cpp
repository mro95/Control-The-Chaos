#include "ball.hpp"
#include "../shapes/circle.hpp"

Ball::Ball()
{
    x = 0;
    y = 0;
    r = 30;
    dx = -500;
    dy = 300;
    circle = new Circle(x,y,r);
}

void Ball::draw()
{
    circle->drawFilledCircle();
}

void Ball::update( double dt )
{
    x = x + dx * dt;
    y = y + dy * dt;
    circle->setX(x);
    circle->setY(y);
}

void Ball::flipY()
{
    dy = -(dy);
    dx = -(dx);
}
