#include<iostream>
using namespace std; 

void func()
{
    cout<<"Inside base class"<<endl;
}

class Base 
{
public:
    Base(){func();};
};

Base b; 

int main(void)
{
    return 0;
}