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
    Stack(){top =NULL;}
    void push(int x);
    int pop();
    friend ostream& operator<<(ostream & os, const Stack st);
};

void Stack::push(int x)
{
    Node *t = new Node;
    if( t == NULL)
        cout<<"Stack Overflow "<<endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }   
}

int Stack::pop()
{
    if(!top)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    else
    {
        Node *t = top;
        int x = t -> data;
        top = top -> next;
        delete t;
        return x;
    }   
}

ostream& operator<<(ostream & os, const Stack st)
{
    Node *p = st.top;
    while(p)
    {
        cout<<p->data<<", ";
        p = p->next;
    }
    os<<endl;
    return os;
}

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st;
}