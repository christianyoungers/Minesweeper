#ifndef MINE
#define MINE

class Mine
{
public:
     Mine(int xCoord, int yCoord);
     int xCoord() {return m_xCoord;}    
     int yCoord() {return m_yCoord;}    
     bool isOn() {return m_on;}
     void turnOn() {m_on = true;}
     void turnOff() {m_on = false;}     
     void draw();
     

private:     
     int m_xCoord;
     int m_yCoord;
     bool m_on;
     

};

#endif

