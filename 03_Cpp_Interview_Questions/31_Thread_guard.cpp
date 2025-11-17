#include<iostream> 
#include<thread> 

using namespace std; 

class thread_guard 
{
    std::thread &t;
public:
    //explicit constructor 
    explicit thread_guard(std::thread &_t) : t(_t) {}; 

    //destructor 
    ~thread_guard()
    {
        if(t.joinable())
        {
            t.join();
        }
    }
    //delete copy and move assignment 
    thread_guard(const thread_guard&) = delete; 
    thread_guard& operator=(const thread_guard& ) = delete;
}; 

void worker()
{
    cout<<"Worker thread called!"<<endl;
}

int main(void)
{
    thread t1(worker); 
    thread_guard guard(t1);//RAII wrapper 

    return 0;
}