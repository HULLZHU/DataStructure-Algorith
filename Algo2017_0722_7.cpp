/*Fibonacci*/
#include<iostream>
using namespace std;

int F[10];

/*The most often one*/
int fab1(int n)
{
    if ( n <= 1)
        return n;
    return fab1(n-2)+fab1(n-1);
}

/*Iteration method*/R
int fab2(int n)
{
    int t0 = 0;
    int t1 = 1;
    int s = 0;
    for ( int i = 2; i <= n ; i ++ )
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }

    return s;
}

/*Memoization*/
int fab3(int n)
{
    if ( n <= 1)
    {
        F[n] = n;
        return F[n];
    }

    else
    {
        if (F[n-2] == -1)
            F[n-2] = fab3(n-2);
        if (F[n-1] == -1)
            F[n-1] = fab3(n-1);
        return F[n-1] + F[n-2];
    }
}


int main()
{
    for (int i = 0 ; i < 10 ; i ++ )
        F[i] = -1;

        cout<<fab3(10)<<endl;
        cout<<fab2(10)<<endl;
        cout<<fab1(10)<<endl;
}
