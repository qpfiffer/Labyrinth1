#ifndef _LABYRINTH_H_
#define _LABYRINTH_H

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h> //Sure, why not
#include <time.h>
#include <string.h>

#include "textures.h"
#include "shape.h"
#include "rooms.h"
#include "npc.h"
#include "physics.h"
struct player {
  struct object player_phys;
};
//---
float globX=-2.5, globY=0.0, globZ=-3.0;
float globXrot=0.0, globYrot=0.0, globZrot=0.0;
float lastX, lastY;
//OpenGL functions:
int window;
void initGame(int width, int height);
void initFog();
void initTextures();
void initPlayer();
void initNPC();
void resizeGLScene(int width, int height);
void draw();
void FAKE_KEYS (int key, int x, int y);      
void move(unsigned char key, int x, int y);
void mouseMovement(int x, int y);
void click(int button, int state, int x, int y);
void renderBitmapString(float x, float y, void *font,char *string);

//My functions:
void camera(); 

#endif
