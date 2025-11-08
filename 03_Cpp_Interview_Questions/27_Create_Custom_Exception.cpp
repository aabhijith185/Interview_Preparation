#include<iostream>
#include<exception>
using namespace std;

class Myexception : public exception
{
public:
    const char * what() const noexcept override 
    {
        return "Custom exception occured!";
    }
};

int divide(int a,int b)
{
    if(b==0)
    {
        throw Myexception(); //Throwing custom exception 
    }
    return a/b;
}

int main()
{
    try
    {
        cout<<divide(10,0)<<endl;
    }
    catch(const Myexception &e)
    {
        cout<<"Caught exception: "<<e.what()<<endl;
    }
    return 0;
}