#ifndef _TEXTURES_H_
#define _TEXTURES_H_
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <GL/glpng.h>
GLuint makeTexture(char name[]);

struct roomTextures {
  GLuint wall[5];
  GLuint ceiling;
  GLuint floor;
};

struct doorTextures {
  GLuint innerDoor;
  GLuint floorPad;
};
#endif
