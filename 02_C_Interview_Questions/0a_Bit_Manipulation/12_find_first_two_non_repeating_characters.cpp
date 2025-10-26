#include<iostream>
using namespace std; 

void first_two_non_repeating_characters(int A[],int n)
{
    int xor_all = 0 ; 
    for(int i = 0;i<n;i++)
        xor_all ^= A[i]; 

    //3 ^ 5  = 011^ 101 = 111 = 7 
    // 111 & -(111) = 111 & 001 = 001 
    int righmost_set_bit = xor_all & (-xor_all); 
    int num1 = 0,num2 = 0; 
    //Divide elements into tqo group based on LSB 
    for(int i=0;i<n;i++)
    {
        if(A[i]&righmost_set_bit)
            num1 ^= A[i]; 
        else 
            num2 ^= A[i]; 
    }
    cout<<"First two non-repeating characters are "<<num1<<" and "<<num2<<endl;
}

int main(void)
{
    int A[7] = {1,2,3,4,5,2,1}; 
    first_two_non_repeating_characters(A,6); 

    return 0;
}