#include<iostream>
using namespace std; 

class Base 
{
public: 
    Base() { cout<<"Bingo "<<endl;};
}; 

int main(void)
{
    Base b[10]; //calls the contructor 10 times 
    return 0;
}