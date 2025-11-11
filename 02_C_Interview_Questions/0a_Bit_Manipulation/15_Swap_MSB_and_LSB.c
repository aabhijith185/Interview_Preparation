#include<stdio.h>

unsigned char swapMSBandLSB(unsigned char x)
{
    unsigned char msb_mask = 0x80;
    unsigned char lsb_mask = 0x01;
    unsigned char msb = (x&0x80)>>7; 
    unsigned char lsb =  (x&0x01)<<7; 
    //clear msb and lsb Mask 0111 1110 7E
    unsigned char mid = x&~(lsb_mask|msb_mask);

    return (mid|msb|lsb);//Combine all
}

int main()
{
    unsigned char x = 0x31; //0011 0001 
    unsigned char y = swapMSBandLSB(x); 

    printf("Original : 0x%02x\n",x);
    printf("Swapped  :  0x%02x\n",y);

    return 0;
}