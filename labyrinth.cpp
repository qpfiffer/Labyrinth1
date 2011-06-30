#include "labyrinth.h"

#define ESCAPE 27
#define UP_ARROW 101
#define DOWN_ARROW 103
#define LEFT_ARROW 100
#define RIGHT_ARROW 102
#define W 119
#define S 115
#define D 100
#define A 97
#define E 101
int isNewRoom = 0; // If there is a new room, set this to one.
room room_construct;
room *currentRoom;
room *newRoom;
NPC creepy_face;
struct roomTextures room1, *Proom, *Proom2;
struct player mainPlayer;
int frame=0,time2=0,timebase=0;
char s[30];

void camera() {
  glTranslatef(0,0,-0.05);
  glRotatef(globXrot, 1.0, 0, 0);
  glRotatef(globYrot, 0, 1.0, 0);
  glTranslatef(globX,globY,globZ); 
}
void initFog() {
  GLfloat fogColor[4]= {0.0f, 0.0f, 0.0f, 0.0f};	// Fog Color
  glFogi(GL_FOG_MODE, GL_LINEAR); // Fog Mode
  glFogfv(GL_FOG_COLOR, fogColor);// Set Fog Color
  glFogf(GL_FOG_DENSITY, 0.95f);	// How Dense Will The Fog Be
  glHint(GL_FOG_HINT, GL_NICEST);	// Fog Hint Value
  glFogf(GL_FOG_START, 0.25f);		// Fog Start Depth
  glFogf(GL_FOG_END, 5.0f);				// Fog End Depth
  glEnable(GL_FOG);					      // Enables GL_FOG

}
void initPlayer() {
  mainPlayer.player_phys.dimensions[0] = 0.35;
  mainPlayer.player_phys.dimensions[1] = 0.35;
  mainPlayer.player_phys.dimensions[2] = 0.6;
}
void initTextures() {
  room1.wall[0]   = makeTexture("textures/wall01.png");
  room1.wall[1]   = makeTexture("textures/wall02.png");
  room1.wall[2]   = makeTexture("textures/wall03.png");
  room1.wall[3]   = makeTexture("textures/wall04.png");
  room1.ceiling   = makeTexture("textures/ceiling.png");
  room1.floor     = makeTexture("textures/floor.png");
  
  Proom = &room1;
}
void initNPC() {
  creepy_face.initLocNPC();
}
void initGame(int width, int height) {
  currentRoom = &room_construct;
  GLfloat light_position[] = { 1.0f, 1.0f, 1.0f};
  srand(time(NULL));
  glClearColor(1,1,0,0); //aRGB
  glClearDepth(1.0);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  //glEnable(GL_LIGHTING); //GO TO HELL
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
  glEnable(GL_ALPHA_TEST);
  glAlphaFunc(GL_GREATER,0.1f);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_position);
  glShadeModel(GL_SMOOTH);
  
  GLfloat specular[] = {1.0f, 1.0f, 1.0f , 1.0f};
  glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

  GLfloat position[] = { globX, globY, globZ, 1 };
  glLightfv(GL_LIGHT0, GL_POSITION, position);

  glEnable(GL_LIGHT0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  glMatrixMode(GL_MODELVIEW);

  //initFog();
  initTextures();
  initNPC();
  initPlayer();
  //float dimensions[3] = { (int)rand() % 8+2, (int)rand() % 8+2, (int)rand() % 6 +1};
  float dimensions[3] = { 4, 4, 3 };  
  float origin[3]     = { 1, 0, 1 };
  //printf("%d, %d, %d\n", (int)dimensions[0], (int)dimensions[1], (int)dimensions[2]); 
  room_construct.initRoom(dimensions, origin, Proom, 5);
  //glutSetCursor(GLUT_CURSOR_NONE);
  
}

void resizeGLScene(int width, int height) {
  if (height==0)
    height=1;
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
  glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
  glMatrixMode(GL_MODELVIEW);
}

void FAKE_KEYS (int key, int x, int y) {
  //printf("Key: %i\n", (int) key);
}

