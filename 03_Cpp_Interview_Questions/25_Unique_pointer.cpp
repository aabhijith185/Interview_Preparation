#include<iostream>
#include<memory>
using namespace std; 

class Rectangle 
{
private:
    int length; 
    int breadth;
public:
    Rectangle(int l,int b)
    {
        length = l;
        breadth = b;
    }

    int area()
    {
        return length*breadth;
    }
};

int main()
{
    unique_ptr<Rectangle> ptr(new Rectangle(10,20));
    cout<<ptr->area()<<endl;

    unique_ptr<Rectangle> ptr2 = std::move(ptr);
    cout<<ptr2->area()<<endl;
    
    return 0;
}