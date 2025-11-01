#include "sensor.hpp"

class TemperatureSensor : public sensor 
{
public: 
    void readData() override
    {
        cout<<"Read temperature sensor "<<endl;
    }
};