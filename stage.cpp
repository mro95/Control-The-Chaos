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

    Ball* b1 = new Ball();
    b1->x = 50;
    b1->y = 100;
    b1->r = 15;
    b1->dx = 300;
    b1->dy = -100;
    b1->setRGB(0,0,255);
    balls[0].set(b1);

    Ball* b2 = new Ball();
    b1->x = 100;
    b1->y = 50;
    b2->r = 15;
    b2->dx = -200;
    b2->dy = 200;
    b2->setRGB(0,255,0);
    balls[1].set(b2);

    Ball* b3 = new Ball();
    b3->r = 15;
    b3->dx = 200;
    b3->dy = 50;
    b1->setRGB(0,0,255);
    balls[2].set(b3);
}

void Stage::render()
{
    stageCircle->draw();

    for(int i=0;i<3;i++) {
        Ball* b = balls[i].get();
        b->draw();
    }
}

void Stage::update( double dt )
{
    for(int i=0;i<3;i++) {
        Ball* b = balls[i].get();

        if( stageCircle->ballCollision(b) ) {
            b->flip();
        }

        for(int j=0;j<3;j++) {
            if( i == j )
                continue;
            Ball* other = balls[j].get();
            if( b->ballCollision(other) )
            {
                b->flip();
                other->flip();
                printf("dx = %i dy = %i \n", b->dx - other->dx, b->dy - other->dy);
            }
            //else
                //std::cout << "no:" << j << std::endl;
        }

        b->update( dt );
    }
}
