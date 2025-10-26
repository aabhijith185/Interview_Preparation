#include<iostream>
using namespace std; 

class Base 
{
private:
    //Method one : Make & operator private
    // Base* operator&()
    // {
    //     return this;
    // }
public : 
    //Method two : Delete & operator 
    Base* operator&() = delete; 
}

int main()
{
	Base b;
	Base *bp = &b;
	cout<<bp<<endl;
	cout<<&b<<endl;

	return 0;
}