#include <iostream>
#include <unistd.h>
#include <cmath>

#include "main.hpp"
#include "vec2.hpp"
#include "stage.hpp"


#define MAX_DT 0.025

Main::Main( )
{
    running = true;
    window = NULL;
    debugMode = false;
}

int main(int argc, char* args[])
{
    Main game;
    game.execute();
}

int Main::execute( )
{
    if(!initialize())
        return -1;

    double lastFrame = glfwGetTime();
    double now;
    double dt;
    double game_now = lastFrame;

    int fps = 0;
    int fps_count = 0;


    while (!glfwWindowShouldClose(window))
    {
        now = glfwGetTime();
        dt = now - lastFrame;
        double game_dt = fmin(dt, MAX_DT);
        int reps = 0;
        while(game_now < now) {
            update( game_dt );
            game_now += game_dt;
            reps++;
        }

        fps += (int) 1/dt;
        fps_count++;
        if(fps_count >= 60) {
            printf("now=%8.4f  game_now=%8.4f  dt=%6.4f  game_dt=%6.4f  reps=%d fps=%6i \n", now, game_now, dt, game_dt, reps, fps/fps_count);
            fps_count = 0;
            fps=0;
        }
        render( );
        lastFrame = now;

        if(fps > 65) {
            usleep(5000);
        }
        //if(glfwGetTime() > 10 && glfwGetTime() < 20)
        //    usleep(1000000);
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);

    return 0;
}

bool Main::initialize( )
{
    /* Initialize the library */
    if (!glfwInit())
        return false;

    /* Create a windowed mode window and its OpenGL context */
    glfwWindowHint(GLFW_FLOATING, true);
    glfwWindowHint(GLFW_RESIZABLE, false);
    glfwWindowHint(GLFW_SAMPLES, 16);
    window = glfwCreateWindow(Settings::windowWidth, Settings::windowHeight, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return false;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    glfwSetKeyCallback(window, key_callback);

    return true;
}

void Main::update( double dt )
{
    stage.update(dt);
}

void Main::render( )
{
    int widtha, heighta;
    glfwGetFramebufferSize(window, &widtha, &heighta);

    int height2 = Settings::windowHeight;
    int width2 = Settings::windowWidth;
    double top = -(height2/2.0);
    double bottom = height2/2.0;
    double left = -(width2/2.0);
    double right = width2/2.0;

    glViewport(0, 0, widtha, heighta);

    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho( left, right, bottom, top, 1, -1 );
    //glMatrixMode(GL_MODELVIEW);

    //glDisable(GL_DEPTH_TEST);

    // Blended points, lines, and polygons.
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA); 

    //glEnable(GL_MULTISAMPLE);
    //glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    //glLoadIdentity();

    stage.render();

    glfwSwapBuffers(window);
    glfwPollEvents();
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    if (key == GLFW_KEY_F12 && action == GLFW_PRESS) {
        if(debugMode) {
            glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
            debugMode = false;
        } else {
            glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
            debugMode = true;
        }
    }
}

void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
