#include<thread> 
#include<iostream> 
#include<chrono>

using namespace std::literals;

//Stop_token tells the compiler there can be interruptible points in the function 
void do_some_work(std::stop_token token)
{
    int counter{0};
    while(counter<10)
    {
        if(token.stop_requested())
        {
            return ; 
        }
        std::this_thread::sleep_for(0.2s);
        std::cerr<<"This is an interruptible thread : "<<std::endl;
        ++counter;
    }

}

int main()
{
    //Jthread manages the lifecycle implicitely and we dont need to use a join call implicitly 
    std::jthread interruptible_thread(do_some_work);

    std::this_thread::sleep_for(1.0s);
    interruptible_thread.request_stop();


    return 0;
}