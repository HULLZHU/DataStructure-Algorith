#include<iostream>
#include<cmath>
using namespace std;

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *t;
};

Poly add(Poly &p1, Poly &p2)
{
    int i=0,j=0,k=0;
    Poly P3;
    P3.t = new Term[p1.n+p2.n];

    while(i < p1.n && j < p2.n)
    {
        if(p1.t[i].exp > p2.t[j].exp)
        {
            P3.t[k].exp = p1.t[i].exp;
            P3.t[k++].coeff = p1.t[i++].coeff;
        }
        else if(p1.t[i].exp < p2.t[j].exp)
         {
            P3.t[k].exp = p2.t[j].exp;
            P3.t[k++].coeff = p2.t[j++].coeff;
        }
        else
        {
            P3.t[k].exp = p2.t[j].exp;
            P3.t[k++].coeff =p1.t[i++].coeff+p2.t[j++].coeff;
        }
    }
    return P3;
}

int main()
{
    Poly poly;
    poly.n = 5;

    Term* t1 = new Term[5];

    t1[0].coeff = 5;
    t1[0].exp=5;
    t1[1].coeff = 4;
    t1[1].exp=4;
    t1[2].coeff = 3;
    t1[2].exp=3;
    t1[3].coeff = 2;
    t1[3].exp=2;
    t1[4].coeff = 1;
    t1[4].exp=1;
    t1[5].coeff = 0.5;
    t1[5].exp=0.5;

    poly.t = t1;

    Poly poly2 = add(poly,poly);

    cout<<"Case 1:"<<endl;
    int sum = 0;
    int x = 2;
    for(int i = 0 ; i < 5; i ++ )
        sum += poly.t[i].coeff*pow(x,poly.t[i].exp);
    cout<<"Sum = "<<sum<<endl;

    int sum2 = 0;
    cout<<"Case 2:"<<endl;
    for(int i = 0 ; i < 5; i ++ )
        sum2 += poly2.t[i].coeff*pow(x,poly2.t[i].exp);
    cout<<"Sum = "<<sum2<<endl;
    cout<<"___"<<endl;
}