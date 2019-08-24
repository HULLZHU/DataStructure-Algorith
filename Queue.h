#ifndef QUEUE_H_
#define QUEUE_H_

#include<iostream>
using namespace std;

#ifndef NODE
#define NODE
template<class T = int>
class Node
{
public:
    /*Public data field*/
    Node<T> *lchild;
    T data;
    Node<T> *rchild;
    /*Constructor*/
    Node(){lchild = NULL; rchild = NULL;};
    Node(T _data_){data = _data_;lchild = NULL; rchild = NULL;};
    /*output override*/
};
#endif

/*This queue is based on array*/
/*For saving space, we use circular queue*/
template<class T = int>
class Queue
{
private:
    int front;
    int rear;
    int size;
    int capacity;
    T *queue;
    void initialize(){front = -1; rear = -1;size = 0;};
public:
    /*Constructor*/
    Queue(){capacity = 10;queue = new T[capacity];initialize();};
    Queue(int _capacity_){capacity = _capacity_;queue = new T[capacity];initialize();};
    /*getter*/
    int getSize(){return this->size;}
    int getCapacity(){return this->capacity;};
    T* toArray();
    /*ADT*/
    void enqueue(T ele);
    T dequeue();
    int isEmpty(){return size == 0;};
    int isFull(){return size == capacity-1;};
};

 template<class T>
 T* Queue<T>::toArray()
 {
     T *arr = new int[this->capacity];
     for(int i = 0 ; i < capacity ; i ++ )arr[i] = -1;

     int i =front + 1;
    do
    {
        if(queue[i])
        {
            arr[i]=queue[i];
            i = (i+1)%capacity;
        }
    } while ( i != (rear+1)%capacity );
    return arr;
 }

 template<class T >
 void Queue<T>::enqueue(T ele)
 {
     if(!this->isFull())
     {
        rear = (rear+1)%capacity;
        queue[rear] = ele;
        size ++;
     }
     else
        cout<<"Full Queue\n";
 };

 template<class T>
 T Queue<T>::dequeue()
 {
    T x;
    if(isEmpty())
    {
        cout<<"Empty Stack"<<endl;
    }
    else
    {   
        front = (front+1)%capacity;
        x = queue[front];
        size --;
    }
    return x;
 }


#endif