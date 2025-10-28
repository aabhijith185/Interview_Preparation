#include<iostream>
using namespace std; 

class Int 
{
private:
    int elem; 
public:
    Int(int value) : elem(value) {}; 
    void printValue() {cout<<elem<<endl;}

    //Overload preincrement operator 
    Int& operator++()
    {
        elem++; //increment the element 
        return *this;//return the object
    }

    Int operator++(int num)
    {
        Int tmp = *this; //copy current object to a temporary object 
        ++(*this); //Increment the object ,this will be reflected after execution 
        return tmp;//olvalue is returned not the updated state 
    }
}; 

int main(void)
{
    Int i(100); 
    //Post increment 
    (i++).printValue();//100
    i.printValue(); //101

    //Pre increment 
    (++i).printValue();//102
    return 0;
}