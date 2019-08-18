#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
}*front = NULL, *rear = NULL;

void enqueue(int x)
{
    Node *t = new Node;
    if(t == NULL )
        cout<<"Queue is full\n";
    else
    {
        t -> data = x;
        t -> next = NULL;
        if(front == NULL)//If there is no element in the Queue
            front = rear = t;
        else//If there are other elements in the queue
        {
            rear -> next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    Node *t;//If the front is NULL, then the queue is empty
    if(front == NULL)cout<<"Empty Queue"<<endl;
    else
    {
        x = front -> data;
        t = front;//t is used to store the pointer of the front
        front = front -> next;
        delete t;
    }
    return x;
}

void Display()
{
    Node *p = front;
    while(p)
    {
        cout<<p -> data<<", ";
        p = p -> next;
    }
    cout<<"\n";
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    Display();
}
