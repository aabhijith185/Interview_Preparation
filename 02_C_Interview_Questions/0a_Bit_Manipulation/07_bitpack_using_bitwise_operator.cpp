#include<iostream>
#include<cstdint>
#include<bitset>
using namespace std; 

int main(void)
{
    uint8_t serial_number = 0xFB; 
    uint16_t fazit_id     = 0xAABB; 
    uint32_t merge_id     = 0xCAFEFFEE; 

    uint64_t packed_sw_data = (serial_number&0xFF)|
                              ((fazit_id&0xFFFF)<<8)|
                              ((uint64_t)(merge_id&0xFFFFFFFF)<<24);
                                                                                                          
    cout<<std::hex<<packed_sw_data<<endl;
                                                                                                                  return 0;
}