#include "main.hpp"
#include "library/settings.hpp"
#include "game/GameLoop.hpp"
int main(int argc, char* argv[])
{
    Settings settings;
    settings.loadConfigFile(argv);

    GameLoop game;
    game.settings = &settings;
    game.execute();
    return 0;
}
