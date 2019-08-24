#include<iostream>
#include "Queue.h"
using namespace std;

int main()
{
    Node<char> node('A');
    cout<<node.data<<endl;

    Node<> node2;
    node2.data=3;
    cout<<node2.data<<endl;

    Node<double> node3(3.1313);
    cout<<node3.data<<endl;

    Queue<int> *queue = new Queue<int>();
    queue->enqueue(10);
    queue->enqueue(20);
    queue->enqueue(30);
    queue->enqueue(40);

    int *arr = queue->toArray();
    for(int i = 0 ; i < 10 ; i ++ )cout<<arr[i]<<", ";
    cout<<endl;
    cout<<"size(1) : "<<queue->getSize()<<endl;

    int x = queue->dequeue();
    cout<<"dequeue (1) "<<x<<endl;

    int *arr2 = queue->toArray();
    cout<<"size(2) : "<<queue->getSize()<<endl;
    for(int i = 0 ; i < queue->getCapacity(); i ++ )cout<<arr2[i]<<", ";

    queue->enqueue(50);
    queue->enqueue(60);
    queue->enqueue(70);
    queue->enqueue(80);
    queue->enqueue(90);
    queue->enqueue(100);
    queue->enqueue(10);

    int *arr3 = queue->toArray();
    cout<<"size(3) : "<<queue->getSize()<<endl;
    for(int i = 0 ; i < queue->getCapacity(); i ++ )cout<<arr3[i]<<", ";
    
    x = queue->dequeue();
    x = queue->dequeue();
    x = queue->dequeue();
    x = queue->dequeue();

    int *arr4 = queue->toArray();
    cout<<"size(4) : "<<queue->getSize()<<endl;
    for(int i = 0 ; i < queue->getCapacity(); i ++ )cout<<arr4[i]<<", ";

    queue->enqueue(10);
    queue->enqueue(20);
    queue->enqueue(30);
    queue->enqueue(40);

    int *arr5 = queue->toArray();
    cout<<"size(5) : "<<queue->getSize()<<endl;
    for(int i = 0 ; i < queue->getCapacity(); i ++ )cout<<arr5[i]<<", ";
}