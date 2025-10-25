#include<iostream>
using namespace std; 

class Node 
{
public:
    int data; 
    Node *next;
}; 

class CircularLinkedList 
{
private:
    Node *front = nullptr; 
    Node *rear  = nullptr; 
public:
    void enqueue(int value)
    {
        Node *tmp = new Node{value,nullptr}; 
        //If queue is empty
        if(!front)
        {
            front = rear = tmp; 
            //create circular link 
            rear->next = front;
        }
        else
        {
            rear->next = tmp; //link new node to the rear
            rear = tmp;//update rear pointer
            rear->next = front;
        }
    }

    int dequeue()
    {
        int x = 0xFF; 
        if(!front)
        {
            cout<<"Empty queue: "<<endl;
            return x;
        }
        else 
        {
            Node *tmp  = front; 
            //delink the front node 
            front = front->next;
            rear->next = front; //link rear end to the new front 
            x = tmp->data; 
            delete tmp;
            return x;
        }
    }

    void display()
    {
        Node *p = front; 
        do
        {
            if(p)
                cout<<p->data;
            if(p&&p->next != front)
                cout<<"->"; 
            p = p->next;
        }while(p!=front);
        cout<<endl;
    }
    ~CircularLinkedList()
    {
        if(!front)
            return; 
        //break circular link first ,else front will never be null
        rear->next = nullptr;
        Node *tmp;
        while(front)
        {  
            tmp = front;
            front = front->next;
            delete tmp; 
        }
    }
};

int main()
{
    int A[6] = {1,2,3,4,5,6}; 
    CircularLinkedList cll; 
    for(int i=0;i<6;i++)
        cll.enqueue(A[i]); 
    cll.display();
    cll.dequeue(); 
    cll.display();
    return 0;
}