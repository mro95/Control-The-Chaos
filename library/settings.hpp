#ifndef _settings_H_
    #define _settings_H_

#include <fstream>
#include <string>
#include <streambuf>
#include <libgen.h>

#include "json.hpp"

// for convenience
using json = nlohmann::json;

using string = std::string;

class Settings {
    public:

        static const int windowWidth = 1280;
        static const int windowHeight = 720;

        void loadConfigFile()
        {
            string path = get_selfpath();
            string filename = path + "/config.json";
            char* a = '.';
            std::cout << dirname(".") << std::endl;
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
