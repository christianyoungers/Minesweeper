#include "headers.h"

Flag::Flag(int xCoord, int yCoord)
     :m_xCoord(xCoord), m_yCoord(yCoord), m_on(false)
{}

void Flag::draw()
{
     if ( m_on )
     {
	  int x = m_xCoord * BLOCKDIM;
	  int y = m_yCoord * BLOCKDIM;

	  glColor4ub(255, 0, 0, 255);
	  glBegin(GL_TRIANGLES);
	  glVertex2f(x + (BLOCKDIM/4),   y + (BLOCKDIM/4));
	  glVertex2f(x + (BLOCKDIM*3/4), y + (BLOCKDIM/2));
	  glVertex2f(x + (BLOCKDIM/4),   y + (BLOCKDIM/2));
	  glEnd();

	  glColor4ub(255, 255, 255, 255);
	  glBegin(GL_LINES);
	  glVertex2f(x + (BLOCKDIM/4),   y + (BLOCKDIM/4));
	  glVertex2f(x + (BLOCKDIM/4),   y + (BLOCKDIM*3/4));
	  glEnd();
     }
}
