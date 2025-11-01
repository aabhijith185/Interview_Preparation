#include<iostream>
#include<queue>
#include<mutex>
#include<thread> 
#include<condition_variable> 

using namespace std; 
condition_variable cv; 
mutex mtx; 
queue<int> dataQueue; 

void producer()
{
    std::unique_lock<std::mutex> lock(mtx); 
    dataQueue.push(5); 
    std::cout<<"Producer added data: "<<endl;
    cv.notify_one(); //Notify the waiting consumer 
}

void consumer()
{
    std::unique_lock<std::mutex> lock(mtx); 
    cv.wait(lock,[]{return !dataQueue.empty();});//Waiting for data 
    int data = dataQueue.front(); 
    dataQueue.pop(); 
    std::cout<<"Consumer got the data "<<data<<std::endl;
}

int main(void)
{
    std::thread t1(producer); 
    std::this_thread::sleep_for(std::chrono::seconds(2)); //delay producer 
    std::thread t2(consumer); 

    t2.join(); 
    t1.join(); 
    return 0;
}