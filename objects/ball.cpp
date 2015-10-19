#include "ball.hpp"

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

bool Ball::ballCollision( Ball* other, double dt )
{
    vec2 tp = this->p + (this->v * dt);
    vec2 op = other->p + (other->v * dt);

    double dx = (op.x - tp.x);
    double dy = (op.y - tp.y);

    //double dx = (other->p.x - this->p.x);
    //double dy = (other->p.y - this->p.y);
    double dr = other->r + this->r;
    if( dx*dx + dy*dy < dr*dr) {
        //printf("aaa=%f \n ", dx*dx + dy*dy );
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
    //printf("x:%f y:%f \n", point.x, point.y);

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
    //vec2 norm = (other->p + this->p)/2;
    //norm/2;
    //norm.normalize();
    //double v = (this->v.x * (this->mass – other->mass) + (2 * other->mass * other->v.x)) / (this->mass + this->mass);
    
    //this->p = other->p-(other->r*2);
    //other->p = this->p-this->r;

    vec2 v1 = this->v;
    vec2 v2 = other->v;
    double mass1 = this->mass;
    double mass2 = other->mass;


    pv = v;
    this->v = (v1 * (mass1 - mass2) + (v2 * ( mass2 * 2) )) / (mass1 + mass2);
    other->v = (v2 * (mass2 - mass1) + (v1 * ( mass1 * 2) )) / (mass1 + mass2);

    this->p += this->v * dt;
    other->p += other->v * dt;

    //printf("vx=%f vy=%f \n", v.x, v.y);
}
