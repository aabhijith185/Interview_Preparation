#include<iostream>
#include<span>
#include<vector> 

/* 
std::span is used for having a non-owning view over a contiguous sequence of element 

*/
void print(std::span<int> data)
{
    for(int x : data)
        std::cout<<x<<" "; 
    std::cout<<"\n";
}

int main()
{
    int arr[] = {1,2,3,4,5}; 
    std::vector<int> vec = {1,2,3,4,5}; 

    print(arr); 
    print(vec); 

    return 0;
}