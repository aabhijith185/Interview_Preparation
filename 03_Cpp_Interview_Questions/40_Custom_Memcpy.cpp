#include<iostream> 

void *my_memcpy(void *dest,const void* src,size_t n)
{
    //convert to unsigned char pointers for byte level access 
    unsigned char *d = static_cast<unsigned char*>(dest);
    const unsigned char *s = static_cast<const unsigned char*>(src);

    //copy n bytes 
    for(size_t i=0;i<n;i++)
    {
        d[i] = s[i];
    }

    return dest;
}

int main(void)
{
    int src[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    }; 

    int dest[3][3]; 

    //Use custom memcpy 
    my_memcpy(dest,src,sizeof(src)); 

    //Print to verify 
    std::cout<<"Copied 2D Array"<<std::endl; 
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            std::cout<<dest[i][j]<<" ";
        }
        std::cout<<"\n";
    }

    return 0;
}