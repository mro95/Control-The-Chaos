#include "circle.hpp"

Circle::Circle(int cx, int cy, int r)
{
    this->cx = cx;
    this->cy = cy;
    this->r = r;
    this->lineWidth = 1;
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
        glVertex2d(cx + r * cos(a), cy + r * sin(a));
    }
    glEnd();
}

void Circle::drawFilledCircle( )
{
    int seg = 64;
    double circle_step = TAU / seg;

    glLineWidth((GLfloat) this->lineWidth);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for(double a = 0; a < TAU; a += circle_step) 
    {
        glVertex2f(cx + r * cos(a), cy + r * sin(a));
    }
    glEnd();
}
