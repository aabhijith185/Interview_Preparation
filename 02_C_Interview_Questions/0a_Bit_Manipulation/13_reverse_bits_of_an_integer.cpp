#include<iostream>
#include<cstdint>
#include<bitset>
using namespace std; 
//num 0x1234  0001 0010 0011 0100 
//rev_num 0x4321


void reverse_bits_32(uint32_t num) 
{
   //swap adjacent bits 
   num = ((num&0xAAAAAAAA)>>1) | ((num&0x55555555)<<1);
   //swap consecutive pairs  1100 0011 
   num = ((num&0xCCCCCCCC)>>2) | ((num&0x33333333)<<2);
   //swap 4 bits (nibble) 1111 0000 0000 1111
   num = ((num&0xF0F0F0F0)>>4) | ((num&0x0F0F0F0F)<<4);
   //swap bytes 
   num = ((num&0xFF00FF00)>>8) | ((num&0x00FF00FF)<<8);
   //swap 16 bit halves 
   num = (num>>16) | (num<<16);
   cout<<"Reversed bits : "<<std::bitset<32>(num)<<endl;
}

int main(void)
{
    int A = 0x12345678; 
    cout<<std::bitset<32>(A)<<endl;
    reverse_bits_32(A); 
    return 0;
}