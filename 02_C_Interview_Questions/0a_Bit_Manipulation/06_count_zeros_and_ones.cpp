#include<iostream>
#include<cstdint>
using namespace std; 

void count_ones_zeros(uint8_t num)
{
    int ones_count = 0; 
    int zeros_count = 0; 
    while(num)
    {
        if(num&0x01)
            ones_count++; 
        else
            zeros_count++; 
        num = num>>1;
    }
    cout<<"zero count: "<<zeros_count<<endl<<"Ones_count: "<<ones_count<<endl;
}

int main()
{
    uint8_t num = 0b11100101; 
    count_ones_zeros(num); 
    return 0;
}