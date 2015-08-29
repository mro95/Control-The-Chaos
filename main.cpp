#include "main.hpp"
#include "library/settings.hpp"
int main(int argc, char* argv[])
{
    Settings settings;
    settings.loadConfigFile(argv);
    return 0;
}
