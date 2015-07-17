#include "shapes/circle.hpp"
#include "stage.hpp"
#include "settings.hpp"
#include "stage/stagecircle.hpp"
#include <GL/glut.h>
#include <list>

#define max_balls 5

Stage::Stage()
{
    stageCircle = new StageCircle();

    Ball* b1 = new Ball( vec2( 200, 0) );
    b1->updateR(30);
    b1->v = vec2(-20, 0);
    b1->setRGB(0,0,255);
    balls[0].set(b1);

    Ball* b2 = new Ball( vec2 (-200, 0) );
    b2->updateR(30);
    b2->v = vec2(20, 0);
    b2->setRGB(0,255,0);
    balls[1].set(b2);

    Ball* b3 = new Ball( vec2(0, -200) );
    b3->updateR(30);
    b3->v = vec2(0, 20);
    b1->setRGB(0,0,255);
    balls[2].set(b3);

    for(int i=0;i<max_balls+1;i++) {
        double x = rand() % 500 -250;
        double y = rand() % 500 -250;
        double dx = x * 0.5;
        double dy = y * 0.5;
        Ball* b1 = new Ball( vec2(x, y) );
        b1->updateR(i*10);
        b1->mass = i*10;
        b1->v = vec2(dx, dy);
        b1->setRGB(0,0,255);
        balls[i].set(b1);
    }
    
    //cols.push_back( vec2(34,56) );
    //cols.push_back( vec2(79,0) );
}

void Stage::render()
{

    stageCircle->draw();

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
    //if(glfwGetTime() > 10 && glfwGetTime() < 20)
    //    usleep(1000000);
    for(int i=0;i<max_balls;i++) 
    {
        Ball* b = balls[i].get();

        int collisions = false;
        if( stageCircle->ballCollision(b) ) {
            b->bounce( b->p );
            b->update( dt );
            //b->flip();
        }

        //for(int j=0;j<max_balls;j++)
        for(int j= i+1;j<max_balls;j++)
        {
            Ball* other = balls[j].get();
            // vec2 op = other->p;
            // if( other->ballCollision(b) )
            // {
            //     collisions = true;
            //     cols.push_back( other->drawCollision( b ) ); // Draw collision
            //     other->ballBounce( b, dt );
            // }
            if( b->ballCollision(other) )
            {
                collisions = true;
                cols.push_back( b->drawCollision( other ) ); // Draw collision
                b->ballBounce( other, dt );
            }
            b->update( dt );
            other->update( dt );
        }

    }
}
