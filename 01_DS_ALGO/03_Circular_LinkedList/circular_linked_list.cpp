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
    Node *head; 
public:
    CircularLinkedList() : head{nullptr} {}; 
    //Parameterized constructor 
    CircularLinkedList(int A[],int n)
    {
        //Create Head node 
        head = new Node{A[0],nullptr}; 
        //Create circular link 
        head->next = head;
        Node *last = head; 
        for(int i=1;i<=n;i++)
        {
            Node *tmp = new Node{A[i],nullptr}; 
            tmp->next = head; 
            last->next = tmp; 
            last = tmp;
        }
    }
    void Display()
    {
        Node *p = head; 
        while(p && p->next != head)
        {

            cout<<p->data<<"->"; 
            p = p->next;
        }
        cout<<endl;
    }

    void Insert(int index,int value)
    {
        Node *tmp = new Node{value,nullptr}; 
        //Insert at the beginning 
        if(index == 0)
        {
            if(!head)
            {
                head = tmp; 
                head->next = head;
            }
            else 
            {
                Node *p = head; 
                //traverse to reach the last node
                while(p->next != head)
                {
                    p = p->next;
                }
                tmp->next = head; 
                p->next = tmp; 
                head = tmp;
            }
        }
        else 
        {
            Node *p = head; 
            for(int i =0;i<index-1;i++ )
            {
                p = p->next; 
            }
            tmp->next = p->next; 
            p->next = tmp;
        }
    }
    int Delete(int index)
    {
        Node *tmp = nullptr; 
        int x = -1; 
        if(index == 0)
        {
            if(!head)
            {
                cout<<"Circular linked list is empty!"<<endl;
                return -1;
            }
            else 
            {
                Node *p = head; 
                //traverse to reach end of cll
                while(p->next != head)
                    p = p->next; 
                tmp = head; 
                p->next = head->next; 
                x = tmp->data; 
                head = head->next;
                delete tmp; 
                return x; 
            }
        }
        else 
        {
            Node *p = head; 
            Node *q = nullptr;
            for(int i=0;i<index;i++)
            {
                q = p; 
                p = p->next; 
            }
            tmp = p; 
            q->next = p->next; 
            x = tmp->data; 
            delete tmp; 
            return x;
        }
    }
}; 

int main()
{
    int A[5] = {1,2,3,4,5}; 
    CircularLinkedList cll(A,5); 
    cll.Display();
    cll.Delete(2); 
    cll.Display();

    return 0;
}