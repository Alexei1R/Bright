#define pragma once
#include "Bright.h"
typedef unsigned int GLuint;


namespace Bright {

    // Simple helper function to load an image into a OpenGL texture with common settings
    bool LoadTextureFromFile(const char* filename, unsigned int* out_texture, int* out_width, int* out_height);
}