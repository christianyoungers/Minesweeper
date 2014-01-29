#include "headers.h"

Block::Block(int xCoord, int yCoord)
     : m_xCoord(xCoord), m_yCoord(yCoord), m_x(xCoord * BLOCKDIM), m_y(yCoord * BLOCKDIM), m_dim(BLOCKDIM), m_on(true), m_count(0)
{}

void Block::draw()
{ 
     if ( m_on )
     {
	  glColor4ub(150, 150, 150, 255);
	  glBegin(GL_LINES);
	  glVertex2f(m_x,             m_y);
	  glVertex2f(m_x + m_dim - 1, m_y);

	  glVertex2f(m_x + m_dim - 1, m_y);
	  glVertex2f(m_x + m_dim - 1, m_y + m_dim - 1);

	  glVertex2f(m_x + m_dim - 1, m_y + m_dim - 1);
	  glVertex2f(m_x,             m_y + m_dim - 1);

	  glVertex2f(m_x,             m_y + m_dim - 1);
	  glVertex2f(m_x,             m_y);
	  glEnd();

     }
     else
     {
	  glColor4ub(120, 120, 120, 255);
	  glBegin(GL_QUADS);
	  glVertex2f(m_x,             m_y);
	  glVertex2f(m_x + m_dim - 1, m_y);
	  glVertex2f(m_x + m_dim - 1, m_y + m_dim - 1);
	  glVertex2f(m_x,             m_y + m_dim - 1);
	  glEnd();

	  if ( m_count > 0 )
	  {
	       switch (m_count)
	       {
	       case 1:
		    blue();
		    break;
	       case 2:
		    green();
		    break;
	       case 3:
		    red();
		    break;
	       case 4:
		    purple();
		    break;
	       case 5:
		    brown();
		    break;
	       case 6:
		    orange();
		    break;
	       case 7:
		    yellow();
		    break;
	       case 8:
		    black();
		    break;
	       }

	       glColor4ub(m_numR, m_numG, m_numB, 255);
	       glRasterPos2f(m_x + m_dim/3, m_y + m_dim*2/3);
	       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0' + m_count);
	  }
     }


}
