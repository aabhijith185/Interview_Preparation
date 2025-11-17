#include<iostream> 
#include<thread> 

using namespace std; 
/* Thread guard is an RAII based wrapper that ensures that a thread is properly joined or detached when it goes out of scope
    ->Thread guard prevents program crashes and undefined behavior that occurs when thread object is object is destroyed 
    while still joinable 
    Why we need a thread guard 
    ->Destroying a std::thread object that is still joinable causes an immediate terminate() call 
    ->Happens when we forgot to call join() 
    ->An exception is thrown before join is executed 
    *A thread guard handles this situation by performing the join in the destructor 
*/

class thread_guard 
{
private :
    std::thread& t; 
public : 
    explicit thread_guard(std::thread& _t) : t(_t) {}

    ~thread_guard()
    {
        if(t.joinable())
        {
            t.join(); //ensures safe cleanup 
        }
    }

    //delete copy and assignment operator 
    thread_guard(const thread_guard& ) = delete; 
    thread_guard& operator==(const thread_guard&) = delete;
};

void work()
{
    std::cout<<"Working thread"<<std::endl;
}
int main(void)
{
    std::thread t(work);
    thread_guard guard(t); //RAII guard

    return 0;
}