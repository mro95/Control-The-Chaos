#include "../shapes/circle.hpp"
#include "stagecircle.hpp"
#include "ball.hpp"
#include "../settings.hpp"

StageCircle::StageCircle()
{
}

void StageCircle::draw()
{
    double windowWidth = Settings::windowWidth;
    double windowHeight = Settings::windowHeight;

    glColor3d(0, 0, 0);
    Circle* circle1 = new Circle(0,0,(windowHeight/2-10));
    circle1->setLineWidth(5.0);
    circle1->drawLineCircle();
}

void StageCircle::ballCollision( Ball* ball )
{

}
