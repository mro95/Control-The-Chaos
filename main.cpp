#include <iostream>
#include <unistd.h>
#include <cmath>

#include "main.hpp"
#include "circle.hpp"


Main::Main( )
{
    running = true;
    window = NULL;
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

    while (!glfwWindowShouldClose(window))
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        double top = -(height/2);
        double bottom = height/2;
        double left = -(width/2);
        double right = width/2;

        glViewport(0, 0, width, height);

        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho( left, right, bottom, top, 1, -1 );
        //glMatrixMode(GL_MODELVIEW);

        glDisable(GL_DEPTH_TEST);

        // Blended points, lines, and polygons.
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

        glEnable(GL_POINT_SMOOTH);
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_POLYGON_SMOOTH);
        //glLoadIdentity();
        
        glColor3d(0, 0, 0);
        Circle* circle1 = new Circle(0,0,(Main::windowHeight/2-10));
        circle1->setLineWidth(5.0);
        circle1->drawLineCircle();
        
        Circle* circle2 = new Circle(0,0,50);
        circle2->drawFilledCircle();

        glfwSwapBuffers(window);
        glfwPollEvents();
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
    window = glfwCreateWindow(Main::windowWidth, Main::windowHeight, "Hello World", NULL, NULL);
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
}

void Main::render( )
{
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
