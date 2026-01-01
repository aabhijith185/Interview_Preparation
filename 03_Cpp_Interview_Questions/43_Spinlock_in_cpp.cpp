#include<iostream> 
#include<thread> 
#include<vector> 
#include<atomic> 

using namespace std;
class Spinlock 
{ 
private:    
    //std::atomic_flag is lock_free and provides essential test-and-set functionality required for spinlock 
    std::atomic_flag flag = ATOMIC_FLAG_INIT; 
public:
    //Lock the spinlock 
    void lock()
    {
        /*test_and_set() atomically checks the flag's previous value and sets it to true */
        /*If it returns true (the lock was already set/held),it means we failed to acquire the lock ,so we spin and try again */
        while(flag.test_and_set(std::memory_order_acquire));
        //std::memory_order_acquire ensures read/write AFTER the locks are not recieved 
    }
    //Unlock the spinlock 
    void unlock()
    {
        //clear() atomically sets the flag to false ,releasing the lock 
        flag.clear(std::memory_order_release); 
        //std::memory_order_release ensures reads/writes BEFORE the unlock are not reordered AFTER it 
    }
}; 
//Shared data and worker functions 
volatile int shared_counter =0; 

//The spinlock instance 
Spinlock my_spinlock; 

//Function run by multiple threads 
void worker_function(int iterations)
{
    for(int i=0;i<iterations;i++)
    {
        //Acquire the lock (start of critical section )
        my_spinlock.lock(); 

        //--CRITICAL SECTION--
        shared_counter++; 

        my_spinlock.unlock();
    }
}

// Main program execution 
int main() 
{
     const int num_threads = 4; 
     const int iteration_per_thread = 100000;

     const int expected_val = num_threads*iteration_per_thread;

     std::vector<std::thread> threads; 

     for(int i=0;i<num_threads;++i)
     {
        threads.emplace_back(worker_function,iteration_per_thread);
     }

     //Wait for all threads to finicsh 
     for(auto &t : threads)
        t.join(); 
    
    cout<<"Thread finished. Final counter value: "<<shared_counter<<endl;
    cout<<"Expected value: "<<expected_val<<endl; 

    if(shared_counter == expected_val)
    {
        cout<<"Result is correct(Synchronization worked )"<<endl;
    }
    else 
    { 
        cout<<"Result is Incorrect(Synchronization Failed)"<<endl;
    }
    
    return 0;
}
