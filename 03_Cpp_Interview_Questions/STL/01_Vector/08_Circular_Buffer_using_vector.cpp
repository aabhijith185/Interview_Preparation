#include<iostream> 
#include<vector> 

using namespace std; 

class CircularBuffer
{
private:    
    vector<int> buff; 
    int front; 
    int rear;
    int size;
public:
    CircularBuffer(size_t sz):buff(sz),front(0),rear(0),size(0) {};

    bool isFull() const 
    {
        return size == buff.size();
    }

    bool isEmpty() const 
    {
        return front == rear;
    }
    
    //write data into buffer 
    bool write(int value)
    {
        if(isFull()) 
        {
            cout<<"Buffer is full ,cannot write "<<endl;
            return false;
        }
        buff[rear] = value; 
        rear = (rear+1)%buff.size();
        size++;
        return true;
    }
    //read data from the buffer 
    bool read(int &value)
    {
        if(isEmpty())
        {
            cout<<"Empty buffer"<<endl;
            return false;
        }
        value = buff[front];
        front =(front+1)%buff.size();
        size--;
        return true;
    }

    //print buffer content from front to rear 
    void printBuffer()const 
    {
        int idx = front; 
        for(int i=0;i<size;i++)
        {
            cout<<buff[idx]<<" ";
            idx = (idx+1)%buff.size();
        }
        cout<<endl;
    }
};

int main()
{
    //Circular buffer of size 3
    CircularBuffer cb(3); 

    //write some values 
    cb.write(10);
    cb.write(20);
    cb.write(30);
    
    cb.printBuffer(); //output 10 20 30

    //Try writing when full 
    cb.write(40);

    int val; 

    //Read one value 
    cb.read(val);
    cb.read(val);
    cb.read(val);

    cb.printBuffer();

    //Try reading when empty 
    cb.read(val);
    
    return 0;
}