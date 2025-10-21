#include<iostream>
using namespace std; 

class Node 
{
public:
    Node *prev = nullptr; 
    int data; 
    Node *next = nullptr;
}; 

class DoublyLinkedList 
{
private:
    Node *first;
public:
     DoublyLinkedList() : first{nullptr} {}; 
     //Parameterized constructor 
     DoublyLinkedList(int A[],int n)
     {
        Node *tmp,*last;
        //Create the first node 
        first = new Node{nullptr,A[0],nullptr}; 
        last = first; 
        for(int i=1;i<n;i++)
        {
            tmp = new Node{nullptr,A[i],nullptr}; 
            //link the tmp node to the ll 
            last->next = tmp; 
            //link the linkedlist to the tmp 
            tmp->prev  = last; 
            last = tmp;
        }
     }
     void Display()
     {
        Node *p = first; 
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
     void Display_rev()
     {
        Node *p = first; 
        //traverse to reach the last node 
        while(p->next)
            p = p->next; 
        while(p)
        {
            if(p->prev)
                cout<<p->data<<"->";
            else 
                cout<<p->data;
            p = p->prev;
        }
        cout<<endl;
     }
     void Insert(int index,int value)
     {
        Node *tmp = new Node {nullptr,value,nullptr};  
        //Insert at the beginning 
        if(index == 0)
        {
            if(!first)
                first = tmp; 
            else 
            {
                tmp->next = first ; 
                first->prev = tmp;
                first = tmp;
            }    
        }
        else 
        {
            Node *p = first; 
            //Traverse to reach index-1 node 
            for(int i=0;i<index-1;i++)
            {
                p = p->next;
            }
            tmp->next = p->next; 
            p->next->prev   = tmp; 
            p->next   = tmp;
            tmp->prev = p;
        }
     }
     int Delete(int index)
     {
        Node *tmp = nullptr; 
        int x = -1; 

        //delete from head 
        if(index == 0)
        {
            if(!first)
            {
                cout<<"DLL is empty "<<endl;
                return -1;
            }
            else 
            {
                tmp = first; 
                first = first->next; 
                first->prev = nullptr;
                x = tmp->data;
                delete tmp; 
                return x;
            }
        }
        else 
        {
            Node *q,*p; 
            p = first; 
            //traverse to reach the index node 
            for(int i=0;i<index;i++)
            {
                q = p ; 
                p = p->next; 
            }
            tmp = p;
            q->next = p->next; 
            p->next->prev = q;
            x = tmp->data; 
            return x;
        }
    }
    void reverse()
    {
        Node *p = first; 
        Node *tmp; 

        while(p)
        {
            tmp = p->next; 
            //reverse link 
            p->next = p->prev; 
            p->prev = tmp; 
            if(!tmp)//reach end of ll
                first = p;
            p = tmp;
        }
    }
};

int main()
{
    int A[5] = {1,4,5,6,8}; 
    DoublyLinkedList dll(A,5); 
    dll.Display();
    dll.reverse();
    dll.Display();
    return 0;
}