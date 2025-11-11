#include<iostream>
#include<thread> 

class Singleton 
{
private :
    Singleton() {std::cout<<"Constructor called"<<std::endl;}; 
    static Singleton* instance; 
public : 
    static Singleton* getInstance()
    {
        if(instance == nullptr) //<- Not thread safe
        {
            instance = new Singleton(); //<- Race condition here 
        }
        return instance;
    }
}; 

Singleton* Singleton::instance = nullptr; 

void createInstance()
{
    Singleton* obj = Singleton::getInstance(); 
}

int main()
{
    //both threads will create an instance and singleton is breaked
    std::thread t1(createInstance);//constructor called 
    std::thread t2(createInstance);//constructor called 

    t1.join();
    t2.join();

    return 0;
}