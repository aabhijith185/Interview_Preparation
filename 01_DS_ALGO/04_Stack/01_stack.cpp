#include<iostream>
using namespace std;

class Node 
{
public:
    int data; 
    Node *next;
}; 

class Stack 
{
private:
    Node *top; 
public: 
    Stack() : top(nullptr) {}; 

    void push(int value)
    {
        Node *tmp = new Node {value,nullptr}; 
        tmp->next = top;
        top = tmp;
    }
    int pop()
    {
        int x = 0xFF;
        Node *tmp;
        if(!top)
            cout<<"Empty Stack"<<endl;
        x = top->data; 
        tmp = top;
        top = top->next;
        delete tmp; 
        return x;
    }
    int peek(int index)
    {
        Node *p = top; 
        //Traverse to reach the index
        for(int i=0;p && i<index;i++)
            p = p->next; 
        if(p)
            return p->data; 
        else 
            return -1;
    }
    void display()
    {
        Node *p = top; 
        while(p)
        {
            cout<<p->data<<"->"; 
            p = p->next;
        }
        cout<<endl;
    }
    int isEmpty()
    {
        return top?0:1;
    }
    
    ~Stack()
    {
        Node *p = top; 
        while(top)
        {
            top = top->next; 
            delete p; 
            p = top;
        }
    }

};

int main(void)
{
    int A[5] = {1,2,3,4,5}; 
    Stack stk; 
    for(int i=0;i<5;i++)
    {
        stk.push(A[i]);
    }
    stk.display();
    cout<<"Element at index 2: "<<stk.peek(2)<<endl;
    
    for(int i=0;i<5;i++)
        stk.pop();
        
    if(stk.isEmpty())
        cout<<"stack is empty"<<endl;
    else 
        cout<<"Stack is not empty "<<endl;
        

    return 0;
}