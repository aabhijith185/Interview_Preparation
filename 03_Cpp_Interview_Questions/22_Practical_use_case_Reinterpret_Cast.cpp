#include<iostream>
#include<cstdint>
using namespace std; 

struct BinaryData
{
    uint8_t serial_number; 
    uint32_t mergeId; 
    uint32_t fazitId;
}; 

int main(void)
{
    unsigned char rawBytes[] = {0x12,0x00,0xCA,0xDD,0x12,0x34,0x00,0xCA,0xD0}; 
    //copy the array to structure 
    BinaryData *bdata = reinterpret_cast<BinaryData*>(rawBytes); 
    cout<<std::hex<<"Serial number "<<bdata->serial_number<<endl;
    cout<<std::hex<<"Merge Id "<<bdata->mergeId<<endl;
    cout<<std::hex<<"Fazit id "<<bdata->fazitId<<endl;

    return 0;
}
