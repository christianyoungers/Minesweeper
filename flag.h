#ifndef FLAG
#define FLAG

class Flag
{
public:
     Flag(int xCoord, int yCoord);
     bool isOn() { return m_on; }
     void turnOn() { m_on = true; }
     void turnOff() { m_on = false; }     
     void draw();
     

private:     
     int m_xCoord;
     int m_yCoord;
     bool m_on;
     

};

#endif

