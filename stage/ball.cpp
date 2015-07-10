#include "ball.hpp"
#include "../shapes/circle.hpp"
#include "../settings.hpp"

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
    p = p + v * 1 * dt;
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

void Ball::bounce( vec2 other )
{
    vec2 norm = vec2(other.x, other.y);
    //vec2 norm = vec2(v.x, v.y);
    norm.normalize();

    v = v - (norm * (vec2::dot2(v,norm) * 2));

    std::cout << v.x << std::endl;
}
