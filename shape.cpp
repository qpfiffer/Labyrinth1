#include "shape.h"

//Makes a cube. Who woulda thought?
void Cube(float x, float y, float z) {
  //glPolygonMode(GL_FRONT, GL_LINE); 
  glBegin(GL_QUADS);

  //Back of cube:
  glVertex3f(-x/2, y/2, -z/2);
  glVertex3f(x/2, y/2, -z/2);
  glVertex3f(x/2, -y/2, -z/2);
  glVertex3f(-x/2, -y/2, -z/2);

  //front of the cube
  glVertex3f(-x/2, y/2, z/2);
  glVertex3f(x/2, y/2, z/2);
  glVertex3f(x/2, -y/2, z/2);
  glVertex3f(-x/2, -y/2, z/2);
  
  //Left side of the cube
  glVertex3f(-x/2, y/2, z/2);
  glVertex3f(-x/2, y/2, -z/2);
  glVertex3f(-x/2, -y/2, -z/2);
  glVertex3f(-x/2, -y/2, z/2);

  //RIGHT side of the cube
  glVertex3f(x/2, y/2, z/2);
  glVertex3f(x/2, y/2, -z/2);
  glVertex3f(x/2, -y/2, -z/2);
  glVertex3f(x/2, -y/2, z/2);

  //Top of the cube
  glVertex3f(-x/2, y/2, -z/2);
  glVertex3f(-x/2, y/2, z/2);
  glVertex3f(x/2, y/2, z/2);
  glVertex3f(x/2, y/2, -z/2);
  
  //Bottom of the cube
  glVertex3f(-x/2, -y/2, -z/2);
  glVertex3f(-x/2, -y/2, z/2);
  glVertex3f(x/2, -y/2, z/2);
  glVertex3f(x/2, -y/2, -z/2);
  
  glEnd();
}
void door(int open, struct doorTextures door1) {
  //I am lazy. This is terrible.
  glPushMatrix();
  glColor3f(1, 1, 1);
  float tileSize[3] = { 0.1, 0.1, 0.1 };
  if (open==0) {
    glBegin(GL_QUADS);
      glVertex3f(-0.5, -0.5, 0.5);
      glVertex3f(0.5, -0.5, 0.5);
      glVertex3f(0.5, 0.5, 0.5);
      glVertex3f(-0.5, 0.5, 0.5);
    glEnd();  
  //Begin outerdoor
  glColor3f(0, 0, 0);
  glTranslatef(0, 0, 0.5);
  Cube(0.75, 0.75, 0.05);
  glColor3f(0.5, 0.5, 0.5);
  Cube(0.70, 0.70, 0.07);
  //End outerdoor, begin inner door
  //---
  //InnerDoor border:
  glColor3f(0.7, 0.7, 0.7);
  glTranslatef(-0.2, 0, 0);
  Cube(0.08, 0.4, 0.08);
  glTranslatef(0.4, 0, 0);
  Cube(0.08, 0.4, 0.08);
  glTranslatef(-0.2, 0, 0);
  glTranslatef(0, 0.2, 0);
  Cube(0.48, 0.08, 0.08);
  glTranslatef(0, -0.4, 0);
  Cube(0.48, 0.08, 0.08);
  glTranslatef(0, 0.2, 0);
  //InnerDoor
  glBindTexture(GL_TEXTURE_2D, door1.innerDoor);
  glTranslatef(-0.1, 0.1, -0.05);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f);glVertex3f(-tileSize[0], tileSize[1], tileSize[2]);
    glTexCoord2f(1.0f, 1.0f);glVertex3f(tileSize[0], tileSize[1], tileSize[2]);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(tileSize[0], -tileSize[1], tileSize[2]);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(-tileSize[0], -tileSize[1], tileSize[2]);
  glEnd();
  glTranslatef(0.2, 0, 0);
  glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f);glVertex3f(-tileSize[0], tileSize[1], tileSize[2]);
    glTexCoord2f(0.0f, 1.0f);glVertex3f(tileSize[0], tileSize[1], tileSize[2]);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(tileSize[0], -tileSize[1], tileSize[2]);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(-tileSize[0], -tileSize[1], tileSize[2]);
  glEnd();
  glTranslatef(0, -0.2, 0);
  glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(-tileSize[0], tileSize[1], tileSize[2]);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(tileSize[0], tileSize[1], tileSize[2]);
    glTexCoord2f(0.0f, 1.0f);glVertex3f(tileSize[0], -tileSize[1], tileSize[2]);
    glTexCoord2f(1.0f, 1.0f);glVertex3f(-tileSize[0], -tileSize[1], tileSize[2]);
  glEnd();
  glTranslatef(-0.2, 0, 0);
  glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(-tileSize[0], tileSize[1], tileSize[2]);
    glTexCoord2f(1.0f, 0.0f);glVertex3f(tileSize[0], tileSize[1], tileSize[2]);
    glTexCoord2f(1.0f, 1.0f);glVertex3f(tileSize[0], -tileSize[1], tileSize[2]);
    glTexCoord2f(0.0f, 1.0f);glVertex3f(-tileSize[0], -tileSize[1], tileSize[2]);
  glEnd();
  glPopMatrix();
  }
  glColor3f(1, 1, 1);
}
void plane(float x, float y, int texture) {
  // Non-textured planes are just one giant quad.
  // ONE GIANT QUAD! ONE! UNO! DO NOT CHANGE SENOR!
  float i, j; 
  float cielX = 0.5;
  float cielY = 0.5;
  float cielZ = 0.5;  
  if (texture != 1) {
    glBegin(GL_QUADS);   
    glVertex3f(-x, -1, -y);
    glVertex3f(-x, -1, y);
    glVertex3f(x, -1, y);
    glVertex3f(x, -1, -y);
    glEnd();
  }
  else {
  for (i=0;i<x;i++) {
    for (j=0;j<y;j++) {  
      
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);glVertex3f(-cielX, -cielY, -cielZ);
        glTexCoord2f(0.0f, 1.0f);glVertex3f(-cielX, -cielY, cielZ);
        glTexCoord2f(1.0f, 1.0f);glVertex3f(cielX, -cielY, cielZ);
        glTexCoord2f(1.0f, 0.0f);glVertex3f(cielX, -cielY, -cielZ);
        glEnd();
        glTranslatef(1, 0, 0);
      }
      glTranslatef(-x, 0, 1);
    }
  }
}

