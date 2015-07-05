#include "ball.hpp"
#include "../shapes/circle.hpp"

Ball::Ball()
{
    x = 0;
    y = 0;
    r = 0;
    dx = 0;
    dy = -300;
}

void Ball::draw()
{
    Circle* circle = new Circle(x,y,r);
    circle->drawFilledCircle();
}

void Ball::update( double dt )
{
    x += dx * dt;
    y += dy * dt;
}
