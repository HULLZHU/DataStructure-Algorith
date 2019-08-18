#include <iostream>
using namespace std;

struct Node
{
    char data;
    struct Node *next;
}*top = NULL;

void push(char x)
{
    Node *t = new Node;
    if(t == NULL)cout<<"Stack Overflow"<<endl;
    else
    {
        t ->data = x;
        t -> next = top;
        top = t;
    }
}

int isEmpty()
{
    if(top)
        return 1;
    return 0;    
}

char pop()
{
    Node *t;
    char x = -1;
    if(top == NULL)
        cout<<"Empty Stack"<<endl;
    else
    {
        t = top;
        x = t->data;
        top = top->next;
        delete t;
    }
    return x;
}

int isBalanced(char *exp)
{
    for(int i = 0 ; exp[i] != '\0';i++ )
    {
        if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] ==')')
        {
            if(!top)
                return 0;
            pop();
        }
    }
    if(top == NULL)return 1;
    else return 0;
}

int main()
{
    char exp1[]="(1+2)*(3+4)";
    char exp2[] = "(1+2))(3+d)";

    cout<<isBalanced(exp2);
}