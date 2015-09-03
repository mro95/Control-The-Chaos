#ifndef _GameLoop_H_
    #define _GameLoop_H_

#include <math.h>
#include <GLFW/glfw3.h>
#include "../library/settings.hpp"
#include "../library/text.hpp"

# define PI           3.14159265358979323846  /* pi */
# define TAU          6.28318530717958647692  /* tau */

using string = std::string;
class GameLoop {
    public:

        bool pause = false;
        bool smallPause = false;
        bool running = true;
        bool debugMode = false;
        bool mainmenu = true;
        GLFWwindow* window;
        Settings* settings;

        int execute()
        {
            double MAX_DT = 0.025;
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

                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                //render( );
                while(game_now < now) {
                    if( !pause )
                        update( game_dt );
                    else if( smallPause )  {
                        update( game_dt );
                        smallPause = false;
                    }
                    game_now += game_dt;
                    reps++;
                }

                fps += (int) 1/dt;
                fps_count++;
                if(fps_count >= 60) {
                    if( debugMode )
                        printf("now=%8.4f  game_now=%8.4f  dt=%6.4f  game_dt=%6.4f  reps=%d fps=%6i \n",
                                now, game_now, dt, game_dt, reps, fps/fps_count);
                    fps_count = 0;
                    fps=0;
                }
                render( );
                lastFrame = now;

                if(fps > 65) {
                    usleep(5000);
                }

                glfwSwapBuffers(window);
                glfwPollEvents();
            }
            glfwDestroyWindow(window);
            glfwTerminate();
            exit(EXIT_SUCCESS);

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
            window = glfwCreateWindow(windowWidth, windowHeight, "Control The Chaos", NULL, NULL);
            if (!window)
            {
                glfwTerminate();
                return false;
            }

            /* Make the window's context current */
            glfwMakeContextCurrent(window);

            glfwSwapInterval(1);

            glfwSetKeyCallback(window, keyboardInput);

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
            if (mainmenu) {
                //mainmenuRender();
            }
            Text text;
            double sx = 10;
            double sy = 10;
            text.loadFontLibs();
            text.render("The Small Texture Scaled Fox Jumps Over The Lazy Dog",
                -1 + 8 * sx,   1 - 175 * sy,   sx * 0.5, sy * 0.5);

        }

        void update( double dt )
        {

        }

        static void keyboardInput(GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                glfwSetWindowShouldClose(window, GL_TRUE);
        }
};

bool debugMode = false;
//static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
//void DrawCircle(float cx, float cy, float r);

#endif
