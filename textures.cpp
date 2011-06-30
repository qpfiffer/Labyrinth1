#include "textures.h"

GLuint makeTexture(char *name) {
  pngInfo info;
  GLuint texture_passed;
  //http://www.fifi.org/doc/libglpng-dev/glpng.html
  texture_passed = pngBind(name, PNG_NOMIPMAP, PNG_ALPHA, &info, GL_CLAMP, GL_NEAREST, GL_NEAREST);
  if (texture_passed == 0) {
    printf("Cannot load texture.\n");
    return NULL;
  }
  return texture_passed;
}
