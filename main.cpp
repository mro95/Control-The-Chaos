#include <GL/glut.h>
#include <GLFW/glfw3.h>

#include "main.hpp"
#include "library/settings.hpp"
#include "game/GameLoop.hpp"
int main(int argc, char* argv[])
{
    Settings settings;
    settings.loadConfigFile(argv);

    glutInit(&argc, argv);
    GameLoop game;
    game.settings = &settings;
    game.execute();
    return 0;
}
