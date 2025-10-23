#include<iostream>
using namespace std; 

class Node 
{
public:
    int data; 
    Node *next;
};

class LinkedList 
{
public:
    Node *first,*second,*res = nullptr;

    //Non parameterized constructor 
    LinkedList(){first = NULL;}
    //Parameterized constructor 
    LinkedList(int A[],int n);
    //Destructor
    ~LinkedList();

    void create(int A[],int n); 
    void Display(Node *p);
    void Display_res();
    void Insert(int index,int x);
    int  Delete(int index);
    int  Length();
    int  findMidNode();
    void InsertMidNode(int x);
    void reverse();
    bool is_sorted(); 
    void Merge(Node *p,Node *q);
};

//Parameterized constructor 
LinkedList::LinkedList(int A[],int n)
{
    Node *last,*tmp = nullptr;

    //create first node 
    first = new Node{A[0],nullptr};
    last  = first;
    
    //Traverse through the array and link the elements to the ll 
    for(int i=1;i<n;i++)
    {
        tmp = new Node{A[i],nullptr}; 
        //link to the ll 
        last->next = tmp; 
        last = tmp;
    }
}
void LinkedList::create(int A[],int n)
{
        Node *last,*tmp = nullptr;

    //create first node of ll2
    second = new Node{A[0],nullptr};
    last  = second;
    
    //Traverse through the array and link the elements to the ll 
    for(int i=1;i<n;i++)
    {
        tmp = new Node{A[i],nullptr}; 
        //link to the ll 
        last->next = tmp; 
        last = tmp;
    }
}
LinkedList::~LinkedList()
{
    Node *tmp; 
    Node *p = first; 
    while(p)
    {
        tmp = p; 
        p = p->next; 
        delete tmp;
    }
    p = nullptr;
}
int LinkedList::Length()
{
    Node *p = first; 
    int len =0; 
    while(p)
    {
        len++; 
        p = p->next;
    }
    return len;
}
void LinkedList::Display(Node *p)
{
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
void LinkedList::Insert(int index,int x)
{
    Node *tmp,*last = nullptr;
    
    tmp = new Node{x,nullptr}; 
    if(index == 0)
    {
        if(!first)
            first = tmp; 
        else 
        {
            tmp->next = first; 
            first   = tmp; 
        }
    }
    else 
    {
        Node *p = first; 
        //Traverse through ll to reach index-1 node 
        for(int i=0;i<index-1;i++)
        {
            p = p->next ;
        }
        tmp->next = p->next; //link tmp node to the nth node 
        p->next   = tmp; 
        last = tmp;
    }
}
int LinkedList::Delete(int index)
{
    int x = -1; 
    Node *tmp = nullptr; 

    if(index == 0)
    {
        if(!first)
        {
            cout<<"Cannot delete from empty linked list "<<endl;
            return -1;
        }
        else 
        {
            tmp = first; 
            first = first->next; 
            x = tmp->data; 
            delete tmp;
            return x;
        }
    }
    else 
    {
        Node *p = first; 
        Node *q; 
        for(int i =0;i<index;i++)
        {
            q = p;
            p = p->next; 
        }
        tmp = p; 
        //delink the nth node 
        q->next = p->next; 
        x = tmp->data; 
        delete tmp; 
        return x;
    }
}
void LinkedList::reverse()
{
    Node *p = first; 
    Node *q = nullptr;
    Node *r = nullptr; 
    while(p)
    {
        r = q; // r follows q 
        q = p; //q follows p 
        p = p->next; //advance p 
        q->next = r; //reverse links
    }
    first = q;
}
int LinkedList::findMidNode()
{
    Node *p = first ; 
    Node *q = p; 
    int midNode =0;
    while(q)
    {
        q = q->next;
        if(q)
            q = q->next;
        if(q)
        {
            p = p->next;
            midNode++;
        }
    }
    return midNode;
}
void LinkedList::InsertMidNode(int value)
{
    int midNode = findMidNode(); 
    Insert(midNode,value);
}

bool LinkedList::is_sorted()
{
    Node *p = first ; 

    while(p->next)
    {
        if(p->data >p->next->data)
            return false;
        p = p->next;
    }
    return true;
}
void LinkedList::Merge(Node *p,Node *q)
{
    p = first; 
    q = second; 
    Node *last = nullptr;
    //Link the first node to the resultant linkedlist 
    if(p->data < q->data)
    {
        res = last = first;
        p = p->next;
    }
    else 
    {
        res =  last = q;
        q = q->next;
    }
    
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next = p; 
            last = p;
            p = p->next;
        }
        else 
        {
            last->next = q; 
            last = q;
            q = q->next;
        }
    }

    if(p)
        last->next = p;
    if(q)
        last->next = q;
    
}
int main()
{
    int A[5] = {1,3,5,7,9};
    int B[5] = {0,2,4,6,8};
    LinkedList ll(A,5); 
    ll.Display(ll.first);
    ll.create(B,5);
    ll.Display(ll.second);
    ll.Merge(ll.first,ll.second);
    ll.Display(ll.res);
    
    return 0;
}