#include<iostream>
#include<cstdint>
#include<bitset>

using namespace std; 

uint8_t ones_compliment(uint8_t num)
{
    return num ^ 0xFFFFFFFF;
}

uint8_t twos_compiment(uint8_t num)
{
    return ones_compliment(num)+1;
}

int main()
{
    uint8_t num = 0b10110010; 
    cout<<bitset<8>(ones_compliment(num))<<endl;
    cout<<bitset<8>(twos_compiment(num))<<endl;
    return 0;
}