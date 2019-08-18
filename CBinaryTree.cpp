#include<iostream>
using namespace std;
struct Node* root = NULL;
/*Create a Queue data structure first for binary tree*/

struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    Node **Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q -> front = q -> rear = 0;
    q -> Q = (struct Node**)malloc(q->size*sizeof(struct Node *));
}

void enqueue(Queue *q, struct Node *x)
{
    if((q->rear + 1)%q->size == q -> front)
        cout<<"Full queue"<<endl;
    else
    {
        q->rear = (q->rear + 1)%q->size;
        q->Q[q->rear]=x;
    }
}

struct Node* dequeue(struct Queue* q)
{
    Node * x = NULL;
    if(q->front == q->rear)
        cout<<"The queue is empty"<<endl;
    else
    {
        q->front = (q->front + 1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(Queue q)
{
    return q.front == q.rear;
}

void Treecreate()
{
    Node *p, *t;
    int x;
    Queue q;
    create(&q,100);//create a queue of tree nodes, size = 100

    cout<<"Enter the root value";
    cin>>x;
    root = (struct Node*)malloc(sizeof(struct Node));
    root ->data =x;
    root ->lchild = root->rchild = NULL;
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        p = dequeue(&q);
        cout<<"Enter the left node value of "<<p->data;
        cin>>x;
        if(x!=-1)//IF x = -1, THEN input is invalid
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t ->data = x;
            t -> lchild = t -> rchild = NULL;
            p -> lchild = t;
            enqueue(&q,t);
        }

        cout<<"Enter the right node value of "<<p->data;
        cin >> x;
        if(x!=-1)
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t -> data = x;
            t -> lchild = t->rchild = NULL;
            p ->rchild = t;
            enqueue(&q,t);
        }
    }
}

void preorder(Node *p)
{
    if(p)
    {
        cout<<p->data<<", ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<", ";
        inorder(p->rchild);
    }
}

void postorder(Node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<", ";
    }
}

int main()
{
    Treecreate();
    preorder(root);

    return 0;
}