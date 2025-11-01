#include "Sensor_Factory.hpp"

int main()
{
    auto sensor1 = Sensor_Factory::createSensor("temp");
    auto sensor2 = Sensor_Factory::createSensor("pressure");
}