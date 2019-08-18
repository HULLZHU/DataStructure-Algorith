/*Combination formula*/
#include<iostream>
using namespace std;

int HT[10];

int fact(int n)
{
    if ( n <= 1)
    {
        HT[n] = 1;
        return HT[n];
    }
    else
    {
        if( HT[n-1] != -1 )
        {
            HT[n] = n * HT[n-1];
            return HT[n];
        }
        else
        {
            HT[n] = n * fact(n-1);
            return HT[n];
        }
    }
    return -1;
}

//Use the basic formula to compute combination formula
int C1(int n, int r)
{
    return fact(n)/(fact(r)*fact(n-r));
}

//Use the Pascal Triangle to compute combination formula

int C2(int n, int r)
{
    if( n == r || r == 0)
        return 1;
    else
        return C2(n-1,r-1)+C2(n-1,r);
}


int main()
{
    for ( int i = 0 ; i < 10; i ++ )
        HT[i] = -1;

    cout<<fact(5)<<endl;
    cout<<C1(10,5)<<endl;
    cout<<C2(10,5)<<endl;

    int *p = new int[5];
    for (int i = 0; i < 5; i ++ )
        p[i] = i;

    p = p+2;
    for (int i = 0 ; i < 3; i ++ )
        cout<<p[i]<<endl;
    delete []p;
}
