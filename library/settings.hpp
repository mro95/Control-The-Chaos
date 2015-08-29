#ifndef _settings_H_
    #define _settings_H_

#include <fstream>
#include <string>
#include <streambuf>
#include <libgen.h>
#ifdef WINDOWS
    #include <direct.h>
    #define getcwd _getcwd
#else
    #include <unistd.h>
#endif

#include "json.hpp"

// for convenience
using json = nlohmann::json;

using string = std::string;

class Settings {
    public:

        static const int windowWidth = 1280;
        static const int windowHeight = 720;

        void loadConfigFile(char** argv)
        {
            std::string s = argv[0];
            std::string token = s.substr(2, s.find("/"));

            std::cout << token << std::endl;

            char cCurrentPath[10000];

            if (!getcwd(cCurrentPath, sizeof(cCurrentPath)))
            {
                return;
            }

            cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

            printf ("The current working directory is %s \n", cCurrentPath);


            string path = get_selfpath();
            string filename = "config.json";

            std::ifstream t(filename);
            if( t ) {
                string str((std::istreambuf_iterator<char>(t)),
                            std::istreambuf_iterator<char>());
                std::cout << str;
            } else {
                std::cout << "config file not found";
            }

        }


        std::string get_selfpath() {
            char buff[1000];
            ssize_t len = ::readlink("/proc/self/exe", buff, sizeof(buff)-2);
            if (len != -1) {
              buff[len] = '\0';
              return std::string(buff);
            }
            /* handle error condition */
        }

    private:

};

#endif
