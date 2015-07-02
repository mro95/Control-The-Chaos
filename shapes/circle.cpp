#include <iostream>
#include "circle.hpp"

Circle::Circle(int cx, int cy, int r)
{
    this->cx = cx;
    this->cy = cy;
    this->r = r;
    this->lineWidth = 1;
}

void Circle::setCx( int cx )
{
    this->cx = cx;
}

void Circle::setCy( int cy )
{
    this->cy = cy;
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
    //std::cout << circle_step << "; ";

    glLineWidth((GLfloat) this->lineWidth);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(cx, cy);
    //for(double a = 0; a < TAU; a += circle_step) 
    for(double a = 0; a < 7; a += circle_step) 
    {
        glVertex2d(cx + r * cos(a), cy + r * sin(a));
    }
    //glVertex2d(cx-1, cy-1);
    glEnd();
}


//void Circle::drawFilledCircle( )
//{
//    int halfWidth = 400;
//    int halfHeight = 300;
//    glBegin(GL_TRIANGLES);
//
//    glVertex2f(-halfWidth, -halfHeight);
//
//    glVertex2f(-halfWidth, halfHeight);
//
//    glVertex2f(halfWidth, halfHeight);
//
//    glVertex2f(halfWidth, -halfHeight);
//
//    glEnd();
//}
