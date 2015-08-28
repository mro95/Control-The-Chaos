#include "shapes/circle.hpp"
#include "shapes/arc.hpp"
#include "stage.hpp"
#include "settings.hpp"
#include "stage/stagecircle.hpp"
#include <GL/glut.h>
#include <list>
#include <ctime>

int max_balls = 4;
Stage::Stage()
{
    std::srand(std::time(0));
    stageCircle = new StageCircle();

    this->situation2();
    std::cout << max_balls;
    //cols.push_back( vec2(34,56) );
    //cols.push_back( vec2(79,0) );
}

void Stage::render()
{

    stageCircle->draw();

    Arc g = Arc();
    //g.draw(0,0,60,-2.45,90,8);

    for(int i=0;i<max_balls;i++) {
        Ball* b = balls[i].get();
        b->draw();
    }

    int abc = false;

    // Draw collisions
    if (abc) {
        for (std::list<vec2>::iterator it=cols.begin(); it != cols.end(); ++it) {
            //std::cout << (*it).x << std::endl;
            glColor3d(1,0,0);
            glPointSize(15);
            glBegin(GL_POINTS);
            glVertex3d((*it).x, (*it).y, 0);
            glEnd();
        }
        cols.clear();
    }

    //glRasterPos2i(-500, -300);

    //std::string s = "Hallo";
    //
    //glColor3f(0.0f, 0.0f, 1.0f);
    //glTranslatef(0.0f, 0.0f, -5.0f);

    //void * font = GLUT_BITMAP_9_BY_15;
    //for (std::string::iterator i = s.begin(); i != s.end(); ++i)
    //{
    //    char c = *i;
    //    glutBitmapCharacter(font, c);
    //}
}

void Stage::update( double dt )
{
    // checking constraints
    int constraint = this->constraints(dt);
    if(constraint == -1)
        std::cout << "constraint error wall\n";
    if(constraint == -2)
        std::cout << "constraint error ball\n";

    for(int i=0;i<max_balls;i++)
    {
        Ball* b = balls[i].get();
        b->update( dt );
    }
    
    this->checkCollisions(dt);

    int constraint2 = this->constraints(dt);
    int contraint_counter = 0;
    //while(constraint2 < 0)
    //{
    //    this->checkCollisions(dt);
    //    constraint2 = this->constraints(dt);
    //    contraint_counter++;

    //    if(contraint_counter > 1000) {
    //        this->dirtyCollisionHack( dt );
    //        constraint2 = 0;
    //    }
    //}

    if( contraint_counter > 1 )
        std::cout << contraint_counter << std::endl;

}

void Stage::checkCollisions( double dt )
{
    for(int i=0;i<max_balls;i++)
    {
        Ball* b = balls[i].get();
        if( stageCircle->ballCollision(b, dt) ) {
            b->bounce( b->p );
        }
        for(int j= i+1;j<max_balls;j++)
        {
            Ball* other = balls[j].get();
            if( b->ballCollision(other, dt) )
            {
                //cols.push_back( b->drawCollision( other ) ); // Draw collision
                b->ballBounce( other, dt );
            }
        }
    }
}

int Stage::constraints( double dt )
{
    for(int i=0;i<max_balls;i++) {
        Ball* b = balls[i].get();
        //b->setRGB(0,0,255);
        if( stageCircle->ballCollision(b, dt) ) {
            //b->setRGB(255,0,0);
            return -1;
        }
        for(int j= i+1;j<max_balls;j++) {
            Ball* other = balls[j].get();
            if( b->ballCollision(other, dt) ) {
                //b->setRGB(0,255,0);
                return -2;
            }
        }
    }
    return 0;
}

void Stage::dirtyCollisionHack( double dt )
{
    for(int i=0;i<max_balls;i++) {
        Ball* b = balls[i].get();
        if( stageCircle->ballCollision(b, dt) ) {
            b->p = vec2(0,0);
        }
        for(int j= i+1;j<max_balls;j++) {
            Ball* other = balls[j].get();
            if( b->ballCollision(other, dt) ) {
                b->p -= b->r + other->r;
            }
        }
    }
}




// Situations
void Stage::situation1()
{
    max_balls = 4;
    Ball* b1 = new Ball( vec2( 0, 0) );
    b1->updateR(30);
    b1->mass = 30*30;
    b1->v = vec2(900, 900);
    b1->setRGB(0,0,255);
    balls[0].set(b1);

    Ball* b2 = new Ball( vec2 (50, 50) );
    b2->updateR(30);
    b2->mass = 30*30;
    b2->v = vec2(900, 900);
    b2->setRGB(0,255,0);
    balls[1].set(b2);

    Ball* b3 = new Ball( vec2(100, 100) );
    b3->updateR(30);
    b3->mass = 30*30;
    b3->v = vec2(900, 900);
    b3->setRGB(255,0,0);
    balls[2].set(b3);

    Ball* b4 = new Ball( vec2(150, 150) );
    b4->updateR(30);
    b4->mass = 30*30;
    b4->v = vec2(900, 900);
    b4->setRGB(0,100,155);
    balls[3].set(b4);
}
void Stage::situation2()
{
    max_balls = 2;
    Ball* b1 = new Ball( vec2( -200, 0) );
    b1->updateR(30);
    b1->mass = 30*30;
    b1->v = vec2(500, 0);
    b1->setRGB(0,0,255);
    balls[0].set(b1);

    Ball* b2 = new Ball( vec2 (200, 0) );
    b2->updateR(30);
    b2->mass = 30*30;
    b2->v = vec2(-500, 0);
    b2->setRGB(0,255,0);
    balls[1].set(b2);

}
void Stage::situation3()
{
    max_balls = 20;

    for(int i=0; i<21; i++) 
    {
        double rand1 = rand() % 4+1;
        double rand2 = rand() % 4+1;

        double x = 0;
        double y = 0;
        double dx = 0;
        double dy = 0;

        if(rand1 < 2) {
            x = rand() % -200 + (i+30);
            dx = rand() % -350 + -200;
        }else{
            x = rand() % 200 + (i+30);
            dx = rand() % 350 + 200;
        }

        if(rand2 < 2) {
            y = rand() % -200 + (i+30);
            dy = rand() % -350 + -200;
        }else{
            y = rand() % 200 + (i+30);
            dy = rand() % 350 + 200;
        }

        Ball* b1 = new Ball( vec2( x, y) );
        b1->updateR(15);
        b1->mass = 15*15;
        b1->v = vec2(dx, dy);
        b1->setRGB(0,0,255);
        balls[i].set(b1);
    }


}
