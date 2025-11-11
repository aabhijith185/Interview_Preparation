#include<iostream>
#include<mutex> 
#include<thread> 

using namespace std; 

class Singleton
{
private:
    Singleton() {cout<<"Constructor called"<<endl;}

    static Singleton* instance ; 
    static std::once_flag flag; 
public:
    static Singleton* getInstance()
    {
        std::call_once(flag,[](){
            instance = new Singleton(); //Only one thread will run this 
        });
        return instance ; 
    }
}; 
Singleton* Singleton::instance = nullptr; 
std::once_flag Singleton::flag; 

void createInstance()
{
    Singleton* obj = Singleton::getInstance();
}

int main(void)
{
    std::thread t1(createInstance); 
    std::thread t2(createInstance); 

    t1.join(); 
    t2.join(); 

    return 0;
}
