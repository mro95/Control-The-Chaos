#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include "circle.hpp"

Circle::Circle(vec2 p, int r)
{
    this->p = p;
    this->r = r;
    this->lineWidth = 1;
    rgb[0] = 0;
    rgb[1] = 0;
    rgb[2] = 0;
}

void Circle::setRGB( int r, int g, int b )
{
    rgb[0] = r/255;
    rgb[1] = g/255;
    rgb[2] = b/255;
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
    glColor3d(rgb[0], rgb[1], rgb[2]);
    for(double a = 0; a < TAU; a += circle_step) 
    {
        glVertex2d(p.x + r * cos(a), p.y + r * sin(a));
    }
    glEnd();
}

void Circle::drawFilledCircle( )
{
    int seg = 64;
    double circle_step = TAU / seg;
    glLineWidth((GLfloat) this->lineWidth);
    glBegin(GL_TRIANGLE_FAN);
    glColor3d(rgb[0], rgb[1], rgb[2]);
    glVertex2d(p.x, p.y);
    for(double a = 0; a < TAU; a += circle_step) 
    {
        glVertex2d(p.x + r * cos(a), p.y + r * sin(a));
    }
    glEnd();
}
