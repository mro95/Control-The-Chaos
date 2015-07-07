#include "ball.hpp"
#include "../shapes/circle.hpp"

Ball::Ball()
{
    x = 0;
    y = 0;
    r = 30;
    dx = 0;
    dy = 0;
    circle = new Circle(x,y,r);
}

void Ball::draw()
{
    circle->drawFilledCircle();
}

void Ball::setRGB(int r, int g, int b)
{
    circle->setRGB(r,g,b);
}

void Ball::update( double dt )
{
    x = x + dx * dt;
    y = y + dy * dt;
    circle->setX(x);
    circle->setY(y);
}

void Ball::flip()
{
    dy = -(dy);
    dx = -(dx);
}

bool Ball::ballCollision( Ball* other )
{
    int dx = other->x - this->x;
    int dy = other->y - this->y;
    int dr = other->r*2 + this->r*2;
    if( dx*dx + dy*dy < dr*dr) {
        return true;
    }
    return false;
}
