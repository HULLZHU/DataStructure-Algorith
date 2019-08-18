//Using Linkedlist to implement the polynomial
#include<iostream>
#include<cmath>
using namespace std;

struct Node
{
    double coeff;
    double exp;
    Node *next;
}*poly =NULL;

void create(int num, double *coef, double *exp)
{
    Node*t, *last =NULL;
    for( int i = 0 ; i < num ; i++ )
    {
        t = new Node;
        t ->coeff = coef[i];
        t -> exp = exp[i];
        t ->next = NULL;
        if(poly == NULL)
        {
            poly = last = t;
        }
        else
        {
            last -> next = t;
            last = t;
        }
        
    }
}

double Eval(Node *p, double x)
{
    double val = 0;
    while(p)
    {
        val += p->coeff*std::pow(x,p->exp);
         p = p ->next;
    }
    return val;
}

int main()
{
    double coef[3] ={1.2,2.3,-1.7};
    double pow[3] = {3,2,1};
    create(3,coef,pow);
    cout<<Eval(poly,2);
}