void pipe(float length, float subdivs, float radius) {
  //Lets just use cubes  for now
  Cube(length, radius, radius);
}

void drawFace(GLuint texturePassed) {
  glPushMatrix();  
  glBegin(GL_TRIANGLES);
    glColor3f(1,1,1 );  
    glVertex3f(0, 2.5, 0);
    glVertex3f(-0.15, 2.15, 0);
    glVertex3f(0.15, 2.15, 0);
  glEnd(); 
  //---
  glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);     
    glVertex3f(0, 2.5, 0);
    glVertex3f(-0.30, 2.5, -0.2);
    glVertex3f(-0.15, 2.15, 0);
  glEnd(); 
  glBegin(GL_TRIANGLES);
    glColor3f(1,0,0); 
    glVertex3f(0, 2.5, 0);
    glVertex3f(0.30, 2.5, -0.2);
    glVertex3f(0.15, 2.15, 0);
  glEnd();
  //---
  glPopMatrix();
  glBegin(GL_TRIANGLES);
    glColor3f(0,0,1);     
    glVertex3f(-0.30, 2.5, -0.2);
    glVertex3f(-0.15, 2.15, 0);
    glVertex3f(-0.45, 2.15, -0.25);
  glEnd(); 
  glBegin(GL_TRIANGLES);
    glColor3f(0,0,1); 
    glVertex3f(0.30, 2.5, -0.2);
    glVertex3f(0.15, 2.15, 0);
    glVertex3f(0.45, 2.15, -0.25);
  glEnd();
  //---
  // Start Nose:
  glBegin(GL_TRIANGLES);
    glColor3f(0,1,0 );  
    glVertex3f(0, 1.85, 0.15);
    glVertex3f(-0.15, 2.15, 0);
    glVertex3f(0.15, 2.15, 0);
  glEnd();
  //---
  glBegin(GL_TRIANGLES);
    glColor3f(0,0,1 );  
    glVertex3f(-0.15, 2.15, 0);
    glVertex3f(0, 1.85, 0.15);
    glVertex3f(-0.15, 1.75, 0);
  glEnd();
  glBegin(GL_TRIANGLES);
    glColor3f(0,0,1 );  
    glVertex3f(0.15, 2.15, 0);
    glVertex3f(0, 1.85, 0.15);
    glVertex3f(0.15, 1.75, 0);
  glEnd();
  //---
  glBegin(GL_TRIANGLES);
    glColor3f(0,0.5,0 );  
    glVertex3f(0, 1.85, 0.15);
    glVertex3f(-0.15, 1.75, 0);
    glVertex3f(0.15, 1.75, 0);
  glEnd();
  //End nose
  //--- 
  //Begin eyes
  glBegin(GL_TRIANGLES);
    glColor3f(0,0,0.75 );  
    glVertex3f(-0.15, 2.15, 0);
    glVertex3f(-0.30, 1.95, -0.15);
    glVertex3f(-0.15, 1.75, 0);
  glEnd();
  glBegin(GL_TRIANGLES);
    glColor3f(0,0,0.75 );  
    glVertex3f(0.15, 2.15, 0);
    glVertex3f(0.30, 1.95, -0.15);
    glVertex3f(0.15, 1.75, 0);
  glEnd();
  //---
  glBegin(GL_TRIANGLES);
    glColor3f(0,0.75,0 );  
    glVertex3f(-0.15, 2.15, 0);
    glVertex3f(-0.30, 1.95, -0.15);
    glVertex3f(-0.45, 2.15, -0.25);
  glEnd();
  glBegin(GL_TRIANGLES);
    glColor3f(0,0.75,0 );  
    glVertex3f(0.15, 2.15, 0);
    glVertex3f(0.30, 1.95, -0.15);
    glVertex3f(0.45, 2.15, -0.25);
  glEnd();
  //---
  glBegin(GL_TRIANGLES);
    glColor3f(0.75,0,0 );  
    glVertex3f(-0.45, 2.15, -0.25);
    glVertex3f(-0.30, 1.95, -0.15);
    glVertex3f(-0.45, 1.75, 0);
  glEnd();
  glBegin(GL_TRIANGLES);
    glColor3f(0.75,0,0 );  
    glVertex3f(0.45, 2.15, -0.25);
    glVertex3f(0.30, 1.95, -0.15);
    glVertex3f(0.45, 1.75, 0);
  glEnd();
  //---
  glBegin(GL_TRIANGLES);
    glColor3f(1,0.5,0 );  
    glVertex3f(-0.30, 1.95, -0.15);
    glVertex3f(-0.15, 1.75, 0);
    glVertex3f(-0.45, 1.75, 0);
  glEnd();
  glBegin(GL_TRIANGLES);
    glColor3f(1,0.5,0 );  
    glVertex3f(0.30, 1.95, -0.15);
    glVertex3f(0.15, 1.75, 0);
    glVertex3f(0.45, 1.75, 0);
  glEnd();
  //---
  float colorsRand[3] = { 1/(rand() % 10 + 1),
                       1/(rand() % 10 + 1),
                       1/(rand() % 10 + 1) };
  glColor3f(colorsRand[0],colorsRand[1],colorsRand[2]);
  glPushMatrix();
  glTranslatef(-0.3, 1.95, -0.15);
  Cube(0.05, 0.05, 0.05);
  glPopMatrix();
