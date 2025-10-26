#include<iostream>
#include<bitset>
using namespace std; 

int convert_decimal_to_binary(int num)
{
    int bin= 0; 
    int i=0;
    while(num)
    {
        bin |= (num&0x01)<<i; 
        num =num>>1; 
        i++;
    }
    return bin;
}

int main(void)
{
    int dec = 0xAA; //1010 1010
    cout<<std::bitset<8>(convert_decimal_to_binary(dec))<<endl;
    cout<<std::hex<<(convert_decimal_to_binary(dec))<<endl;
    return 0;
}