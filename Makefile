#OBJS specifies which files to compile as part of the project
OBJS = main.cpp game.cpp texture_manager.cpp game_object.cpp map.cpp vector2d.cpp collision.cpp ecs/ecs.cpp

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -std=c++14

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2main -lSDL2 -lSDL2_image 

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
	./main