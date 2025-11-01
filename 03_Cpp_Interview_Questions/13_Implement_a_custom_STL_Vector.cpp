#include<iostream>
using namespace std; 

template <typename T>

class Vector 
{
private:    
    T *data; //Pointer to the dynamically allocated array 
    size_t sz; //Current number of elements 
    size_t cap; //Total allocated capacity 

    //Internal function to resize the capacity of an array 
    void resize_capacity(size_t new_cap)
    {
        T* new_data = new T[new_cap];

        //Copy the old elements to the memory 
        for(size_t i = 0;i<sz;i++)
        {
            new_data[i] = data[i];
        }
        //delete the old memory 
        delete[] data; 

        //Point data to the new memory 
        data = new_data; 
        cap = new_cap;
    }
public:
    //Constructor :Initialized empty vector 
    Vector() : data(nullptr),sz(0),cap(0) {}; 

    //Destructor : Releases the allocated memory 
    ~Vector()
    {
        delete[] data; 
    }

    //Add an element at the end of vector 
    void push_back(const T& value)
    {
        //If no space left ,resize the entire vector 
        if(sz == cap)
        {
            size_t new_cap = (cap==0)?1:2*cap;//If cap is zero,make it 1 else 2 the current capacity
            resize_capacity(new_cap);
        }
        //Store the new element and increase the size
        data[sz++] = value;
    }

    // pop_back element from the vector 
    void pop_back()
    {
        if(sz>0)
            sz--; 
        data[sz].~T();
    }

    //Access element at a given index (non-constant version)
    T& operator[](size_t index)
    {
        return data[index];
    }

    //returns number of elements store 
    size_t size() const 
    {
        return sz;
    }

    //returns the total allocated capacity 
    size_t  capacity() const 
    {
        return cap;
    }

    //checks if vector is empty 
    size_t empty() const 
    {
        return sz == 0;
    }
    void display()
    {
        for(int i=0;i<sz;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};

int main(void)
{
    Vector<int> v; //Create a vector of integers 

    v.push_back(10); //Add elements 
    v.push_back(20); //Add elements 
    v.push_back(30); //Add elements 
    v.push_back(40); //Add elements 
    cout<<"Vector elements: ";
    v.display();
    //Print size and capacity 
    cout<<"\n Size: "<<v.size()<<", capacity : "<<v.capacity()<<endl;

    v.pop_back(); 

    //Print after pop 
    cout<<"After pop_back(),size "<<v.size()<<endl;
    cout<<"Vector elements ";
    v.display();
    return 0;

}