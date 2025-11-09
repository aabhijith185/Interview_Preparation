#include<iostream>
#include<vector>
#include<mutex>
#include<memory> 
#include<thread> 
#include<chrono> 

//Observed Interface 
class Observer
{
public:
    virtual void update(int value) = 0; 
    virtual ~Observer() = default;
};

class Subject 
{
private:
    std::vector<std::shared_ptr<Observer>> observers; 
    std::mutex mtx; 
    int state; 
public:
    void attach(std::shared_ptr<Observer> obs)
    {
        std::lock_guard<std::mutex> lock(mtx);
        observers.push_back(obs);
    }

    void setState(int val)
    {
        {
            std::lock_guard<std::mutex> lock(mtx); 
            state = val;
        }
        notifyAll();
    }

    void notifyAll()
    {
        std::lock_guard<std::mutex> lock(mtx); 
        for(auto &obs : observers)
        {
            if(obs)
                obs->update(state);
        }
    }
};

class ConcreteObserver : public Observer
{
private:
    std::string name; 
public:
    ConcreteObserver(const std::string &id) :name(id) {};
    void update(int value)override
    {
        std::cout<<name<<" recieved update: "<<value<<"\n";
    }
};
//-------------------------------Thread Worker Functions----------------------------------------------
void sensorTask(std::shared_ptr<Subject> subj)
{
    int value = 0;
    while(value<10)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        subj->setState(++value);
    }
}

void observedAttachTasks(std::shared_ptr<Subject> subj)
{
    int count = 1; 
    while(count <= 5)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(900));
        subj->attach(std::make_shared<ConcreteObserver>("Observer "+ std::to_string(count++)));
    }
}
int main()
{
    auto subj = std::make_shared<Subject>();

    std::thread sensorThread(sensorTask,subj);
    std::thread observerThread(observedAttachTasks,subj);

    sensorThread.join(); 
    observerThread.join(); 

    return 0;
}