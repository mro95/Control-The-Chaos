#include "shapes/circle.hpp"
#include "stage.hpp" 
#include "settings.hpp"
#include "stage/stagecircle.hpp"


Stage::Stage()
{
    ball1 = new Ball();
    ball1->x = 0;
    ball1->y = 0;
    ball1->r = 15;
    stageCircle = new StageCircle();
}

void Stage::render()
{
    double windowWidth = Settings::windowWidth;
    double windowHeight = Settings::windowHeight;

    glColor3d(0, 0, 0);
    stageCircle->draw();

    //Circle* circle2 = new Circle(0,0,50);
    //circle2->drawFilledCircle();

    glColor3d(0, 0, 1);
    ball1->draw();

    //Circle* circle3 = new Circle(0,200,15);
    //circle3->drawFilledCircle();

}

void Stage::update( double dt )
{
    ball1->update( dt );

    if( stageCircle->ballCollision(ball1) ) {
        //std::cout << "true" << "\n";
        ball1->flipY();
    } else {
        //std::cout << ball1->y << "\n";
    }
}
