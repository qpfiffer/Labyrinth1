#ifndef _PHYSICS_H_
#define _PHYSICS_H
struct object {
  float dimensions[3];
  float position[3];
};
//float playerCollision[3] = { 0.35, 0.35, 0.6 }; //Width, length and height
int collisionCheck(struct object obj1, struct object obj2);
#endif
