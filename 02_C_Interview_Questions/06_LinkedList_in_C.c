#include<stdio.h> 
#include<stdlib.h> 

typedef struct Node 
{
    int data; 
    struct Node * next;
}Node; 

Node *first = NULL; 
Node *second = NULL; 
Node *res    = NULL; 

void create(int A[],int n)
{
    Node *last,*tmp;
    //create the first Node 
    first = (Node*)malloc(sizeof(Node)); 
    first->data = A[0]; 
    first->next = NULL; 
    //tracking pointer to the first Node 
    last = first ; 

    //link the rest of the nodes 
    for(int i=1;i<n;i++)
    {
        tmp = (Node*)malloc(sizeof(Node)); 
        tmp->data = A[i];
        tmp->next = NULL; 

        last->next = tmp; 
        last       = tmp;
    }
}

void create_2(int A[],int n)
{
    Node *last,*tmp;
    //create the first Node 
    second = (Node*)malloc(sizeof(Node)); 
    second->data = A[0]; 
    second->next = NULL; 
    //tracking pointer to the first Node 
    last = second ; 

    //link the rest of the nodes 
    for(int i=1;i<n;i++)
    {
        tmp = (Node*)malloc(sizeof(Node)); 
        tmp->data = A[i];
        tmp->next = NULL; 

        last->next = tmp; 
        last       = tmp;
    }
}

void insert(Node *p,int index,int value)
{
    //Create a temp node 
    Node *tmp = (Node*)malloc(sizeof(Node)); 
    tmp->data = value; 
    tmp->next = NULL; 

    //Insert at the beginning 
    if(index == 0)
    {
        tmp->next = first; 
        first = tmp; 
    }
    else 
    {
        p = first;
        //traverse to reach the index-1 node 
        for(int i=0;i<index-1;i++)
            p = p->next; 
        //link the tmp node to the nth node 
        tmp->next = p->next; 
        p->next = tmp;
    }
}

int delete(Node *p,int index)
{
    int x = -1; 
    Node *tmp; 

    if(index == 0)
    {
        tmp = first; 
        //move the first node 
        first = first->next; 
        x = tmp->data; 
        free(tmp);
        return x;
    }
    else 
    {
        p = first; 
        Node *q;
        //traverse to reach the index node 
        for(int i=0;i<index;i++)
        {
            q = p; 
            p = p->next; 
        }
        //delink the nth node 
        tmp = p; 
        q->next = p->next; 
        x = p->data;
        free(tmp); 
        return x;
    }
}

void reverse(Node *head)
{
    Node *p = head; 
    Node *q = NULL; 
    Node *r = NULL;

    while(p)
    {
        r = q; //r follows q
        q = p; //q follows p
        p = p->next; 
        q->next = r;//reverse the link in each iteration 
    }
    first = q;
}

int findMidNode(Node *p)
{
    int mid = 0; 
    Node *q=p; 
    while(q)
    {
        q = q->next; 
        if(q)
            q = q->next; 
        if(q)
        {
            p = p->next; 
            mid++;
        }
    } 
    return mid;
}

void Insert_at_middle(Node *p,int value)
{
    int mid = findMidNode(p); 
    insert(p,mid,value);
}

void merge(Node *p,Node *q)
{
    Node *last; 
    //link the first node 
    if(p->data < q->data)
    {
        res = last = p; 
        p = p->next;
    }
    else 
    {
        res = last = q; 
        q   = q->next;
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
            last   = q; 
            q = q->next;
        }
    }
    //link the leftover nodes 
    if(p) last->next = p; 
    if(q) last->next = q;
}
void display(Node *p)
{
    while(p)
    {
        if(p->next)
            printf("%d->",p->data); 
        else 
            printf("%d",p->data); 
        p = p->next;
    }
    printf("\n");
}

int main(void)
{
    int A[5] = {1,3,5,7,9}; 
    int B[5] = {2,4,6,8,10};
    create(A,5); 
    // insert(first,3,-1);
    // display(first); 
    // delete(first,3);
    // Insert_at_middle(first,0);
    // display(first);
    create_2(B,5); 
    // display(second);
    merge(first,second);
    display(res);

    return 0;
}