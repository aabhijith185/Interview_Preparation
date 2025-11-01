#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std; 

mutex mtx; 
condition_variable cv; 
bool isOdd = true; //Shared resource b/w threads 

void printOdd(int n)
{

    for(int i=1;i<=n;i+=2)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[]{return isOdd;});//Wait for the flag to be true to release lock 
        cout<<i<<" ";
        isOdd = false; 
        cv.notify_all();
    }
}
void printEven(int n)
{
    for(int i=2;i<=n;i+=2)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[]{return !isOdd;});//Wait for the flag to be true to release lock 
        cout<<i<<" ";
        isOdd = true; 
        cv.notify_all();
    }
}

int main(void)
{
    int n = 10; 
    std::thread t1(printOdd,n); 
    std::thread t2(printEven,n); 

    t1.join(); 
    t2.join();
    return 0;
}