
#include "main.hpp"
#include "library/settings.hpp"
int main(int argc, char* args[])
{
    Settings settings;
    settings.loadConfigFile();
    return 0;
}
