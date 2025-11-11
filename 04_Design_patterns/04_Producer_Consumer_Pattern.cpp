#include<iostream> 
#include<queue> 
#include<thread> 
#include<mutex> 
#include<condition_variable> 

using namespace std; 

queue<int> buffer; 
const unsigned int MAX_SIZE = 10; 
std::mutex mtx; 
std::condition_variable cv; 

//Producer thread function 
void producer()
{
    for(int i=0;i<MAX_SIZE;i++)
    {
        std::unique_lock lock(mtx); //Lock mutex to access the shared buffer 
        //Fill data till size<MAX_SIZE
        cv.wait(lock,[](){return buffer.size()<MAX_SIZE;});
        buffer.push(i);
        std::cout<<"Produced: "<<i<<endl;
        //Notify the waiting consumer that data is available 
        cv.notify_one();
    }
}

//consumer thread function 
void consumer()
{
    for(int i=0;i<10;i++)
    {
        std::unique_lock<std::mutex> lock(mtx); 
        cv.wait(lock,[](){ return !buffer.empty();});
        int value = buffer.front();
        buffer.pop(); 
        cout<<"Consumed: "<<value<<endl;
        cv.notify_one();
    }
}

int main(void)
{
    //Launch producer and consumer threads
    std::thread prod(producer);
    std::thread cons(consumer); 

    //Wait for the threads to complete 
    prod.join(); 
    cons.join(); 

    return 0;
}