#include<iostream>
using namespace std; 

union Endian
{
    int x; 
    char c;
}en; 

int main()
{
    en.x = 0x12345678; 
    if(en.c == (en.x&0xFF))
        cout<<"Little endian"<<endl;
    else 
        cout<<"Big endian"<<endl;

    return 0;
}
