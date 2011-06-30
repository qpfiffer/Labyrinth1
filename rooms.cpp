#include "rooms.h"
float *room::returnDim() {
  return dimensions;
}
float *room::returnOr() {
  return origin;
}
void room::initRoom(float dimensions_p[3], float origin_p[3], struct roomTextures *Proom_p, int doors_p) { 
  int debug = 1;
  // This int holds how many textures will be used for a room
  int totalDoorTexes = 4;
  srand(time(NULL));
  door1.innerDoor = makeTexture("textures/door0.png"); 
  door1.floorPad  = makeTexture("textures/floorPad.png");  
  dimensions[0]    = dimensions_p[0];
  dimensions[1]    = dimensions_p[1];
  dimensions[2]    = dimensions_p[2];
  origin[0]        = origin_p[0];
  origin[1]        = origin_p[1];
  origin[2]        = origin_p[2];
  Proom         = Proom_p;
  numDoors = doors_p;  
  // This is all for the doors:
  int i, j, l, k=0;
  int side = 0;
  int one=0, two=0;
  while(k<doors_p) {
    //side = (int)rand() % 6; //Pick which side we want the door to be on
    side = 1 + ((int)rand() % 4); 
    switch (side) {
      //NOTE:
      // I guess the variable 'one' is always equal to zero?
      //Edit: I forgot, I moved all the doors to the bottom level
      /*case (0): //Bottom of the cube
        one = (int)rand() %  ((int)dimensions_p[2]);
        two = (int)rand() % ((int)dimensions_p[0]-1);        
        PtextMem.bottom_door[one][two] = 1;
        if (debug == 1)
          printf("Side: Bottom one = %d, two = %d,\n", one, two);    
        break;*/
      case (1): //Front of the cube
        doorStructs[k] = (doorInformation *) malloc(sizeof(doorInformation)); //All important malloc for dynamic doors
        doorStructs[k]->side = 1; //Set side to 1, meaning front
	      doorStructs[k]->doorNumber = k;
	      //one = (int)rand() % ((int)dimensions_p[1]+1);
        two = (int)rand() % ((int)dimensions_p[0]);
        // The reason this is so batshit fucking long is because we need to make sure doors
        // don't have pressure pads that overlap on corners. And stuff.
        if (floorPads1.floorPadsPlaces[0][two] != 1) {
          doorStructs[k]->x=one;
          doorStructs[k]->y=two;
          PtextMem.front_door[one][two] = 1; //Tells the room drawing func to not draw a wall
          floorPads1.floorPadsPlaces[0][two] = 1; //Tells the same func to draw a floorpad.
          doorStructs[k]->floorLoc[0][two]=1;
          if (debug == 1)
            printf("Side: Front one = %d, two = %d,\n", one, two);
          k++;
        }
        break;    
      case (2): //Right of the cube
        doorStructs[k] = (doorInformation *) malloc(sizeof(doorInformation));
        doorStructs[k]->side = 2;
	      doorStructs[k]->doorNumber = k;
        //one = (int)rand() %  ((int)dimensions_p[2]);
        two = (int)rand() % ((int)dimensions_p[1]);
        if (floorPads1.floorPadsPlaces[two][(int)dimensions_p[1]-1] != 1) {
        doorStructs[k]->x=one;
          doorStructs[k]->y=two;
          PtextMem.right_door[one][two] = 1;
          floorPads1.floorPadsPlaces[two][(int)dimensions_p[1]-1] = 1;
          doorStructs[k]->floorLoc[two][(int)dimensions_p[1]-1]=1;
          if (debug == 1)
            printf("Side: Right one = %d, two = %d,\n", one, two);
          k++;
        }
        break;
      case (3): //Back wall of the cube
        doorStructs[k] = (doorInformation *) malloc(sizeof(doorInformation));
        doorStructs[k]->side = 3;
	      doorStructs[k]->doorNumber = k;
        //one = (int)rand() %  ((int)dimensions_p[1]+1);
        two = (int)rand() % ((int)dimensions_p[0]); 
        if (floorPads1.floorPadsPlaces[(int)dimensions_p[0]-1][two] != 1) {
          doorStructs[k]->x=one;
          doorStructs[k]->y=two;
          PtextMem.back_door[one][two] = 1;
          floorPads1.floorPadsPlaces[(int)dimensions_p[0]-1][two] = 1;
          doorStructs[k]->floorLoc[(int)dimensions_p[0]-1][two]=1;
          if (debug == 1)
            printf("Side: Back one = %d, two = %d,\n", one, two); 
          k++;
        }
        break;
      case (4): //Left side of the cube
        doorStructs[k] = (doorInformation *) malloc(sizeof(doorInformation));
        doorStructs[k]->side = 4;
	      doorStructs[k]->doorNumber = k;
        //one = (int)rand() %  ((int)dimensions_p[2]);
        two = (int)rand() % ((int)dimensions_p[1]); 
        if (floorPads1.floorPadsPlaces[two][0] != 1) {
          doorStructs[k]->x=one;
          doorStructs[k]->y=two;
          PtextMem.left_door[one][two] = 1;
          floorPads1.floorPadsPlaces[two][0] = 1;
          doorStructs[k]->floorLoc[two][0]=1;
          if (debug == 1)
            printf("Side: Left one = %d, two = %d,\n", one, two);
          k++;
        }
        break;
      /*case (5): //Top of the cube
        one = (int)rand() %  ((int)dimensions_p[2]);
        two = (int)rand() % ((int)dimensions_p[0]-1); 
        PtextMem.top_door[one][two] = 1;
        if (debug == 1)
          printf("Side: Top one = %d, two = %d,\n", one, two);
        break;*/
        printf("%d\n", k);
    }    
    //k++;
    one = 0;
    two = 0;       
  }
  //This little POS picks textures for the walls.
  for (l=0;l<dimensions[2];l++) {
    for (i=0;i<dimensions[1];i++) {
      for (j=0;j<dimensions[0];j++) {
        PtextMem.top_tex[i][j] = Proom->ceiling;
        PtextMem.bottom_tex[i][j] = Proom->floor;
        PtextMem.front_tex[i+l][j] = Proom->wall[(int)rand() % totalDoorTexes];
        PtextMem.back_tex[i+l][j] = Proom->wall[(int)rand() % totalDoorTexes];
        PtextMem.left_tex[i+l][j] = Proom->wall[(int)rand() % totalDoorTexes];
        PtextMem.right_tex[i+l][j] = Proom->wall[(int)rand() % totalDoorTexes];
      }
    }
  }
}

