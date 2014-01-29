#include "headers.h"

MineWorld::MineWorld()
     : m_isRunning(true), m_exploded(false), m_mineNum(0), m_leftClick(false), m_rightClick(false), m_waitingForFirstClick(true)
{
     //create all of the flags and blocks
     for ( int i = 0; i < XDIM; i++ )
	  for ( int j = 0; j < YDIM; j++ )
	  {
	       m_blocks[i][j] = new Block(i, j);
	       m_flags[i][j] = new Flag(i, j);
	  }

     //create all of the mines
     for ( int i = 0; i < LEVEL; i++ )
	  insertMine();

     //get the counts for all of the mines
     for ( int k = 0; k < LEVEL; k++ )
	  for ( int i = 0; i < 3; i++ )
	       for ( int j = 0; j < 3; j++ )
	       {
		    int x = m_mines[k]->xCoord()-1+i;
		    int y = m_mines[k]->yCoord()-1+j;
		    if ( x < 0 || x >= XDIM || y < 0 || y >= YDIM )
			 continue;
		    if ( !isMineHere(x, y) )
			 m_blocks[x][y]->upCount();
	       }
}

MineWorld::~MineWorld()
{
     //delete blocks and flags
     for ( int i = 0; i < XDIM; i++ )
	  for ( int j = 0; j < YDIM; j++ )
	  {
	       delete m_blocks[i][j];
	       delete m_flags[i][j];
	  }

     //delete mines
     for ( int i = 0; i < LEVEL; i++ )
	  delete m_mines[i];
}

void MineWorld::events()
{
     //EVENTS
     while ( SDL_PollEvent(&m_event) )
     {
	  //exit button at top of window
	  if ( m_event.type == SDL_QUIT )
	       m_isRunning = false;
 
	  //key released
	  if ( m_event.type == SDL_KEYUP )
	       switch ( m_event.key.keysym.sym )
	       {
	       case SDLK_ESCAPE:
		    m_isRunning = false;
		    break;
	       case SDLK_q:
		    explode();
		    break;
	       }
 
	  //if the mouse button was clicked, record data
	  if ( m_event.type == SDL_MOUSEBUTTONDOWN )
	  {
	       m_xClick = m_event.button.x / BLOCKDIM;
	       m_yClick = m_event.button.y / BLOCKDIM;
	       if ( m_event.button.button == SDL_BUTTON_LEFT )
		    m_leftClick = true;
	       else if ( m_event.button.button == SDL_BUTTON_RIGHT )
		    m_rightClick = true;
	  }
     }
}

void MineWorld::logic()
{
     if ( ! m_exploded )
     {
	  if ( m_leftClick ) 
	  {
	       m_leftClick = false;
 
	       //if the block has its number showing
	       if ( ! m_blocks[m_xClick][m_yClick]->isOn() &&
		    ! m_blocks[m_xClick][m_yClick]->hasNoCount() )
	       {
		    //check to open the blocks around the number
		    clickedNum(m_xClick, m_yClick);
		    return;
	       }	       

	       //if no flag
	       if ( ! isFlagHere(m_xClick, m_yClick) )
	       {
		    //open the block
		    m_blocks[m_xClick][m_yClick]->turnOff();

		    //check if a mine exploded
		    if ( isMineHere(m_xClick, m_yClick) )
			 explode();

		    //check if an empty block was opened
		    if ( m_blocks[m_xClick][m_yClick]->hasNoCount() && 
			 ! isMineHere(m_xClick, m_yClick) )
			 clickedEmpty(m_xClick, m_yClick);

		    return;
	       }
	  }
	  else if ( m_rightClick )
	  {
	       m_rightClick = false;

	       if ( ! isFlagHere(m_xClick, m_yClick) && 
		    m_blocks[m_xClick][m_yClick]->isOn() )
		    m_flags[m_xClick][m_yClick]->turnOn();
	       else 
		    m_flags[m_xClick][m_yClick]->turnOff();
	  }
     }
}

