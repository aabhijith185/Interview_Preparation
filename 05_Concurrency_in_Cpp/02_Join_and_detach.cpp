#pragma once 
#include<thread> 
#include<iostream> 
#include<chrono> 

using namespace std;

void foo()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    cout<<"Hello from foo()"<<endl;
}

void bar()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    cout<<"Hello from bar()"<<endl;
}

int main(void)
{
    thread foo_thread(foo); 
    thread bar_thread(bar); 
    bar_thread.detach();
    cout<<"After bar thread detach "<<endl; 
    foo_thread.join(); 
    cout<<"After foo thread join "<<endl;

    return 0;
}