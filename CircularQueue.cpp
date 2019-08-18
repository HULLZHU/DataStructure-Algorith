/*Circular Queue save more space, which can be used in system task management*/
#include<iostream>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q -> size = size;
    q -> front = q -> rear = 0;
    q -> Q = new int[size];
}

void enqueue(Queue *q, int x)
{
    //There must be one cell retained on purpose in circular queue implemented by array
    if( (q-> rear + 1) % q -> size == q-> front)
        cout<<"full queue"<<endl  ´Ó        ¡¤
    else
    {
        q -> rear = (q->rear + 1) % q -> size;
        q -> Q[q->rear] = x;
    }
}

int dequeue(Queue *q)
{
    int x = -1;
    if( q -> front == q -> rear)
        cout<<"Empty Queue\n";
    else
    {
        q -> front = (q->front + 1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    int i = q.front + 1;
    do
    {
        cout<<q.Q[i]<<", ";
         i = (i+1)%q.size;
    }
    while(i != (q.rear + 1) % q.size);
    cout<<endl;
}

int main()
{
    Queue q;
    create(&q, 5);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    enqueue(&q,60);

    Display(q);
    return 0;
}