void room::draw() {
  glColor3f(1, 1, 1);
  int doors_on = 1;
  float tileSize[3] = { 0.5, 0.5, 0.5 };
  //Translate to the origin
  glTranslatef(origin[0], origin[1], origin[2]);
  int i, j;
  //Floor
  glPushMatrix();
  for (i=0;i<dimensions[1];i++) {
    for (j=0;j<dimensions[0];j++) {
    //if (PtextMem.bottom_door[i][j] == 1 && doors_on == 1) {
      if (floorPads1.floorPadsPlaces[i][j] != 0 && doors_on == 1) {
        glBindTexture(GL_TEXTURE_2D, door1.floorPad);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);glVertex3f(-tileSize[0], -tileSize[1], -tileSize[2]);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-tileSize[0], -tileSize[1], tileSize[2]);
        glTexCoord2f(1.0f, 1.0f);glVertex3f(tileSize[0], -tileSize[1], tileSize[2]);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(tileSize[0], -tileSize[1], -tileSize[2]);
        glEnd();
      } else {
        glBindTexture(GL_TEXTURE_2D, PtextMem.bottom_tex[i][j]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);glVertex3f(-tileSize[0], -tileSize[1], -tileSize[2]);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-tileSize[0], -tileSize[1], tileSize[2]);
        glTexCoord2f(1.0f, 1.0f);glVertex3f(tileSize[0], -tileSize[1], tileSize[2]);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(tileSize[0], -tileSize[1], -tileSize[2]);
        glEnd();
      }
      glTranslatef(1, 0, 0);
    }
    glTranslatef(-dimensions[0], 0, 1);
  }
  glPopMatrix();
  //Move up to where the ceiling should be
  glTranslatef(0, dimensions[2], 0);
  //Ceiling
  for (i=0;i<dimensions[1];i++) {
    for (j=0;j<dimensions[0];j++) {
      if (PtextMem.top_door[i][j] != 0 && doors_on == 1) {
          glPushMatrix();
          glRotatef(90, 1, 0, 0);
          if ( PtextMem.top_door[i][j] == 1)      
            door(0, door1);
          glPopMatrix();  
        } else {
          glBindTexture(GL_TEXTURE_2D, PtextMem.top_tex[i][j]);
          glBegin(GL_QUADS);
          glTexCoord2f(1.0f, 0.0f);glVertex3f(tileSize[0], -tileSize[1], -tileSize[2]);
          glTexCoord2f(0.0f, 0.0f);glVertex3f(-tileSize[0], -tileSize[1], -tileSize[2]);
          glTexCoord2f(0.0f, 1.0f);glVertex3f(-tileSize[0], -tileSize[1], tileSize[2]);
          glTexCoord2f(1.0f, 1.0f);glVertex3f(tileSize[0], -tileSize[1], tileSize[2]);
          glEnd();
      }
      glTranslatef(1, 0, 0);
    }
    glTranslatef(-dimensions[0], 0, 1);
  }
  //Move back down to floor level
  glTranslatef(0, -dimensions[2], -dimensions[1]);
  //Wall Left
  for (i=0;i<dimensions[2];i++) {
    for (j=0;j<dimensions[1];j++) {
      if (PtextMem.left_door[i][j] != 0 && doors_on == 1) {
          glPushMatrix();
          glRotatef(90, 0, 1, 0);              
          glTranslatef(0, 0, -1);
          if ( PtextMem.left_door[i][j] == 1)          
          door(0, door1);
          glPopMatrix();  
        } else {
          glBindTexture(GL_TEXTURE_2D, PtextMem.left_tex[i][j]);
          glBegin(GL_QUADS);
          glTexCoord2f(0.0f, 0.0f);glVertex3f(-tileSize[0], tileSize[1], tileSize[2]);
          glTexCoord2f(0.0f, 1.0f);glVertex3f(-tileSize[0], tileSize[1], -tileSize[2]);
          glTexCoord2f(1.0f, 1.0f);glVertex3f(-tileSize[0], -tileSize[1], -tileSize[2]);
          glTexCoord2f(1.0f, 0.0f);glVertex3f(-tileSize[0], -tileSize[1], tileSize[2]);
          glEnd();
      }
      glTranslatef(0, 0, 1);
    }
    glTranslatef(0, 1, -dimensions[1]); 
  }
  //Move across the floor
  glTranslatef(dimensions[0]-1, -dimensions[2], 0);
  //Wall RIGHT
  for (i=0;i<dimensions[2];i++) {
    for (j=0;j<dimensions[1];j++) {
      if (PtextMem.right_door[i][j] != 0 && doors_on == 1) {
          glPushMatrix();
          glRotatef(270, 0, 1, 0);              
          glTranslatef(0, 0, -1);
          if ( PtextMem.right_door[i][j] == 1)
	          door(0, door1);   
          glPopMatrix();  
        } else {
          glBindTexture(GL_TEXTURE_2D, PtextMem.right_tex[i][j]);
          glBegin(GL_QUADS);
          glTexCoord2f(0.0f, 0.0f);glVertex3f(tileSize[0], tileSize[1], tileSize[2]);
          glTexCoord2f(0.0f, 1.0f);glVertex3f(tileSize[0], tileSize[1], -tileSize[2]);
          glTexCoord2f(1.0f, 1.0f);glVertex3f(tileSize[0], -tileSize[1], -tileSize[2]);
          glTexCoord2f(1.0f, 0.0f);glVertex3f(tileSize[0], -tileSize[1], tileSize[2]);
          glEnd();
      }
      glTranslatef(0, 0, 1);
    }
    glTranslatef(0, 1, -dimensions[1]); 
  }
  //Move to the back wall
  glTranslatef(-dimensions[0]+1, -dimensions[2], dimensions[1]);
  //Back Wall
  for (i=0;i<dimensions[2];i++) {
    for (j=0;j<dimensions[0];j++) {
      if (PtextMem.back_door[i][j] != 0 && doors_on == 1) {
          glPushMatrix();
          glRotatef(-180, 0, 1, 0);
          if ( PtextMem.back_door[i][j] == 1)          
            door(0, door1);   
          glPopMatrix();  
        } else {
          glBindTexture(GL_TEXTURE_2D, PtextMem.back_tex[i][j]);
          glBegin(GL_QUADS);
          //Left
          glTexCoord2f(0.0f, 1.0f);glVertex3f(-tileSize[0], tileSize[1], -tileSize[2]);
          glTexCoord2f(1.0f, 1.0f);glVertex3f(tileSize[0], tileSize[1], -tileSize[2]);
          glTexCoord2f(1.0f, 0.0f);glVertex3f(tileSize[0], -tileSize[1], -tileSize[2]);
          glTexCoord2f(0.0f, 0.0f);glVertex3f(-tileSize[0], -tileSize[1], -tileSize[2]);
          glEnd();
      }
      glTranslatef(1, 0, 0);
    }
    glTranslatef(-dimensions[0], 1, 0); 
  }
  //TO THE FRONT TO THE FRONT
  glTranslatef(0, -dimensions[2], -dimensions[1]-1);
  //Front Wall
  for (i=0;i<dimensions[2];i++) {
    for (j=0;j<dimensions[0];j++) {
      if (PtextMem.front_door[i][j] != 0 && doors_on == 1) {             
          if ( PtextMem.front_door[i][j] == 1)          
            door(0, door1);   
        } else {
          glBindTexture(GL_TEXTURE_2D, PtextMem.front_tex[i][j]);
          glBegin(GL_QUADS);
          //Left
          glTexCoord2f(0.0f, 1.0f);glVertex3f(-tileSize[0], tileSize[1], tileSize[2]);
          glTexCoord2f(1.0f, 1.0f);glVertex3f(tileSize[0], tileSize[1], tileSize[2]);
          glTexCoord2f(1.0f, 0.0f);glVertex3f(tileSize[0], -tileSize[1], tileSize[2]);
          glTexCoord2f(0.0f, 0.0f);glVertex3f(-tileSize[0], -tileSize[1], tileSize[2]);
          glEnd();
      }
      glTranslatef(1, 0, 0);
    }
    glTranslatef(-dimensions[0], 1, 0); 
  }
}

