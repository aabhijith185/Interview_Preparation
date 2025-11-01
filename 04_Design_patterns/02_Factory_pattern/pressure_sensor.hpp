#include "sensor.hpp"

class PressureSensor : public Sensor 
{
public:
    void readData() override 
    {
        cout<<"Read pressure sensor data"<<endl;
    }
}