#include<iostream>
using namespace std; 

int  add(int a,int b)
{
    int carry = 1; 
    while(carry)
    {
        carry = a&b; 
        a = a^b; 
        //propagate carry 
        b = carry<<1;
    }
    return a;
}

int square(int num)
{
    int tmp = num;  
    for(int i=1;i<tmp;i++)
    {
        num = add(num,tmp); 
    }
    return num;
}

int main(void)
{
    cout<<"Square(9): "<<square(9)<<endl; 
    return 0;
}