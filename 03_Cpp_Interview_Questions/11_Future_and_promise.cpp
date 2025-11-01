#include<iostream>
#include<thread> 
#include<chrono> 
#include<future> 

//simulate long computation in a single thread 
void computeSquare(std::promise<int> resultPromise , int value)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    int result = value * value; 
    resultPromise.set_value(result); //Send the result 
}

int main()
{
    std::promise<int> promiseObj; //Create promise 
    std::future<int> futureObj = promiseObj.get_future(); //Get associated future 

    int input = 5; 

    std::thread worker(computeSquare,std::move(promiseObj),input); 

    std::cout<<"Waiting for result...\n"; 
    int result = futureObj.get(); //Blocks until result is ready 
    std::cout<<"Result is "<<result<<"\n"; 

    worker.join(); 
    return 0;
}