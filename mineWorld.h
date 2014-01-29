#ifndef MINE_WORLD
#define MINE_WORLD

#include "headers.h"

class MineWorld
{
public:
     MineWorld();
     ~MineWorld();
     void events();
     void logic();
     void render();
     bool isRunning() { return m_isRunning; }     
     void explode();
     bool isFlagHere(int xCoord, int yCoord);
     bool isMineHere(int xCoord, int yCoord);
     void insertMine();
     int countFlags(int xCoord, int yCoord);
     void clickedNum(int xCoord, int yCoord);
     void clickedEmpty(int xCoord, int yCoord);
          
private:  
     bool m_isRunning;
     bool m_exploded;
     SDL_Event m_event;   
     Block* m_blocks[XDIM][YDIM];
     Flag* m_flags[XDIM][YDIM];
     Mine* m_mines[LEVEL];
     int m_mineNum;
     int m_xClick;
     int m_yClick;
     bool m_leftClick;
     bool m_rightClick;
     bool m_waitingForFirstClick;
     
};

#endif
