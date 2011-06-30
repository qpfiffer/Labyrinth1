]INCLUDE = -I/usr/include/
LINKER = -lglut -lGL -lGLU -lm -lglpng #lX11 -lXi -lXmu -lxcb 
NAME = labyrinth
LIBDIR  = -L/usr/X11R6/lib 
COMPILERFLAGS = -Wall -Wno-write-strings
OBJFILES = shape.o rooms.o npc.o physics.o textures.o
EVERYTHING = $(INCLUDE) $(LIBDIR) $(LINKER) $(COMPILERFLAGS)

all:	labyrinth.cpp labyrinth.h
	g++ $(EVERYTHING) -c shape.cpp
	g++ $(EVERYTHING) -c rooms.cpp
	g++ $(EVERYTHING) -c npc.cpp
	g++ $(EVERYTHING) -c physics.cpp
	g++ $(EVERYTHING) -c textures.cpp
	g++ $(EVERYTHING) -o $(NAME) labyrinth.cpp $(OBJFILES)
clean:
	rm labyrinth
