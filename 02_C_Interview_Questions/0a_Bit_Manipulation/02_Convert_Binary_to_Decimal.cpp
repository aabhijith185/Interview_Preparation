#include<iostream>
#include<cmath>
#include<bitset>

using namespace std;

int bin_to_decimal(int bin)
{
    int power_of_2 = 1 ; //2^0
    int decimal_value = 0;

    while(bin)
    {
        //extract the last bit 
        int last_bit = bin&0x01;
        decimal_value = decimal_value+ (last_bit*power_of_2); 
        power_of_2 = power_of_2<<1;// double power of 2
        bin = bin>>1;
    }
    return decimal_value;
}

int main(void)
{
    int bin = 0b1011011;
    cout<<std::bitset<8>(bin)<<endl;
    cout<<"Decimal value : "<<bin_to_decimal(bin)<<endl;
    return 0;
}