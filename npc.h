#ifndef _NPC_H_
#define _NPC_H_

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <GL/glpng.h>
#include "textures.h"
#include "shape.h"

class NPC {
  public:
    void initLocNPC();
    void move(float vector[4]); 
    void draw(int type); // The int type thing is a little hack.
  private:
    float pos[4]; //X, Y, Z. 
    GLuint texture;
};

#endif
