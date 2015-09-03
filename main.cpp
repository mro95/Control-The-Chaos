#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "main.hpp"
#include "library/settings.hpp"
#include "game/GameLoop.hpp"
int main(int argc, char* argv[])
{
    Settings settings;
    settings.findConfigPath();
    settings.loadConfigFile();

    GameLoop game;
    game.settings = &settings;
    game.execute();
    return 0;
}
