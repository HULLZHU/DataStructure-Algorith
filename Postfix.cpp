#include<iostream>
#include<cstring>
using namespace std;

struct Node
{
    char data;
    Node* next;
}*top = NULL;

void push(char x)
{
    Node *t = new Node;
    if(t == NULL)
        cout<<"Stack is full\n";
    else
    {
        t->data = x;
        t -> next = top;
        top = t;
    }
}

char pop()
{
    Node *t;
    char x = -1;

    if(top==NULL)
        cout<<"Empty Stack\n";
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Display()
{
    Node *p = top;
    while(p)
    {
        cout<<p->data<<", ";
        p = p->next;
    }
}

int isBalanced( char *exp)
{
    for(int i = 0; exp[i] != '\0'; i++ )
    {
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i] ==')')
        {
            if(top == NULL)
                return 0;
            pop();
        }
    }
    if(!top)
        return 1;
    return 0;
}

int pre(char x)
{
    if(x == '+'||x=='-')
        return 1;
    else if(x== '*'||x=='/')
        return 2;
    return 0;
}

int isOperand(char x)
{
    if(x =='+'||x=='-'||x=='*'||x=='/')
        return 0;
    else 
        return 1;
}

char *toPostfix(char *infix)
{
    int i = 0 ; int j = 0; // i is to track infix, j is to track postfix 
    char *postfix = new char[strlen(infix)+1];

    while(infix[i] != 0 )
    {
        if(isOperand(infix[i]))
        {   
            cout<<"Test 1"<<endl;
            postfix[j++] = infix[i++];
        }
        else
        {
            cout<<"Test 2 "<<endl;
             #line 100 "Insert '#' before reading a string"
            if(pre(infix[i]) > pre(top->data)) //如果precedence比stack中的top大，push进stack
            {   
                cout<<"Test 3 "<<endl;
                push(infix[i++]);
            }
            else//反正，将stack中的首个元素冒泡出来，塞到postfix字符串尾部
            { 
                cout<<"Test 4 "<<endl;
                postfix[j++] = pop();
            }
        }
    }
    while(top)
        postfix[j++] = pop();
    postfix[j] ='\0';//Please remember to add '\0' at the end of C-style string
    return postfix;
}

int Eval(char *postfix)
{
    int i = 0 ;
    int x1,x2,r=0;

    for( i = 0 ; postfix[i] !='\0';i++)
    {
        if(isOperand(postfix[i]))
                push(postfix[i]-0);
        else
        {
            x2 = pop();
            x1 = pop();
            switch(postfix[i])
            {
                case '+': r = x1 + x2; break;
                case '-': r = x1 - x2; break;
                case '*': r = x1 * x2; break;
                case '/': r = x1/x2  ; break;
            }
            push(r);
        }
        
    }

    return top->data;
}

int main()
{
    char postfix2[] ="234*+82/-";
    cout<<Eval(postfix2)<<endl;
}
