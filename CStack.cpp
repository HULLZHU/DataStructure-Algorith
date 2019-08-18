#include<iostream>
using namespace std;

struct Stack
{
    int size;
    int top = -1;
    int *s;
}

void push(Stack* st, int x)
{
    if(st->top = st->size - 1)
        cout<<"The Stack is overflow"<<endl;
    else
    {
        st -> top++;
        st -> s[st->top]=x;
    }
}

int pop(Stack *st)
{
    if(top != -1 )
    {
        int result = st -> s[st->top];
        st->top --;
        return result;
    }
    else
    {
        cout<<"Stack underflow"<<endl;
    }
}

int peek(Stack *st, int pos)
{
    int x = -1;
    if(top - pos + 1 < 0 )
        cout<<"Invalid Position"<<endl;
    else
    {
        x = st->s[st->top-pos + 1];
    }
    return x;
}

int stackTop(Stack *st)
{
    if(st.top = -1)
        return -1;
    else
    {
        return st->s[top];
    }
}

int isEmpty(Stack *st)
{
    if(st->top == -1)
        return 1;
    else
    {
        return 0;
    }
}

int isFull(Stack *st)
{
    if(st->top == size)
        return 1;
    return 0;
}


int main()
{
    Stack st;
    st.size = 5;
    st.s = new int[st.size];
    st.top = -1;

}