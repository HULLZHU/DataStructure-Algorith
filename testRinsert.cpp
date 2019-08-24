#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
};

Node* insert(Node *p, int v)
{
    if(p)
    {   
        p->next = insert(p->next,v);
        return p;
    }
    else
    {
        Node *r = new Node;
        r->data = v;
        return r;
    }
};

void display(Node *p)
{
    if(p)
    {
        cout<<p->data<<", ";
        display(p->next);
    };
}

int main()
{
    Node *p1 = new Node;
    p1->data=10;
    insert(p1,12);
    insert(p1,13);
    insert(p1,14);
    insert(p1,15);
    display(p1);
}