//
// Created by 38516 on 2019/5/1.
//Using Horner rule to solve for Taylor Series
//From O(n^2) -> O(n)
#include <iostream>
using namespace std;

double exp_loop(double x, int n)
{
    double s = 1;
    while ( n > 0 )
    {
        s = 1 + x/n*s;
    }
    return s;
}

double exp_rec(double x, int n)
{
    static double s;
    if ( n == 0)
        return s;

    s = 1 + x/n*s;
    return e(x,n-1);

}

int main()
{

}

