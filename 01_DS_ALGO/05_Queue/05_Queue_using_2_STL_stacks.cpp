#include<iostream>
#include<stack>
using namespace std; 

class Queue
{
private:
    stack<int> e_stk;
    stack<int> d_stk; 
public:
    void enqueue(int x)
    {
        e_stk.push(x);
    }

    int dequeue()
    {
        if(d_stk.empty())
        {
            if(e_stk.empty())
            {
                cout<<"Empty stack "<<endl;
                return -1;
            }
            //pop out elements from empty stack and push into dequestack
            while(!e_stk.empty())
            {
                d_stk.push(e_stk.top());
                e_stk.pop();
            }
        }
        int x = d_stk.top(); 
        d_stk.pop(); 
        return x;
    }
    void display()
    {
        //push elements from e_stk to d_stk if d_stk is empty 
        if(d_stk.empty())
        {
            while(!e_stk.empty())
            {
                d_stk.push(e_stk.top()); 
                e_stk.pop();
            }
        }

        stack<int> tmp = d_stk; 
        while(!tmp.empty())
        {
            cout<<tmp.top()<<"->"; 
            tmp.pop();
        }
        cout<<endl;
    }
};

int main()
{
    int A[5] = {1,2,3,4,5}; 
    Queue q;
    for(int i=0;i<5;i++)
        q.enqueue(A[i]); 
    q.display();

    return 0;
}