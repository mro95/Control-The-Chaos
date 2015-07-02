#include "shapes/circle.hpp"
#include "stage.hpp" 
#include "settings.hpp"
#include "stagecircle.hpp"


Stage::Stage()
{
    ball1 = new Circle(0,0,15);
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
    //Circle* circle3 = new Circle(0,200,15);
    //circle3->drawFilledCircle();

    ball1->drawFilledCircle();
}

void Stage::update( double dt )
{
    //std::cout << dt * 100 << ";";

    ball1->setCx( ball1->cx + dt * -200 ) ;
    ball1->setCy( ball1->cy + dt * 200 ) ;
}
