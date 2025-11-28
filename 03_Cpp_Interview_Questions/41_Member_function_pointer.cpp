#include<iostream> 
using namespace std; 

class Math 
{
public:
    //Member function pointer inside class
    void (Math::*funcPtr)(int,int); 

    Math() : funcPtr(nullptr) {} //Initialize to NULL

    void add(int a,int b)
    {
        cout<<"Addition= "<<(a+b)<<endl;
    }
    void sub(int a,int b)
    {
        cout<<"Subtraction= "<<(a-b)<<endl;
    }

    //Method to call the stored function 
    void callFunction(int x,int y)
    {
        if(funcPtr)
            (this->*funcPtr)(x,y); 
        else 
            cout<<"Function pointer not set"<<endl;
    }
};

int main()
{
    Math m; 

    //Assign function pointer to add 
    m.funcPtr = &Math::add;
    m.callFunction(10,5);

    m.funcPtr= &Math::sub; 
    m.callFunction(10,5); 

    return 0;
}