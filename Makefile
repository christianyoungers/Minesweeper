CC = g++
FLAGS = -c
LIBS = -lSDLmain -lSDL -lGL -lglut
SOURCES = main.cpp block.cpp mineWorld.cpp mine.cpp flag.cpp
HEADERS = block.h mineWorld.h mine.h flag.h
GLOBALS = headers.h globals.h
OBJECTS = $(SOURCES:.cpp=.o)

all: Minesweeper

Minesweeper: $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@ 

main.o: main.cpp $(GLOBALS) mineWorld.h
	$(CC) $(FLAGS) main.cpp $(LIBS)

block.o: block.cpp block.h $(GLOBALS)
	$(CC) $(FLAGS) block.cpp $(LIBS)

mineWorld.o: mineWorld.cpp $(GLOBALS) $(HEADERS)
	$(CC) $(FLAGS) mineWorld.cpp $(LIBS)

mine.o: mine.cpp mine.h $(GLOBALS) 
	$(CC) $(FLAGS) mine.cpp $(LIBS)

flag.o: flag.cpp flag.h $(GLOBALS)
	$(CC) $(FLAGS) flag.cpp $(LIBS)

clean: 
	rm -rf *o *~ Minesweeper