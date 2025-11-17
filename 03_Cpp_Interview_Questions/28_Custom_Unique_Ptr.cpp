#include<iostream>
using namespace std;
template<typename T> 

class UniquePtr 
{
private:
    T* ptr;
public:
    //Default constructor 
    UniquePtr() : ptr(nullptr) {}; 

    //Parameterized constructor 
    UniquePtr(T* p)
    {
        ptr = p;
    }

    //Delete copy constructor 
    UniquePtr(const UniquePtr&) = delete; 
    //Delete copy assignment 
    UniquePtr& operator=(const UniquePtr&) = delete;

    //Move constructor 
    UniquePtr(UniquePtr&& other)
    {
        ptr = other.ptr; 
        other.ptr = nullptr; //Release ownership
    }
    //Move Assignment operator 
    UniquePtr& operator=(UniquePtr&& other)
    {
        if(this != other)
        {
            delete ptr; //delete currently owned pointer 
            ptr = other.ptr;//take ownership
            other.ptr = nullptr;// clear source 
        }
        return *this;
    }

    //Destructor 
    ~UniquePtr()
    {
        delete ptr;
    }
    /*---------------------Utility Functions---------------------------------  */
    T* get() const 
    {
        return ptr; 
    }

    //release ownership 
    T* release()
    {
        T* temp = ptr; 
        delete ptr; 
        return temp;
    }

    //Reset with new pointer 
    void reset(T* p)
    {
        delete ptr; 
        ptr = p;
    }

    T& operator*()const{ return *ptr;};
    T* operator->()const{ return ptr;}; 
};

class Base 
{
public:
    Base() = default;
    void hello() {cout<<"Hi from base class"<<endl;}
};

int main(void)
{
    UniquePtr<Base> p1(new Base()); 
    p1->hello(); 

    UniquePtr<Base> p2 = std::move(p1); 

    p2->hello();

    return 0;

}