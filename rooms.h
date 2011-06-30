#ifndef _ROOMS_H_
#define _ROOMS_H

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <time.h>
#include <stdlib.h>
#include "textures.h"
#include "shape.h"

struct roomWallMemory {
  // This struct is the texture memory for a room
  // Each array is an X and Y value corresponding
  // to a side of the cube. The final value of a
  // point is a texture. 15 is the max room size.
  GLuint top_tex    [15][15];
  GLuint bottom_tex [15][15];
  GLuint front_tex  [15][15];
  GLuint right_tex  [15][15];
  GLuint back_tex   [15][15];
  GLuint left_tex   [15][15];

  // Handy chart:
  // 1 = Front
  // 2 = Right
  // 3 = Back
  // 4 = Left

  int lastDoorSide; 
  int lastDoorX;
  int lastDoorY;
 
  int top_door [15][15];
  int bottom_door [15][15];
  int front_door [15][15];
  int right_door [15][15];
  int back_door [15][15];
  int left_door [15][15];
};

struct doorInformation {
  int x;          
  int y;
  int floorLoc[15][15];    // The location of this door's floorpad
  int doorNumber;          // This is the number of the door in the room. Should be 0-15
  int side;                // Should be 1-4. Or 0-6, if I put floors and ceilings back in.
};

struct floorPads {
  int floorPadsPlaces [15][15];
};

class room {
  public:
    float *returnDim();
    float *returnOr();
    void initRoom(float dimensions_p[3], float origin_p[3], struct roomTextures *Proom, int doors_p);
    void draw();
    int doorOpenCheck(float playerX, float playerY, float playerZ);
    void setDoorOpen(float playerX, float playerY, float playerZ);
    int numDoors;         // Total number of doors for this room
    doorInformation *doorStructs[15];  // Holds the pointers that malloc() comes up with.
  private:
    //Variables that have to do with the shape and position of the room:
    float dimensions[3];
    float origin[3];
    //Textures:
    struct roomTextures    *Proom; // Holds a pointer to the structure that holds the textures for the room
    struct roomWallMemory  PtextMem; 
    struct doorTextures    door1;
    struct floorPads       floorPads1;
};   
#endif
