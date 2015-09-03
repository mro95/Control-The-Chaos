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

        void findConfigPath()
        {
            // TODO: Windows support
            // TODO: if files not extist create default files
            std::string homepath = getenv("HOME");
            this->path = homepath+"/.config/control-the-chaos/";
        }


        void loadConfigFile()
        {
            std::cout << "Loading config file..." << std::endl;
            string filename = this->path+"config.json";

            std::ifstream stream(filename);
            if( stream ) {
                string rawConfigData((std::istreambuf_iterator<char>(stream)),
                                      std::istreambuf_iterator<char>());
                parseJsonConfig(rawConfigData);
            } else {
                std::cout << "config file not found";
            }

        }
        

        void loadConfigFile2(char** argv)
        {
            std::cout << "Loading config file..." << std::endl;
            string argv0 = argv[0];
            string path = "";
            if(argv0 != "./ControlTheChaos") {
                path = getPath(argv0);
            }
            string filename = path+"config.json";

            std::ifstream stream(filename);
            if( stream ) {
                string rawConfigData((std::istreambuf_iterator<char>(stream)),
                                      std::istreambuf_iterator<char>());
                parseJsonConfig(rawConfigData);
            } else {
                std::cout << "config file not found";
            }

        }

        int getWindowWidth()
        {
            return this->windowWidth;
        }

        int getWindowHeight()
        {
            return this->windowHeight;
        }

        void setWindowWidth(int width)
        {
            this->windowWidth = width;
        }

        void setWindowHeight(int height)
        {
            this->windowHeight = height;
        }

    private:

        string path;
        int windowWidth;
        int windowHeight;


        std::string getPath(string argv0)
        {
            string path = "";
            std::string s = argv0;
            std::string delimiter = "/";
            size_t pos = 0;
            std::string token;
            while ((pos = s.find(delimiter)) != std::string::npos) {
                token = s.substr(0, pos);
                path += token+"/";
                s.erase(0, pos + delimiter.length());
            }
            return path;
        }

        void parseJsonConfig(string rawConfigData)
        {
            auto j = json::parse(rawConfigData);
            windowWidth = j["window"]["width"];
            windowHeight = j["window"]["height"];

            std::cout << "windowWidth:" << windowWidth << std::endl;
            std::cout << "windowHeight:" << windowHeight << std::endl;
        }


};

#endif