int room::doorOpenCheck(float playerX, float playerY, float playerZ) {
  int localPlayerPos[3];
  //Get the player's position local to the room:
  localPlayerPos[0] = (playerX - origin[0]) - 0.5;
  localPlayerPos[1] = (playerY - origin[1]) - 0.5; // We don't really care about this one, it's not used
  localPlayerPos[2] = (playerZ - origin[2]) - 0.5;
  int i;
  // Go through our returned values and make sure they're all positive
  for(i=0;i<3;i++) {
    if (localPlayerPos[i] < 0)
      localPlayerPos[i] = -(localPlayerPos[i]);
  }
  //printf("X: %d Y: %d\n", localPlayerPos[0], localPlayerPos[2]);
  // This compares the players position with the door pad positions:
  if (floorPads1.floorPadsPlaces[localPlayerPos[2]][localPlayerPos[0]] == 1) {
    return 1;
  }
  else // Redundant but FUCK YOU
    return 0;
}

void room::setDoorOpen(float playerX, float playerY, float playerZ) {
  // NOTE
  // See doorOpenCheck for info on what this does. They're pretty much the same.
  int localPlayerPos[3];
  localPlayerPos[0] = (playerX - origin[0]) - 0.5;
  localPlayerPos[1] = (playerY - origin[1]) - 0.5;
  localPlayerPos[2] = (playerZ - origin[2]) - 0.5;
  int i;
  for(i=0;i<3;i++) {
    if (localPlayerPos[i] < 0)
      localPlayerPos[i] = -(localPlayerPos[i]);
  }
  // If we are standing on a floorpad:
  if (floorPads1.floorPadsPlaces[localPlayerPos[2]][localPlayerPos[0]] == 1) {
    // IF YES:
    // Handy chart:
    // 1 = Front
    // 2 = Right
    // 3 = Back
    // 4 = Left
    // Find out if there is a door already open:
    switch (PtextMem.lastDoorSide) {
      // This should check if there is a door open using lastDoorX and Y
      // Then it should set that door's status to closed. Hopefully.
      case (1):
        PtextMem.front_door[PtextMem.lastDoorX][PtextMem.lastDoorY] = 1;
        break;
      case (2): 
        PtextMem.right_door[PtextMem.lastDoorX][PtextMem.lastDoorY] = 1;
        break;
      case (3): 
        PtextMem.back_door[PtextMem.lastDoorX][PtextMem.lastDoorY] = 1;
        break;
      case (4): 
        PtextMem.left_door[PtextMem.lastDoorX][PtextMem.lastDoorY] = 1;
        break;
    }
    // Find out what door it cooresponds to:
    // Set the new door to "open" status (2)
    for(i=0;i<numDoors;i++) {
      if (doorStructs[i]->floorLoc[localPlayerPos[2]][localPlayerPos[0]]==1) {
        switch (doorStructs[i]->side) {
          case (1): 
            // If the door that is to be opened is on this side, set it to
            // open status, change the globally known "side" var to this
            // side.
            PtextMem.front_door[doorStructs[i]->x][doorStructs[i]->y] = 2;
            PtextMem.lastDoorSide = 1;
            break;
          case (2): 
            PtextMem.right_door[doorStructs[i]->x][doorStructs[i]->y] = 2;
            PtextMem.lastDoorSide = 2;
            break;
          case (3): 
            PtextMem.back_door[doorStructs[i]->x][doorStructs[i]->y] = 2;
            PtextMem.lastDoorSide = 3;
            break;
          case (4): 
            PtextMem.left_door[doorStructs[i]->x][doorStructs[i]->y] = 2;
            PtextMem.lastDoorSide = 4;
            break;
        }
        // This sets the x and y of the global door var (for the current side)
        // to the neww door. Updates the x and y, basically.
        PtextMem.lastDoorX = doorStructs[i]->x;
        PtextMem.lastDoorY = doorStructs[i]->y;
      }
    }
  }
  // IF NO:
  // Do nothing. End.
}

