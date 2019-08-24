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

template <class T>
class Stack
{
private:
    T *st;
    int size;
    int top;
public:
    Stack(){size = 10; top = -1; st = new T[size];};
    Stack(int size){this->size = size; top = -1; st = new T[this -> size];};

    void push(T x);
    T pop();
    T peek(int index);
    T stacktop();
    int isEmpty();
    int isFull();
    void Display();
};

template<class T>

void Stack<T>::push(T x)
{
    if(isFull())
        cout<<"Stack overflow"<<endl;
    else
    {
        top ++;
        st[top] = x;
    }
};

template<class T>
T Stack<T>::pop()
{
    if(isEmpty())
    {
        cout<<"Stack underflow"<<endl;
        //return new T;
    }
    else
    {
        T x = st[top--];
        return x;
    }
};

template<class T>
T Stack<T>::peek(int index)
{
    if(top - index + 1 < 0 )
    {
        cout<<"Invalid Index"<<endl;
        //return new T;
    }
    else
        return st[top - index + 1];
};

template<class T>
T Stack<T>::stacktop()
{
    if(isEmpty())
        return 0;
    return st[top];
};

template<class T>
int Stack<T>::isFull()
{
    return top == size - 1;
};

template<class T>
int Stack<T>::isEmpty()
{
    return top == -1;
};

template<class T>
void Stack<T>::Display()
{
    for(int i = top; i >= 0 ; i --)cout<<st[i]<<" ";
    cout<<endl;
};






