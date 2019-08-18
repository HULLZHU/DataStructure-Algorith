//
// Created by 38516 on 2019/5/5.
//
#include<iostream>
using namespace std;

int fact(int n)
{
    if ( n <= 1)
        return 1;
    else
        return n*fact(n-1);
}

int c_simple(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    else
        return c_simple(n-1,r-1)+c_simple(n-1,r);

}

int c(int n, int r)
{
    int t1,t2,t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n-r);

    return t1/(t2*t3);
}

int main()
{
    cout<<c(10,2);
    cout<<c_simple(10,2);
}



