#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};

void display(Node *p)
{
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p ->next;
    }
}

Node* create(int A[], int n)
{
    Node *p = new Node;
    Node *start = p;
    p -> data = A[0];
    p -> next = NULL;
    for(int i = 1 ; i < n ; i ++ )
    {
        p->next = new Node;
        p = p->next;
        p->data = A[i];
    }
    p ->next = NULL; //Remember the last node should point to the NULL
    return start;
}

void Display(Node *p)
{
    if(p != NULL)
    {
        cout<< p ->data<<" ";
        Display(p->next);
    }
    
}

void Display2(Node *p)
{
    if(p != NULL)
    {
        Display2(p->next);
        cout<< p ->data<<" ";
    }
}

int count(Node *p)
{
    int c = 0;
    while( p!=NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

int count1(Node *p)
{
    if(p == NULL)
        return 0;
    return count1(p ->next)+1;
}

int Add(Node *p)
{
    int sum = 0;
    while( p != NULL)
    {
        sum += p->data;
        p = p ->next;
    }
}

int Add1(Node *p)
{
    if(p == NULL)
        return 0;
    return Add1(p->next)+p->data;
}

int max(Node *p)
{
    int m = -32768; //Minimal Integer
    while( p != NULL)
    {
        if( p-> data > m)
            m = p->data;
        p = p -> next;
    }
    return m;
}

int max1(Node *p)
{
    int x = 0;
    if(p == 0)
        return -32768;
    else
    {
        x = max1( p -> next);
        if(x > p->data)
            return x;
        else
            return p->data;
    }
}

Node* moveTohead(Node *start, int key)
{
    Node *front = start;
    Node *back = NULL;
    while( front != NULL )
    {
        if(front -> data == key)
        {
            back ->next = front->next;
            front ->next = start;
            start = front;
            return front;
        }
        back = front;
        front = front -> next;
    }
}

void Insert(struct Node*p, int index, int x)
{
    Node *first = p;
    Node *t;

    if(index <0 || index > count(first))
    {
        cout<<count(first)<<endl;
        cout<<"Invalid Index"<<endl;
        return;
    }
    t = new Node;
    t -> data = x;

    if(index == 0)
    {
        t ->next = first;
        first = t;
    }
    else
    {
        for(int i = 0 ; i < index-1; i++)
            first = first->next;
        t -> next = first ->next;
        first ->next = t;
    }
}

void push_end(struct Node*p, int x)
{
    Node *t = p;
    Node *t2 = new Node;
    t2 -> data = x;
    t2 -> next = NULL;

    while( t->next !=NULL)
        t = t ->next;
    t->next = t2;
}

Node* SortedInsert(Node *first, int x)
{
    Node *t, *q  = NULL;
    Node *p = first;
    t = new Node;
    t -> data = x;
    t -> next = NULL;

    std::cout<<"@(first__1)"<< first<<endl;

    if(first == NULL)
        first = t;
    else
    {
        while(p && p->data < x)
        {
            cout<<"Block 1"<<endl;
            q = p;
            p = p ->next;
        }
        std::cout<<"@(first__2)"<< first<<endl;
        std::cout<<"@(p__1)"<< p <<endl;
        if( first == p)
        {
            cout<<"Block 2"<<endl;
            t -> next = first;
            first = t;
        }
        else
        {
            std::cout<<"@(first__3)"<< first<<endl;
            cout<<p<<endl;
            cout<<first<<endl;
            cout<<"Block 3"<<endl;
            t ->next = p;
            q ->next = t;
        }
    }
    return first;
}

int Delete(Node **first, int pos)
{
    Node *back,*front;
    //Initialize the pointer
    front = *first;
    back = NULL;
    
    int x = -1;
    if (pos == 0)
    {
        *first = (*first) ->next;
        x = front ->data;
        delete front;
        return x;
    }
    else
    {
        for(int i = 0 ; i < pos; i++ )
        {
            back = front;
            front = front ->next;
        }
        if(front)
        {
            x = front -> data;
            back->next = front ->next;
            delete front;
        }
        else
        {
            back ->next = NULL;
            x = front->data;
            delete front;
        }   
    }
    return x;
}

bool isSorted(Node *first)
{
    int min = -32563;
    Node *p = first;
    while( p!= NULL)
    {
        if( p-> data > min)
        {
            min = p->data;
            p = p->next;
        }
        else
        return false;
    }
    return true;
}

Node* removeDuplicate(Node *first)
{
    Node *p = first;
    Node *q = p ->next;
    while(q != NULL )
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }

    return first;
}

void Reverse1( Node *first)
{
    /*Create an intermediate array to implement*/
    /*Space consuming*/
    int *A = new int[count(first)];
    int i = 0;
    Node *p = first;

    while( p!=NULL)
    {
        A[i++] = p ->data;
        //cout<<"____"<<A[i];
        p = p->next;
    }
    p = first;
    i--;
    while(p!=NULL)
    {
        p->data = A[i];
        p = p->next;
        i--;
    }
}

Node* Reverse2(Node *first)
{
    /*Use sliding pointers to implement
    Less space, but more difficult to implement*/
    Node *left = NULL;
    Node *mid  = NULL;
    Node *right = first;

    while(right != NULL)
    {
        left = mid;
        mid = right;
        right = right->next;
        mid ->next = left;
    }
    return mid;
}

Node* concatenate( Node*first, Node *second)
{
    Node *p = first;
    while(p->next != NULL)
    {
        p= p -> next;
    }
    p->next  = second;

    second = NULL;
    return first;
}

Node* merge( Node *first, Node *second )
{
    Node *p;//p will be returned
    Node *tracker;
    if(first -> data < second ->data)
    {
        p = first;
        tracker = p;
        first = first -> next;
        tracker ->next = NULL;
    }
    else
    {
        p  = second;
        tracker = p;
        second = second -> next;
        tracker ->next = NULL;
    }

    while( first != NULL && second != NULL)
    {
        if(first->data < second ->data)
        {
            tracker -> next = first;
            tracker = first;
            first = first -> next;
            tracker ->next = NULL;
        }
        else
        {
            tracker -> next = second;
            tracker = second;
            second = second -> next;
            tracker ->next = NULL;
        }
    }

    if( first != NULL) tracker -> next = first;
    if( second != NULL) tracker -> next = second;
    return p;
}

bool isLoop(Node *first)
{
    Node *slow, * fast;
    slow = fast =first;

    do
    {
        /* code */
        slow = slow -> next;
        fast = fast -> next;
        if(fast == NULL)
            return false;
        else
            fast = fast -> next;
        
    } while ( slow && fast && slow != fast);

    if(slow == fast)
        return true;
    else
        return false;
}

int main()
{
    int A[] = {3,5,7,10,15};
    Node *t1 = create(A,5);
    Node *t2  = create(A,5);

    //Display2(t1);
    Display(t1);

    cout<<endl;

    cout<<Add1(t1)<<endl;
    cout<<count1(t1)<<endl;
    cout<<max1(t1)<<endl;

    Node*t3 = moveTohead(t1,10);
    Display(t3);
    cout<<endl;
    Node *t4 = create(A,5);

    Insert(t4,2,99);
    Display(t4);
    cout<<endl;
    push_end(t4,111);
    Display(t4);
    cout<<endl;

    Node *t5 = create(A,5);
    //SortedInsert(t5,12);
    //cout<<"Done"<<endl;
    t5= SortedInsert(t5,4);
    t5 = SortedInsert(t5,2);
    Display(t5);
    cout<<endl;

    cout<<(Delete(&t5,3))<<endl;
    Display(t5);
    cout<<endl;

    cout<<(Delete(&t5,5))<<endl;
    Display(t5);
    cout<<endl;

    cout<<(Delete(&t5,0))<<endl;
    Display(t5);
    cout<<endl;

    int B[] = {1,3,5,7,9};
     Node *t6 = create(B,5);//1,3,5,7,9
    cout<<isSorted(t6)<<endl;

    int C[] = {2,4,6,8,10,12};
    Node *t7 = create(C,6);
    Display(removeDuplicate(t7));
    cout<<endl;

    Reverse1(t7);
    Display(t7);
    cout<<endl;

    Node *t8 = create(C,6);//2,4,6,8,10,12
    Display(Reverse2(t8));
    cout<<endl;

    Node *t9 = create(C,6);
    Node *t10 = create(B,5);
    cout<<"Concate: "<<endl;
    Display(concatenate(t9,t10));
    cout<<endl;
    cout<<"Immutable?"<<endl;
    Display(t10);
    cout<<endl;
    Display(t9);
    cout<<endl;
    cout<<"No, mutable"<<endl;
    
    Node *t11 = create(C,6);//2,4,6,8,10,12
    Node *t12 = create(B,5);//1,3,5,7,9
    

    Display(merge(t11,t12));
    cout<<endl;

    cout<<isLoop(t11);
    cout<<endl;
}
