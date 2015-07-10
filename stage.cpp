#include "shapes/circle.hpp"
#include "stage.hpp"
#include "settings.hpp"
#include "stage/stagecircle.hpp"

#define max_balls 3

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

    //for(int i=0;i<5;i++) {
    //    double x = -250+(rand()%(250-(-250)));
    //    double y = rand() % 250;
    //    Ball* b1 = new Ball( vec2(x, y) );
    //    b1->v = vec2(300, -100);
    //    b1->setRGB(0,0,255);
    //    b1->r = 15;
    //    balls[i].set(b1);
    //}
}

void Stage::render()
{
    stageCircle->draw();

    for(int i=0;i<max_balls;i++) {
        Ball* b = balls[i].get();
        b->draw();
    }
}

void Stage::update( double dt )
{
    for(int i=0;i<max_balls;i++) {
        Ball* b = balls[i].get();

        if( stageCircle->ballCollision(b) ) {
            b->bounce( b->p );
            //b->flip();
        }

        for(int j=0;j<max_balls;j++) {
            if( i == j )
                continue;
            Ball* other = balls[j].get();
            if( b->ballCollision(other) )
            {
                b->bounce( other->v );
                //other->bounce( b->p );
            }
        }

        b->update( dt );
    }
}