void MineWorld::render()
{
     //RENDERING to the screen
     glClear(GL_COLOR_BUFFER_BIT);
     glPushMatrix(); //start phase
     glOrtho(0, WIDTH, HEIGHT, 0, -1, 1); //Set the matrix
 
     //draw blocks and flags
     for ( int i = 0; i < XDIM; i++ )
	  for ( int j = 0; j < YDIM; j++ )
	  {
	       m_blocks[i][j]->draw();
	       m_flags[i][j]->draw();
	  }

     //draw mines
     for ( int i = 0; i < LEVEL; i++ )
    	  m_mines[i]->draw();

     glPopMatrix();  //end phase 

     SDL_GL_SwapBuffers();
}

void MineWorld::explode()
{
     //turn on all mines
     for ( int i = 0; i < LEVEL; i++ )
	  if ( !isFlagHere(m_mines[i]->xCoord(), m_mines[i]->yCoord()) )
	       m_mines[i]->turnOn();

     m_exploded = true;
}

bool MineWorld::isFlagHere(int xCoord, int yCoord)
{
     return m_flags[xCoord][yCoord]->isOn();
}

bool MineWorld::isMineHere(int xCoord, int yCoord)
{
     //check all mines if x and y match
     for ( int i = 0; i < m_mineNum; i++ )
	  if ( xCoord == m_mines[i]->xCoord() &&
	       yCoord == m_mines[i]->yCoord() )
	       return true;

     return false;
}

void MineWorld::insertMine()
{
     int xCoord = rand() % XDIM;
     int yCoord = rand() % YDIM;

     while ( isMineHere(xCoord, yCoord) )
     {
	  xCoord = rand() % XDIM;
	  yCoord = rand() % YDIM;
     }

     m_mines[m_mineNum] = new Mine(xCoord, yCoord);
     m_mineNum++;
}

int MineWorld::countFlags(int xCoord, int yCoord)
{
     int count = 0;
     for ( int i = 0; i < 3; i++ )
	  for ( int j = 0; j < 3; j++ )
	  {
	       int x = xCoord-1+i;
	       int y = yCoord-1+j;
	       if ( x < 0 || x >= XDIM || y < 0 || y >= YDIM )
		    continue;
	       if ( isFlagHere(x, y) )
		    count++;
	  }

     return count;
}

void MineWorld::clickedNum(int xCoord, int yCoord)
{
     if ( countFlags(xCoord, yCoord) == m_blocks[xCoord][yCoord]->count() )
     {
	  for ( int i = 0; i < 3; i++ )
	       for ( int j = 0; j < 3; j++ )
	       {
		    int x = xCoord-1+i;
		    int y = yCoord-1+j;
		    if ( x < 0 || x >= XDIM || y < 0 || y >= YDIM )
			 continue;
		    if ( ! isFlagHere(x, y) )
		    {
			 m_blocks[x][y]->turnOff();
			 if ( isMineHere(x, y) )
			      explode();
		    }
	       }
     }
}

void MineWorld::clickedEmpty(int xCoord, int yCoord)
{
/*
     bool hasCount = ! m_blocks[xCoord][yCoord]->hasNoCount();

     //base case, if a numbered block is reached
     if ( hasCount )
     {
	  m_blocks[xCoord][yCoord]->turnOff();
	  return;
     }

     
    
     //if there is no flag
     if ( ! isFlagHere(xCoord, yCoord) )
	  m_blocks[xCoord][yCoord]->turnOff();
*/

     bool hasCount = ! m_blocks[xCoord][yCoord]->hasNoCount();

     if ( hasCount )
	  return;

     //check blocks touching current block
     for ( int i = 0; i < 3; i++ )
	  for ( int j = 0; j < 3; j++ )
	  {
	       int x = xCoord-1+i;
	       int y = yCoord-1+j;

	       //check that block is valid on the board
	       if ( x < 0 || x >= XDIM || y < 0 || y >= YDIM )
		    continue;

	       if ( ! m_blocks[x][y]->hasNoCount() )
	       {
		    m_blocks[x][y]->turnOff();
		    continue;
	       }

	       if ( m_blocks[x][y]->isOn() && m_blocks[x][y]->hasNoCount() )
	       {
		    m_blocks[x][y]->turnOff();
		    clickedEmpty(x, y);
	       }
	  }
}
