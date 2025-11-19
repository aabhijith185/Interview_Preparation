#include<iostream>
#include<thread>

int main(){

    //launch a thread using lambda function 
    std::thread t([](){
        std::cout << "Thread launched using lambda function!" << std::endl;
    });
    t.join(); //wait for the thread to finish
    return 0;
}