#include <iostream>
#include "circle.hpp"
#include "../vec2.hpp"

Circle::Circle(int cx, int cy, int r): v(0,0)
{
    this->v = vec2(cx, cy);
    this->r = r;
    this->lineWidth = 1;
}

void Circle::setX( int x )
{
    this->v.x = x;
}

void Circle::setY( int y )
{
    this->v.y = y;
}

void Circle::setLineWidth( float w )
{
    this->lineWidth = w;
}

void Circle::drawLineCircle( )
{
    int seg = 64;
    double circle_step = TAU / seg;

    glLineWidth((GLfloat) this->lineWidth);
    glBegin(GL_LINE_LOOP);
    for(double a = 0; a < TAU; a += circle_step) 
    {
        glVertex2d(v.x + r * cos(a), v.y + r * sin(a));
    }
    glEnd();
}

void Circle::drawFilledCircle( )
{
    int seg = 64;
    double circle_step = TAU / seg;
    glLineWidth((GLfloat) this->lineWidth);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(v.x, v.y);
    for(double a = 0; a < 7; a += circle_step) 
    {
        glVertex2d(v.x + r * cos(a), v.y + r * sin(a));
    }
    glEnd();
}
