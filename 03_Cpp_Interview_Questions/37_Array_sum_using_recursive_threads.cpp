#include<iostream> 
#include<thread> 

int recursiveSum(int *arr,int start,int end)
{
    //Base case : only one element 
    if(start == end)
        return arr[start];

    int mid = (start+end)/2; 
    int leftsum =0; 

    //thread to compute left half
    std::thread leftthread([&](){
        leftsum = recursiveSum(arr,start,mid);
    });

    //Main thread computes righthalf 
    int rightSum = recursiveSum(arr,mid+1,end); 

    //Wait for left thread to finish 
    leftthread.join(); 

    return leftsum + rightSum;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8}; 
    int size = sizeof(arr)/sizeof(arr[0]); 

    int total = recursiveSum(arr,0,size-1); 
    std::cout<<"Total sum = "<<total<<std::endl;

    return 0;
}