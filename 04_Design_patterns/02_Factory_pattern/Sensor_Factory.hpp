#include "sensor.hpp"
#include "pressure_sensor.hpp"
#include "temperature_sensor.hpp"
#include<string>
#include<memory>

class SensorFactory 
{
public: 
    static std::unique_ptr<Sensor> createSensor(const std::string& type)
    {
        if(type == "temp")
        {
            return std::make_unique<TemperatureSensor>();
        }
        else if(type == "pressure")
        {
            return std::make_unique<PressureSensor>();
        }

        return nullptr;
    }
}

