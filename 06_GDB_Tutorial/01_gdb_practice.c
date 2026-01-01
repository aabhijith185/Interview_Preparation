#include<stdio.h>

int foo(int x,int y){
    x = x*2;
    y = y+3;
    return x+y;
}

int main()
{
    int a = 10; 
    int b = 20;

    printf("foo = %d\n",foo(a,b));
    return 0;
}