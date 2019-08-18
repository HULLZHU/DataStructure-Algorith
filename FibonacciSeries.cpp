//
// Created by 38516 on 2019/5/2.
//
#include <iostream>
using namespace std;

int array[10] ={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} ;

int fib_rec(int n)
{
    if ( n == 0 || n == 1)
        return n;

    return fib_rec(n-2) + fib_rec(n-1);
}

int fib_loop(int n)
{
    int s = 0;
    int t0 = 0;
    int t1 = 1;

    if ( n == 1 || n == 0)
        return n;

    for (int i = 2 ; i <= n ; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int fib_quick(int n)//memoization
{
    if( n == 0 || n == 1) //2 known conditions
    {
        array[n] = n;
        return array[n];
    }

    else
    {
        if (array[n - 2] == -1)
            array[n - 2] == fib_quick(n-2);

        if ( array[n-1] == -1)
            array[n-1] == fib_quick(n-1);

        array[n] = array[n-1]+array[n-2];
        return array[n];
    }


    return array[n];

}



int main()
{
    cout<<fib_rec(5)<<endl;
    cout<<fib_loop(5)<<endl;
    cout<<fib_quick(5)<<endl;

}
