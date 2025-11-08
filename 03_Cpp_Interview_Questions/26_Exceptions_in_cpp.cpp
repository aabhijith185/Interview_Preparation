#include<iostream>
using namespace std; 

int main()
{
    try
    {
        int a =10,b=0; 
        if(b == 0)
            throw("Division by zero error");
        cout<<"Result(a/b) : "<<a/b<<endl;
    }
    catch(const char* arg)
    {
        cout<<"Division by zero exception caught"<<endl;
    }
    return 0;
}