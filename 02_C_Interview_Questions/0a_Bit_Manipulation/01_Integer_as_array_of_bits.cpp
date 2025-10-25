#include<iostream>
#include<cstdint>

using namespace std; 

uint64_t array_of_bits = 0; 

#define BIT_LEN 64

#define SET_BIT(BF,N) BF |= ((uint64_t)(1)<<N)
#define CLR_BIT(BF,N) BF &= ~((uint64_t)(1)<<N)

#define IS_BIT_SET(BF,N) ((BF>>N)&(uint64_t)(1))

void printBins(uint64_t array_of_bits)
{
    for(int i=BIT_LEN-1;i>=0;i--)
    {
        if(IS_BIT_SET(array_of_bits,i))
            cout<<"1";
        else 
            cout<<"0";

        if(i%8 == 0 && i != 0)
            cout<<" ";
    }
    cout<<endl;
}

int  main()
{
    SET_BIT(array_of_bits,0); //Set Bit  0 
    SET_BIT(array_of_bits,2); 
    SET_BIT(array_of_bits,4); 
    SET_BIT(array_of_bits,13); 
    SET_BIT(array_of_bits,45); 

    printBins(array_of_bits); 

    return 0;
    
}