glPushMatrix();
  glTranslatef(0.3, 1.95, -0.15);
  Cube(0.05, 0.05, 0.05);
  glPopMatrix();
  //---
  //Begin Jaw
  glBegin(GL_TRIANGLES);
    glColor3f(1,0,0 );  
    glVertex3f(0, 1.75, 0);
    glVertex3f(-0.40, 1.65, -0.05);
    glVertex3f(0.40, 1.65, -0.05);
  glEnd();
  //---
  glBegin(GL_TRIANGLES);
    glColor3f(1,0,1 );  
    glVertex3f(0, 1.75, 0);
    glVertex3f(0.45, 1.75, 0);
    glVertex3f(0.40, 1.65, -0.05);
  glEnd();  
  glBegin(GL_TRIANGLES);
    glColor3f(1,0,1 );  
    glVertex3f(0, 1.75, 0);
    glVertex3f(-0.45, 1.75, 0);
    glVertex3f(-0.40, 1.65, -0.05);
  glEnd();
  //---
  glBegin(GL_TRIANGLES);
    glColor3f(0.5,0,0.5 );  
    glVertex3f(-0.45, 1.75, 0);
    glVertex3f(-0.35, 1.35, 0);
    glVertex3f(-0.40, 1.65, -0.05);
  glEnd();  
  glBegin(GL_TRIANGLES);
    glColor3f(0.5,0,0.5 );  
    glVertex3f(0.45, 1.75, 0);
    glVertex3f(0.35, 1.35, 0);
    glVertex3f(0.40, 1.65, -0.05);
  glEnd();
  //---
  glBegin(GL_TRIANGLES);
    glColor3f(0.5,0.5,0.5 );  
    glVertex3f(-0.45, 1.75, 0);
    glVertex3f(-0.35, 1.35, 0);
    glVertex3f(-0.40, 1.25, 0);
  glEnd();  
  glBegin(GL_TRIANGLES);
    glColor3f(0.5,0.5,0.5 );  
    glVertex3f(0.45, 1.75, 0);
    glVertex3f(0.35, 1.35, 0);
    glVertex3f(0.40, 1.25, 0);
  glEnd();
  //---
  glBegin(GL_TRIANGLES);
    glColor3f(0.25,0.25,0.25 );  
    glVertex3f(-0.35, 1.35, 0);
    glVertex3f(-0.28, 1.25, 0);
    glVertex3f(-0.40, 1.25, 0);
  glEnd();  
  glBegin(GL_TRIANGLES);
    glColor3f(0.25,0.25,0.25 );  
    glVertex3f(0.35, 1.35, 0);
    glVertex3f(0.28, 1.25, 0);
    glVertex3f(0.40, 1.25, 0);
  glEnd();
  //---
  glBegin(GL_TRIANGLES);
    glColor3f(1,0.25,0.25 );  
    glVertex3f(-0.35, 1.35, 0);
    glVertex3f(-0.28, 1.25, 0);
    glVertex3f(0, 1.30, 0);
  glEnd();  
  glBegin(GL_TRIANGLES);
    glColor3f(1,0.25,0.25 );  
    glVertex3f(0.35, 1.35, 0);
    glVertex3f(0.28, 1.25, 0);
    glVertex3f(0, 1.30, 0);
  glEnd();
  //---
  glBegin(GL_TRIANGLES);
    glColor3f(1,0,0 );  
    glVertex3f(0, 1.30, 0);
    glVertex3f(-0.28, 1.25, 0);
    glVertex3f(0.28, 1.25, 0);
  glEnd();
  //---
  //Inside of mouth
  glBegin(GL_POLYGON);
    glColor3f(colorsRand[0],colorsRand[1],colorsRand[2]);
    glVertex3f(-0.40, 1.65, -0.05);
    glVertex3f(-0.35, 1.35, 0);
    glVertex3f(0, 1.25, 0);
    glVertex3f(0.35, 1.35, 0);
    glVertex3f(0.40, 1.65, -0.05);
  glEnd();  
}
