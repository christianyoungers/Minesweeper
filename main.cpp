/*
Compile command
 g++ game.cpp -lSDLmain -lSDL -lGL
 */

#include "headers.h"

using namespace std;

void initialize()
{
     srand(time(NULL));

     //Initialize Everything
     SDL_Init(SDL_INIT_EVERYTHING);

     //set OprnGl memory usage
     SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
     SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
     SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
     SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
     SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
     SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
     SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

     //Caption of the Window
     SDL_WM_SetCaption("Minesweeper", NULL);

     //Set the size of the Window
     SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_OPENGL);

     //Specify the clear screen color, (RED, GREEN, BLUE, ALPHA)
     glClearColor(0, 0, 0, 1);  

     //What portion of the screen will be displayed
     glViewport(0, 0, WIDTH, HEIGHT);

     //makes pixels gradually change from blue to red, Shader model
     glShadeModel(GL_SMOOTH);

     //2D rendering 
     glMatrixMode(GL_PROJECTION);

     //"Save" the 2D rendering
     glLoadIdentity();

     //disables depth checking
     glDisable(GL_DEPTH_TEST);
}


//start of the program
int main (int argc, char* args[])
{
     initialize(); 
     glutInit(&argc, args);

     cout << "Minesweeper is Working\n";

     MineWorld world;

     //Main game loop
     while ( world.isRunning() )
     { 
	  world.events();
	  world.logic();
	  world.render();
     }

     SDL_Quit();

     return 0;

}
