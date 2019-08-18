//
// Created by 38516 on 2019/5/1.
//
#include <iostream>
using namespace std;

double exp( double x, int n)
{
    static double p = 1, f=1;
    double r = 0;
    if ( n == 0)
        return 1;
    else
    {
         r = exp(x,n-1);
         p = p * x;
         f = f * n;
         return r + p/f;
    }
}

double e_tailRecursion(double x, int n)//More Easily to be understood but need one more temp variable
{
    //Use count to count the number of recursions
    static int count = 1;
    static double p=1;
    static double fac = 1;
    static double r = 0;
    if (count < n )
    {
        fac = fac*count;
        p = x*p;
        count ++;
        r = r +  p/fac + e_tailRecursion(x,n);
    }
    return 1 + r;
}


int main()
{
    cout<<e_tailRecursion(5,20);
}
