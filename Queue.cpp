#include<iostream>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int size;
    int *Q;
public:
    Queue(){front = size = -1; size = 10; Q = new int[size];}
    Queue(int size){front = rear = -1; this -> size = size; Q = new int[size];}
    void enqueue(int x);
    int dequeue();
    friend ostream& operator<<(ostream &os, Queue queue);
};

void Queue::enqueue(int x)
{
    if(rear == size -1)
        cout<<("Queue Full\n");
    else
    {
        rear ++;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if(rear == front)
        cout<<"Empty Queue"<<endl;
    else
    {
        x = Q[front];
        front ++;
    }
    return x;
}

ostream& operator<<(ostream &os, Queue queue)
{
    for(int i = queue.front+1; i<= queue.rear; i++)
        os<<queue.Q[i]<<", "
        ;
    os<<endl;
    return os;
}

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout<<q<<endl;
    return 0;
}
