CC = g++

Simplecpp = ./simplecpp
SCPP = -I$(Simplecpp)/include -L$(Simplecpp)/lib -lsprite -lX11

GLUT = -lGL -lGLU -lglut

EXEC_DIR = object_files

CPP_FILES = $(wildcard *.cpp)
EXEC_FILES = $(patsubst %.cpp,$(EXEC_DIR)/%,$(CPP_FILES))

all : $(EXEC_FILES)

$(EXEC_DIR)/% : %.cpp
	$(CC) $^ $(GLUT) $(SCPP) -o $@

.PHONY : clean

clean :
	rm $(EXEC_DIR)/*