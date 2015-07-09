#include "ball.hpp"
#include "../shapes/circle.hpp"

Ball::Ball(vec2 p)
{
    r = 30;
    this->p = p;
    circle = new Circle(p,r);
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
    p = p + v * dt;
    circle->p = p;
}

void Ball::flip()
{
    v.y = -(v.y);
    v.x = -(v.x);
}

bool Ball::ballCollision( Ball* other )
{
    int dx = other->p.x - this->p.x;
    int dy = other->p.y - this->p.y;
    int dr = other->r*2 + this->r*2;
    if( dx*dx + dy*dy < dr*dr) {
        return true;
    }
    return false;
}
