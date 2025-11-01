#pragma once 
#include<iostream> 

class Sensor 
{
public:
    virtual void readData() = 0; 
    void ~Sensor() = default; 
};