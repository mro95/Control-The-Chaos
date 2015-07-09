#include "shapes/circle.hpp"
#include "stage.hpp"
#include "settings.hpp"
#include "stage/stagecircle.hpp"


Stage::Stage()
{
    stageCircle = new StageCircle();

    Ball* b1 = new Ball( vec2( 200, 100) );
    b1->v = vec2(300, -100);
    b1->setRGB(0,0,255);
    b1->r = 15;
    balls[0].set(b1);

    Ball* b2 = new Ball( vec2 (0,-250) );
    b2->v = vec2(50, 100);
    b2->r = 15;
    b2->setRGB(0,255,0);
    balls[1].set(b2);

    Ball* b3 = new Ball( vec2(-250, 50) );
    b3->v = vec2(200, -150);
    b3->r = 15;
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
                //printf("dx = %i dy = %i \n", b->dx - other->dx, b->dy - other->dy);
            }
            //else
                //std::cout << "no:" << j << std::endl;
        }

        b->update( dt );
    }
}
