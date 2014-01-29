#ifndef BLOCK
#define BLOCK

class Block
{
public:
     Block(int xCoord, int yCoord);
     bool isOn() {return m_on;}
     bool turnOff() {m_on = false;}     
     void draw();     
     void blue()   {m_numR = 0;   m_numG = 0;   m_numB = 200;}  //1
     void green()  {m_numR = 0;   m_numG = 255; m_numB = 0;}    //2
     void red()    {m_numR = 200; m_numG = 0;   m_numB = 0;}    //3
     void purple() {m_numR = 120; m_numG = 0;   m_numB = 120;}  //4
     void brown()  {m_numR = 60;  m_numG = 60;  m_numB = 30;}   //5
     void orange() {m_numR = 200; m_numG = 50;  m_numB = 0;}    //6
     void yellow() {m_numR = 200; m_numG = 200; m_numB = 0;}    //7
     void black()  {m_numR = 0;   m_numG = 0;   m_numB = 0;}    //8
     bool hasNoCount() {return m_count == 0;}
     void upCount() {m_count++;}
     int count() {return m_count;}
          

private:
     int m_xCoord;
     int m_yCoord;
     int m_x;
     int m_y;
     int m_dim;
     bool m_on;
     int m_count;
     int m_numR;
     int m_numG;
     int m_numB;
               
};

#endif
