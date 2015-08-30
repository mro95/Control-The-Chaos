#ifndef _GameLoop_H_
    #define _GameLoop_H_

#include <math.h>
#include <GLFW/glfw3.h>
#include "../library/settings.hpp"

# define PI           3.14159265358979323846  /* pi */
# define TAU          6.28318530717958647692  /* tau */

class GameLoop {
    public:

        bool pause = false;
        bool smallPause = false;
        bool running = true;
        GLFWwindow* window;
        Settings* settings;

        int execute()
        {
            return 0;
        }

        bool initialize()
        {
            /* Initialize the library */
            if (!glfwInit())
                return false;
            
            int windowHeight = settings->getWindowHeight();
            int windowWidth = settings->getWindowWidth();

            /* Create a windowed mode window and its OpenGL context */
            glfwWindowHint(GLFW_FLOATING, true);
            glfwWindowHint(GLFW_RESIZABLE, false);
            glfwWindowHint(GLFW_SAMPLES, 16);
            window = glfwCreateWindow(windowWidth, windowHeight, "ControlTheChaos", NULL, NULL);
            if (!window)
            {
                glfwTerminate();
                return false;
            }

            /* Make the window's context current */
            glfwMakeContextCurrent(window);

            glfwSwapInterval(1);

            //glfwSetKeyCallback(window, key_callback);
            
            int bufferWidth, bufferHeight;
            glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);

            double top = -(windowHeight/2.0);
            double bottom = windowHeight/2.0;
            double left = -(windowWidth/2.0);
            double right = windowWidth/2.0;

            glViewport(0, 0, bufferWidth, bufferHeight);

            glClearColor(1, 1, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho( left, right, bottom, top, 1, -1 );


            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA); 

            glEnable(GL_LINE_SMOOTH);

            return true;
        }

        void render()
        {

        }

        void update( double dt )
        {

        }

};

//bool debugMode = false;
//static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
//void DrawCircle(float cx, float cy, float r);

#endif
