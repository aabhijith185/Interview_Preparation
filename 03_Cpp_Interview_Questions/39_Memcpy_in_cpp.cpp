#include<iostream> 
#include<cstring> 


int main(void)
{
    int src[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int dest[3][3]; 
    
    std::cout<<sizeof(src)<<std::endl;

    std::cout<<"Printout copied 2d array"<<std::endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            std::cout<<dest[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}