 #include "headers.h"

Mine::Mine(int xCoord, int yCoord)
     :m_xCoord(xCoord), m_yCoord(yCoord), m_on(false)
{}

void Mine::draw()
{
     if ( m_on )
     {
	  int x = m_xCoord * BLOCKDIM;
	  int y = m_yCoord * BLOCKDIM;

	  glColor4ub(0, 100, 0, 255);

	  glBegin(GL_QUADS);
	  glVertex2f(x + (BLOCKDIM/3),   y + (BLOCKDIM/3));
	  glVertex2f(x + (BLOCKDIM*2/3), y + (BLOCKDIM/3));
	  glVertex2f(x + (BLOCKDIM*2/3), y + (BLOCKDIM*2/3));
	  glVertex2f(x + (BLOCKDIM/3),   y + (BLOCKDIM*2/3));
	  glEnd();

	  glColor4ub(0, 255, 0, 255);

	  glBegin(GL_LINES);
	  //Vertical and Horizontal Lines
	  glVertex2f(x + (BLOCKDIM/2),   y + (BLOCKDIM/4));
	  glVertex2f(x + (BLOCKDIM/2),   y + (BLOCKDIM*3/4));

	  glVertex2f(x + (BLOCKDIM/4),   y + (BLOCKDIM/2));
	  glVertex2f(x + (BLOCKDIM*3/4), y + (BLOCKDIM/2));

	  //Corner's X
	  glVertex2f(x + (BLOCKDIM/3),   y + (BLOCKDIM/3));
	  glVertex2f(x + (BLOCKDIM*2/3), y + (BLOCKDIM*2/3));

	  glVertex2f(x + (BLOCKDIM*2/3), y + (BLOCKDIM/3));
	  glVertex2f(x + (BLOCKDIM/3),   y + (BLOCKDIM*2/3));
	  glEnd();
     }
}

