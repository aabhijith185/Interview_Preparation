#include<iostream>
using namespace std; 
 

void swap_endianness(int x)//0x12345678
{
    x = ((x>>24)&0xFF)|
         ((x<<24)&0xFF000000)|
         ((x>>8)&0xFF00)|
         ((x<<8)&0xFF0000);
    cout<<std::hex<<"After endianness swap: "<<
    x<<endl;
}
int main()
{
  int x = 0x12345678; 
  swap_endianness(x);
  return 0;
}
