#include "stage.hpp" 
#include "settings.hpp"


Stage::Stage()
{

}

void Stage::render()
{
    double windowWidth = Settings::windowWidth;
    double windowHeight = Settings::windowHeight;
    glColor3d(0, 0, 0);
    Circle* circle1 = new Circle(0,0,(windowHeight/2-10));
    circle1->setLineWidth(5.0);
    circle1->drawLineCircle();
    
    Circle* circle2 = new Circle(0,0,50);
    circle2->drawFilledCircle();

    glColor3d(0, 0, 1);
    Circle* circle3 = new Circle(0,200,15);
    circle3->drawFilledCircle();
}

void Stage::update( double dt )
{

}
