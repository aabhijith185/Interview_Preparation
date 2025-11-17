#pragma once 
#include<iostream> 
#include<thread> 
using namespace std;


void foo()
{
    std::cout<<"Hello from foo -"<<std::this_thread::get_id()<<std::endl;
}

class Callable_Class 
{
public:
    void operator()()
    {
        std::cout<<"Hello from class within function call operator- "<<std::this_thread::get_id()<<std::endl;
    }
};

int main(void)
{
    //passing function as parameter 
    std::thread thread1(foo); 
    thread1.join(); 

    Callable_Class obj; 
    std::thread thread2(obj);
    thread2.join();
    printf("Hello from main %d\n",std::this_thread::get_id());

    return 0;

}