#include<iostream>
#include<thread> 
#include<atomic> 

std::atomic<int> counter(0); 

void increment()
{
    for(int i=0;i<1000;i++)
        counter++;
}

int main(void)
{
    std::thread t1(increment);
    std::thread t2(increment); 
    t1.join(); 
    t2.join(); 

    std::cout<<"Final counter "<<counter<<std::endl;
    return 0;
}