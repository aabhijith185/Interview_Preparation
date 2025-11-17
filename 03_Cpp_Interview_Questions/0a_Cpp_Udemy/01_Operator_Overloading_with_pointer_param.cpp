#include<iostream>

//Max function for int 
int max(int *arr,size_t count)
{
    std::cout<<"Int overload called "<<std::endl;
    int max{0}; 
    for(size_t i = 0;i<count;i++)
    {
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}
//overloaded function for double 
double max(double *arr,size_t count)
{
    std::cout<<"Double  overload called "<<std::endl;
    double max{0}; 
    for(size_t i = 0;i<count;i++)
    {
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}

int main(void)
{
    double doubles[]{11.2,12.3,9.8,5.7};
    int ints[]{1,2,8,4,5}; 

    auto result = max(ints,std::size(ints));
    std::cout<<"Result : "<<result<<std::endl;

    auto result1 = max(doubles,std::size(ints));
    std::cout<<"Result : "<<result1<<std::endl;

    return 0;
}