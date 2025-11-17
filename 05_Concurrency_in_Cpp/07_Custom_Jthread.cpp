#include<thread>
#include<atomic>
#include<future> 
#include<iostream> 

using namespace std::literals;

//The flag will be set when we call interrupt on the new thread
class interrupt_flag{
    bool local_flag; 
public:
    void set()
    {
        local_flag = true;
    }
    bool is_set()
    {
        return local_flag;
    }
};

thread_local interrupt_flag this_thread_flag; 

class jthread_local{
    std::thread _thread; 
    interrupt_flag* flag;
public:
    template<typename FunctionType> 
    jthread_local(FunctionType f)
    {
        std::promise<interrupt_flag*> p; 
        _thread = std::thread([f,&p]{
            p.set_value(&this_thread_flag);
            f();
        });
        flag = p.get_future().get();
    }; 

    void interrupt()
    {
        flag->set();
    }
    ~jthread_local()
    {
        if(_thread.joinable())
            _thread.join();
    }
};

bool interruption_point()
{
    if(this_thread_flag.is_set())
        return true; 
    return false; 
}

//Thread task 
void do_something()
{
    int counter{0};
    while(counter<10)
    {
        if(interruption_point())
        {
            return;
        }
        std::this_thread::sleep_for(0.2s);
        std::cerr<<"This is interruptible thread: "<<counter++<<std::endl;
    }
}

int main()
{
    jthread_local t1(do_something);
    std::this_thread::sleep_for(1s);
    t1.interrupt(); 
    return 0; 
}
