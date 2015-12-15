#ifndef _GameLoop_H_
    #define _GameLoop_H_


#if defined(__APPLE__)
#include <OpenGL/gl3.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <math.h>
#include <GLFW/glfw3.h>
#include "../library/settings.hpp"
#include "../library/text.hpp"
#include "../gamemodes/SinglePlayer.hpp"


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

        SinglePlayer gamemode;


        int execute()
        {
            //Initialize Window
            if(!initialize())
                return -1;

            // Shader sources
            const GLchar* vertexSource =
                "#version 150 core\n"
                "in vec2 position;"
                "void main() {"
                "   gl_Position = vec4(position, 0.0, 1.0);"
                "}";
            const GLchar* fragmentSource =
                "#version 150 core\n"
                "out vec4 outColor;"
                "void main() {"
                "   outColor = vec4(1.0, 1.0, 1.0, 1.0);"
                "}";


            // Create Vertex Array Object
            GLuint vao;
            glGenVertexArrays(1, &vao);
            glBindVertexArray(vao);

            // Create a Vertex Buffer Object and copy the vertex data to it
            GLuint vbo;
            glGenBuffers(1, &vbo);

            //GLfloat vertices;
            GLfloat vertices[10000];
            Circle::vertices( vertices, 10 );

            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

            // Create and compile the vertex shader
            GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertexShader, 1, &vertexSource, NULL);
            glCompileShader(vertexShader);

            // Create and compile the fragment shader
            GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
            glCompileShader(fragmentShader);

            // Link the vertex and fragment shader into a shader program
            GLuint shaderProgram = glCreateProgram();
            glAttachShader(shaderProgram, vertexShader);
            glAttachShader(shaderProgram, fragmentShader);
            glBindFragDataLocation(shaderProgram, 0, "outColor");
            glLinkProgram(shaderProgram);
            glUseProgram(shaderProgram);

            // Specify the layout of the vertex data
            GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
            glEnableVertexAttribArray(posAttrib);
            glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

            //GLuint program = LoadShader("../shaders/circle.vs", "../shaders/circle.fs");
            //glUseProgram(program);

            //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );


            double MAX_DT = 0.025;


            //Init variables
            double lastFrame = glfwGetTime();
            double now;
            double dt;
            double game_now = lastFrame;
            int fps = 0;
            int fps_count = 0;

            //Window loop
            while (!glfwWindowShouldClose(window))
            {
                //set time variables
                now = glfwGetTime();
                dt = now - lastFrame;
                double game_dt = fmin(dt, MAX_DT);
                int reps = 0;

                //Fix time
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

                //Calculate FPS
                fps += (int) 1/dt;
                fps_count++;

                // If debug mode is enabled draw FPS every second
                if(fps_count >= 60) {
                    if( debugMode )
                        printf("now=%8.4f  game_now=%8.4f  dt=%6.4f  game_dt=%6.4f  reps=%d fps=%6i \n",
                                now, game_now, dt, game_dt, reps, fps/fps_count);
                    fps_count = 0;
                    fps=0;
                }

                // Clear the screen to black
                glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);

                glDrawArrays(GL_TRIANGLE_FAN, 0, 66);

                //Draw
                //render( );

                //Set last frame time
                lastFrame = now;

                // if(fps > 65) {
                //     usleep(5000);
                // }

                glfwSwapBuffers(window);
                glfwPollEvents();
            }

            glDeleteBuffers(1, &vbo);

            glDeleteVertexArrays(1, &vao);

            //Destroy Window
            glfwDestroyWindow(window);
            glfwTerminate();
            exit(EXIT_SUCCESS);

            return 0;
        }

        bool initialize()
        {
            //Initialize  GLFW
            if (!glfwInit())
                return false;

            //Get window size from settings
            int windowHeight = settings->getWindowHeight();
            int windowWidth = settings->getWindowWidth();



            // Set up OpenGL options.
            // Use OpenGL verion 4.1,
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
            // GLFW_OPENGL_FORWARD_COMPAT specifies whether the OpenGL context should be forward-compatible, i.e. one where all functionality deprecated in the requested version of OpenGL is removed.
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
            // Indicate we only want the newest core profile, rather than using backwards compatible and deprecated features.
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            // Make the window resize-able.
            glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

            window = glfwCreateWindow(windowWidth, windowHeight, "Control The Chaos", NULL, NULL);
            if (!window)
            {
                glfwTerminate();
                return false;
            }

            //Make the window's context current
            glfwMakeContextCurrent(window);

            //Set frame swap interval
            glfwSwapInterval(1);

            glfwSetKeyCallback(window, keyboardInput);

            int bufferWidth, bufferHeight;
            glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);

            glViewport(0, 0, bufferWidth, bufferHeight);

            // Set background color to white
            glClearColor(1, 1, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();

            // draw on middle of screen
            double top = -(windowHeight/2.0);
            double bottom = windowHeight/2.0;
            double left = -(windowWidth/2.0);
            double right = windowWidth/2.0;
            glOrtho( left, right, bottom, top, 1, -1 );

            //glEnable(GL_BLEND);
            //glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA); 
            //glEnable(GL_LINE_SMOOTH);

            return true;
        }

        void render()
        {
            this->gamemode.render();
        }

        void update( double dt )
        {
            double dt_t = dt/10;
            for(int i; i<=10; i++) {
                this->gamemode.update( dt_t );
            }
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
