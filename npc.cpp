#include "npc.h"
#include "rooms.h"

void NPC::initLocNPC() {
  texture = makeTexture("textures/floorPad.png");
  pos[0] = -2.5;
  pos[1] = -2.5;
  pos[2] = -2.5;
}

void NPC::draw(int type) {
  float cielX = 0.25;
  float cielY = 0.25;
  float cielZ = 0.25;
  if (type == 0) {
    glBegin(GL_QUADS);
      glBindTexture(GL_TEXTURE_2D, texture);
      glTexCoord2f(1.0f, 0.0f);glVertex3f(-cielX, cielY, -cielZ);
      glTexCoord2f(0.0f, 0.0f);glVertex3f(cielX, cielY, -cielZ);
      glTexCoord2f(0.0f, 1.0f);glVertex3f(cielX, -cielY, -cielZ);
      glTexCoord2f(1.0f, 1.0f);glVertex3f(-cielX, -cielY, -cielZ);
    glEnd();
  }
  if (type == 1) { //This is the "face" NPC"
    drawFace(texture);
  } 
}

void NPC::move(float vector[4]){
  pos[0] = vector[0];
  pos[1] = vector[1];
  pos[2] = vector[2];
}

void walter_brain() {
  /* This is Walter. I want him to be somethin like a butler.
     His purpose in the game is simply to hate the player, and
     make him feel terrible. He will destroy, laugh, critisize
     and mock the player. He will argue. He will completely 
     undermine anything the player does. I don't know what he
     will look like or how he will interact, though. I'm 
     picturing someone with no face.
  */
}
