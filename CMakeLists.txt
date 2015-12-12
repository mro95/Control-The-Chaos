cmake_minimum_required(VERSION 3.0)
project(ControlTheChaos)

find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(vendor/glfw)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
    if(NOT WIN32)
        set(GLAD_LIBRARIES dl)
    endif()
endif()

include_directories(/usr/include/freetype2/)
include_directories(/usr/include/GL/)

include_directories(game/
                    gamemodes/
                    objects/
                    objects/shapes
                    library/
                    vendor/glfw/include/)


file(GLOB PROJECT_HEADERS *.hpp
                          library/*.hpp
                          objects/*.hpp
                          objects/shapes/*.hpp
                          gamemodes/*.hpp
                          game/*.hpp)
file(GLOB PROJECT_SOURCES *.cpp
                          library/*.cpp
                          objects/*.cpp
                          objects/shapes/*.cpp
                          gamemodes/*.cpp
                          game/*.cpp)

file(GLOB PROJECT_CONFIGS CMakeLists.txt
                          Readme.md
                         .gitattributes
                         .gitignore
                         .gitmodules)

source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})

add_definitions(-DGLFW_INCLUDE_NONE
                -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS}
                               ${PROJECT_SHADERS} ${PROJECT_CONFIGS}
                               ${VENDORS_SOURCES})

                           target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${EXTRA_LIBS} freetype glfw ${GLFW_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
