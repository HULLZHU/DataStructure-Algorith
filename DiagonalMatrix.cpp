#include<iostream>
using namespace std;

struct Diag
{
    int A[10];
    int n;
};

void set(Diag *diag, int i, int j, int x)
{
    if(i == j)
        diag->A[i-1]=x;
}

int get(Diag *diag, int i, int j)
{
    if( i == j )
        return diag->A[i-1];
    else
        return 0;
}

void Display(Diag *diag)
{


    for(int i = 0 ; i < diag->n ; i ++ )
    {
        for(int j = 0 ; j < diag-> n; j ++ )
        {
            if(i == j)
                cout<<diag->A[i]<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    Diag diag;
    diag.n = 4;

    set(&diag,1,1,15);
    set(&diag,2,2,5);
    set(&diag,3,3,9);
    set(&diag,4,4,10);
    set(&diag,5,5,12);

    Display(&diag);
    cout<<get(&diag,1,1);

    return 0;
}