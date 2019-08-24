#include"Stack.h"
#include <iostream>
using namespace std;

int main()
{
    Node<> *node1 = new Node<>;
    node1->data = 10;

    Node<> *node2 = new Node<>;
    node2->data = 20;

    Node<> *node3 = new Node<>;
    node3->data = 30;

    Node<> *node4 = new Node<>;
    node4->data = 40;

    Stack<Node<>*> *st = new Stack<Node<>*>;
    
    st->push(node1);
    st->push(node2);
    st->push(node3);
    st->push(node4);

    st->Display();

    while(!st->isEmpty())
        cout<<st->pop()->data<<" ";
    cout<<endl;


}