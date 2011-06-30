#ifndef _SHAPE_H_
#define _SHAPE_H

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>

#include <stdio.h>
#include <stdlib.h>

#include "textures.h"
void Cube(float x, float y, float z);
void plane(float x, float y, int texture);
void pipe(float length, float subdivs, float radius);
void door(int open, struct doorTextures door1);
void drawFace(GLuint texturePassed);

#endif
