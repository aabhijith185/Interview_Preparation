#include<iostream>
using namespace std; 

/*
2 ^0 -> 1 
2^1  -> 10 01
2^2  -> 100; 3 011
2^3  -> 1000 ; 7 = 0111
2^4  -> 10000 ; 15 1111
*/
void ispower_of_2(int x)
{
    if((x&(x-1))== 0)
       cout<<"is power of 2"<<endl; 
    else    
        cout<<"is not power of 2"<<endl;
}

int main(void)
{
    int x = 4; 
    ispower_of_2(x);
    return 0;
}