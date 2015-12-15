#ifndef GLSHADER_H
#define GLSHADER_H

#if defined(__APPLE__)
#include <OpenGL/gl3.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

GLuint LoadShader(const char *vertex_path, const char *fragment_path);

#endif
