#include<iostream>
using namespace std; 
class Node 
{
public:
    int data; 
    Node *next;
}; 

class Queue
{
private:    
    Node *front = nullptr; 
    Node *rear = nullptr;
public:
    //insert from the rear
    void enqueue(int value)
    {
        Node *tmp = new Node{value,nullptr}; 
        if(rear == nullptr)
        {
            front = rear = tmp;
        }
        else 
        {
            rear->next = tmp; 
            rear       = tmp;
        }
    }
    int dequeue()
    {
        int x = 0xFF; 
        Node *tmp = nullptr; 
        if(!front)
        {
            cout<<"queue is empty "<<endl;
            return -1;
        }
        else 
        {
            tmp = front; 
            front = front->next; 
            x = tmp->data; 
            delete tmp;
            return x; 
        }
        if(front == nullptr)
            rear == nullptr;
    }

    void Display()
    {
        Node *p = front; 
        while(p)
        {
            if(p->next)
                cout<<p->data<<"->"; 
            else 
                cout<<p->data;
            p = p->next;
        }
        cout<<endl;
    }
    
};

int main()
{
    int A[5] = {1,2,3,4,5}; 
    Queue q; 
    for(int i = 0;i<5;i++)
        q.enqueue(A[i]); 

    q.Display(); 
    return 0;
}