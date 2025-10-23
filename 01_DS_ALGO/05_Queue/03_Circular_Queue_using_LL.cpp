#include<iostream>
using namespace std; 

class Node 
{
public:
    int data; 
    Node *next;
};

class CircularQueue
{
private:
    Node *front = nullptr; 
    Node *rear  = nullptr; 
public:
    void enqueue(int value)
    {
        Node *tmp = new Node{value,nullptr}; 
        if(!front)
        {
            front = rear = tmp; 
            rear->next = front;
        }
        else 
        {
            rear->next = tmp; 
            rear = tmp; 
            rear->next = front;
        }
    }
    void dequeue()
    {
        if(!front)
        {
            cout<<"Queue is empty "<<endl;
            return;
        }
        //Only one node
        if(front == rear)
        {
            delete front; 
            front = rear = nullptr;
        }
        else 
        {
            Node *tmp = front; 
            front = front->next;
            rear->next = front; 
            delete tmp;
        }
    }

    void Display()
    {
        if(!front)
        {
            cout<<"Queue is empty"<<endl;
            return ;
        }
        Node *p = front; 
        do 
        {
            cout<<p->data; 
            if(p->next != front)
                cout<<"->"; 
            p = p->next;
        }while(p!= front);
        cout<<endl;
    }

    ~CircularQueue()
    {
        while(front)
            dequeue();
    }
};

int main() {
    CircularQueue Q;
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);

    Q.Display();  // 10 -> 20 -> 30 -> 40
    Q.dequeue();  // removes 10
    Q.Display();  // 20 -> 30 -> 40

    return 0;
}
