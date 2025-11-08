#include<iostream>
using namespace std; 

class Singleton 
{
private:
    //Private constructor to prevent direct instantiation 
    Singleton() 
    {
        cout<<"Singleton instance created "<<endl;
    }
    //Delete copy constructor and assignment operator 
    Singleton(const Singleton&) = delete; 
    Singleton& operator=(const Singleton&) = delete; 
public:
    static Singleton& getInstance()
    {
        static Singleton instance; 
        return instance;
    }

    void displayMessage()
    {
        cout<<"Hello from singleton message: "<<endl;
    }
};

int main()
{
    //Access the singleton instance 
    Singleton& instance1 = Singleton::getInstance();
    instance1.displayMessage(); 

    Singleton& instance2 = Singleton::getInstance();
    instance2.displayMessage(); 

    cout<<"Are instance 1 and instance 2 the same? "<<(&instance1==&instance2)<<endl;
    return 0;
}