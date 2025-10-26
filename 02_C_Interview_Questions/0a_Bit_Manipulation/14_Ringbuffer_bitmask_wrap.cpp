#include<iostream>
using namespace std; 

#define BUFFER_SIZE 8 

int main(void)
{
    int A[BUFFER_SIZE]; 
    int index = 0; 

    //write 20 elements into the 8 byte buffer 
    for(int i=0;i<20;i++)
    {
        A[index] = i;
        cout<<"Written "<<i<<" at index "<<index<<endl; 
        index = (index+1)&(BUFFER_SIZE-1);
    }
    return 0;
}