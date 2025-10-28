#include<iostream>
using namespace std; 

struct values 
{
    int x; 
    char y; 
    string z;
}; 

values fun(bool flag )
{
    if(flag)
        return values{1,'x',"Abhijith"}; 
    else 
        return values{2,'y',"Abhishek"};
}

int main()
{
    values v; 
    v = fun(true); 
    cout<<v.x<<" "<<v.y<<" "<<v.z<<endl;
    v = fun(false); 
    cout<<v.x<<" "<<v.y<<" "<<v.z<<endl;

    return 0;
}