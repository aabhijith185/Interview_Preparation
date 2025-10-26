#include<iostream>
using namespace std; 

int first_non_repeating_char(int *A,int len)
{
    int res = 0; 
    for(int i=0;i<len;i++)
    {
        res = res ^ A[i]; 
    }
    return res;
}

int main(void)
{
    int A[5] = {1,2,3,1,2}; 
    cout<<"First non repeating character: "<<first_non_repeating_char(A,5)<<endl; 
    return 0;
}