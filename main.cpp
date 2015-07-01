#include <iostream>
#include <unistd.h>
#include <cmath>

#include "main.hpp"
#include "stage.hpp"


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

    while (!glfwWindowShouldClose(window))
    {
        // GAME LOOP!!!
        now = glfwGetTime();
        dt = now - lastFrame;
        lastFrame = now;

        update( dt );
        render();
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
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    int height2 = Settings::windowHeight;
    int width2 = Settings::windowWidth;
    double top = -(height2/2);
    double bottom = height2/2;
    double left = -(width2/2);
    double right = width2/2;

    glViewport(0, 0, width, height);

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
