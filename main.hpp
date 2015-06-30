#ifndef _main_H_
    #define _main_H_

#include <math.h>
#include <GLFW/glfw3.h>

# define PI           3.14159265358979323846  /* pi */
# define TAU          6.28318530717958647692  /* tau */

class Main {
    public:

        static const int windowWidth = 1280;
        static const int windowHeight = 720;

        Main( );
        int execute();

    private:

        bool running;
        GLFWwindow* window;

        bool initialize( );
        void render();
        void update( double dt );
};

bool debugMode = false;
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void DrawCircle(float cx, float cy, float r);

#endif