void move(unsigned char key, int x, int y) {
  //printf("Key: %i\n", (int) key);
  float yrotrad, xrotrad;
  switch (key) { 
  //Movement:  
  case (D):
    yrotrad = (globYrot / 180 * 3.141592654f);
    globX -= float(cos(yrotrad)) * 0.05;
    globZ -= float(sin(yrotrad)) * 0.05;
    break;

  case (A):
    yrotrad = (globYrot / 180 * 3.141592654f);
    globX += float(cos(yrotrad)) * 0.05;
    globZ += float(sin(yrotrad)) * 0.05;
    break;

  case (W):
    yrotrad = (globYrot / 180 * 3.141592654f);
    xrotrad = (globXrot / 180 * 3.141592654f);
    globX -= float(sin(yrotrad)) * 0.1;
    globZ += float(cos(yrotrad)) * 0.1;
    //globY += float(sin(xrotrad)) * 0.1;
    break;

  case (S):
    yrotrad = (globYrot / 180 * 3.141592654f);
    xrotrad = (globXrot / 180 * 3.141592654f);
    globX += float(sin(yrotrad)) * 0.1;
    globZ -= float(cos(yrotrad)) * 0.1;
    //globY -= float(sin(xrotrad)) * 0.1;
    break;
  //Interaction:
  case (E):
    // New Plan: find out which wall you are closest to,
    // then see which door you are closest to on that wall.      
    break;   
  //Options:
  case (ESCAPE):
    exit(0);  
    break; //SURE LOL
  }
  
  // Check to see if there is a door to open here:
  if (currentRoom->doorOpenCheck(globX, globY, globZ) == 1) {
    int i;
    currentRoom->setDoorOpen(globX, globY, globZ); // open that damn door
    // Generate the size of the new room
    float newRoomDim[3] = { (int)rand() % 8+2, (int)rand() % 8+2, (int)rand() % 6 +1}; 
    // Do the oh-so-fancy math to set the origin of the new room to just outside the old room    
    float *newRoomOrigin = currentRoom->returnOr();
    for (i=0;i<3;i++) {
      printf("%f\n", newRoomOrigin[i]);
      printf("%f\n", newRoomDim[i]);
    }
    for (i=0;i<=1;i++) { //Dont need to do th Z level, that would be weird.
      newRoomOrigin[i] = newRoomOrigin[i] + newRoomDim[i]; // Just look at it you dumbass
    }
    printf("l176\n");
    newRoom->initRoom(newRoomDim, newRoomOrigin, Proom2, 5); // Segfaults here. Bum val?
    isNewRoom = 1;
    printf("l178\n");
  }
}

void draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  camera();
  //^^^ Leave this stuff up here alone.
  currentRoom->draw();
  if (isNewRoom == 1)
    newRoom->draw();
  //creepy_face.draw(1);
  //All this stuff to get the FPS:
	/*frame++;
	time2=glutGet(GLUT_ELAPSED_TIME);
	if (time2 - timebase > 1000) {
		sprintf(s,"FPS:%4.2f",frame*1000.0/(time2-timebase));
		timebase = time2;		
		frame = 0;
    printf("%s\n", s);
	}*/
  glutSwapBuffers();
}
void click(int button, int state, int x, int y) {
  if (button == GLUT_LEFT_BUTTON) {
    //glTranslatef(globX,globY,globZ); 
    //glColor3f(1,0,0);
    //Cube(2, 2, 2);
  }
}
void mouseMovement(int x, int y) {
  int diffx=x-lastX;
  int diffy=y-lastY;
  lastX=x;
  lastY=y;
  //FIXME:
  //Crappy hack to avoid mouse-splosion
  if (diffx > 100)
    diffx = 3;
  if (diffy > 100)  
    diffy = 3;
  //printf("x: %d, y: %d\n", diffx, diffy);
  if (globXrot + diffy > -90 && globXrot + diffy < 90)
    globXrot += (float) diffy;
  globYrot += (float) diffx;
}

int main(int argc, char **argv)  {  
  glutInit(&argc, argv);  
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);  
  glutInitWindowSize(640, 480);  
  glutInitWindowPosition(0, 0);  
  window = glutCreateWindow("Labyrinth");
  
  glutKeyboardFunc(&move);    
  glutSpecialFunc(NULL);
  glutPassiveMotionFunc(&mouseMovement);

  glutDisplayFunc(&draw);  
  glutIdleFunc(&draw);
  glutMouseFunc(&click);
  glutReshapeFunc(&resizeGLScene);
  glutFullScreen();
  initGame(640, 480);

  glutMainLoop();  

  return 0;
}
