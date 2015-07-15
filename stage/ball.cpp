#include "ball.hpp"
#include "../shapes/circle.hpp"
#include "../settings.hpp"

Ball::Ball(vec2 p)
{
    this->p = p;
    circle = new Circle(p,r);
}

void Ball::draw()
{
    circle->drawFilledCircle();
}

void Ball::updateR( double r )
{
    this->r = r;
    circle = new Circle(p,r);
}

void Ball::setRGB(int r, int g, int b)
{
    circle->setRGB(r,g,b);
}

void Ball::update( double dt )
{
    pv = v;
    p += v * dt;
    circle->p = p;
}

void Ball::flip()
{
    v.y = -(v.y);
    v.x = -(v.x);
}

bool Ball::ballCollision( Ball* other )
{
    double dx = other->p.x - this->p.x;
    double dy = other->p.y - this->p.y;
    double dr = other->r + this->r;
    if( dx*dx + dy*dy < dr*dr) {
        return true;
    }
    return false;
}

vec2 Ball::drawCollision( Ball* other )
{
    double x1 = this->p.x;
    double x2 = other->p.x;
    double y1 = this->p.y;
    double y2 = other->p.y;
    double r1 = this->r;
    double r2 = other->r;

    vec2 point = vec2( (x1 * r2 + x2 * r1) / (r1 + r2), (y1 * r2 + y2 * r1) / (r1 + r2) );
    //vec2 point = vec2( (x2+x1)/2, (y2+x1)/2 );
    printf("x:%f y:%f \n", point.x, point.y);

    return point;
}

void Ball::bounce( vec2 other )
{
    vec2 norm = vec2(other.x, other.y);
    norm/2;
    //vec2 norm = vec2(v.x, v.y);
    norm.normalize();

    pv = v;
    v = v - (norm * (vec2::dot2(v,norm) * 2));

    //std::cout << v.x << std::endl;
}

void Ball::ballBounce( Ball* other, double dt )
{
    vec2 norm = (other->p + this->p)/2;
    norm/2;
    norm.normalize();

    pv = v;
    v = pv - (norm * (vec2::dot2(pv,norm) * 2));

    //printf("v.x=%f v.y=%f \n", v.x, v.y);
}
