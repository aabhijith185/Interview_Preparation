#include<iostream>
#include<thread> 
#include<chrono> 

using namespace std;
void func1(int &x)
{
    while(true)
    {
        cout<<"Thread 1 value of X - "<<x<<endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main(void)
{-
    int x = 9; 
    cout<<"Main thread value of x: "<<x<<endl;
    std::thread thread1(func1,std::ref(x));

    x = 15; 
    cout<<"Main thread value of X has changed to "<<x<<endl;
    thread1.join();
    
    return 0;
}