#include<iostream>
using namespace std; 

class RingBuffer
{
private:
    int size; 
    int *Q; 
    int front; 
    int rear; 
public:
    //constructor 
    RingBuffer(int size)
    {
        this->size = size; 
        Q = new int[this->size]; 
        front = rear = 0;
    }

    //check if buffer is empty 
    bool isEmpty()
    {
        return front == rear;
    }

    //check if buffer is full
    bool isFull()
    {
        return (rear+1)%size == front;
    }

    void enqueue(int x)
    {
        Q[rear] = x; 
        rear = (rear+1)%size;
    }

    int dequeue()
    {
        int x = -1; 
        if(isEmpty())
            cout<<"Queue underflow"<<endl;
        else 
        {
            x = front; 
            front = (front+1)%size;
        }
        return x;
    }

    void display()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return; 
        }
        int i = front; 
        while(i != rear)
        {
            cout<<Q[i]<<flush; 
            if((i+1)%size != rear)
                cout<<"<-"<<flush; 
            i = (i+1)%size;
        }
        cout<<endl;
    }
    ~RingBuffer()
    {
        delete[] Q;
    }
};
// Driver code
int main()
{
    int A[] = {1, 3, 5, 7, 9};
    RingBuffer cq(sizeof(A) / sizeof(A[0]) + 1); // +1 for reserved slot

    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
        cq.enqueue(A[i]);

    cq.display();

    cq.enqueue(10); // Overflow test

    while (!cq.isEmpty())
        cout << cq.dequeue() << " ";
    cout << endl;

    cq.dequeue(); // Underflow test

    return 0;
}