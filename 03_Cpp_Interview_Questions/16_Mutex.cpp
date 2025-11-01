#include<iostream>
#include<thread>
#include<mutex> 

using namespace std; 

mutex mtx; 
int shared_counter = 0; 

void increment()
{
    mtx.lock();//lock the mutex 
    ++shared_counter; 
    cout<<"Thread: "<<std::this_thread::get_id()<<"Incremented counter"<<endl;
    mtx.unlock();
}

int main(void)
{
    thread t1(increment);
    thread t2(increment); 

    t1.join(); 
    t2.join();

    cout<<"Final counter value : "<<shared_counter<<endl;

    return 0;
}