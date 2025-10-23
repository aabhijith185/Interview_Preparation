#include<iostream>
using namespace std; 

class Queue
{
private:
    int front; 
    int rear; 
    int size; 
    int *Q;
public:
    //default constructor 
    Queue()
    {
        front = rear = -1; 
        size = 10; 
        Q = new int[size];
    }
    //parameterized constructor 
    Queue(int size)
    {
        front = rear = -1; 
        this->size = size; 
        Q = new int[this->size];
    }
    //Enqueue ; Insert from the rear
    void enqueue(int x)
    {
        if(rear == size-1)
            cout<<"Queue is full: "<<endl;
        rear++;
        Q[rear] = x; 
    }
    //dequeue ; remove from the front 
    int dequeue()
    {
        int x = 0xFF;
        if(front  == rear)
            cout<<"Queue is empty"<<endl;
        else 
        {
            x = Q[front+1]; 
            front++;
        }
        return x;
    }
    void display()
    {
        for(int i = front+1;i<=rear;i++)
            cout<<Q[i]<<" "; 
        cout<<endl;
    }
    
    int isEmpty()
    {
        return (rear == front)?1:0;
    }
};

int main(void)
{
    int A[5] = {1,2,3,4,5}; 

    Queue q(5); 
    for(int i=0;i<5;i++)
        q.enqueue(A[i]); 
    q.display(); 

    while(!q.isEmpty())
        q.dequeue(); 
    q.dequeue();

    return 0;
}