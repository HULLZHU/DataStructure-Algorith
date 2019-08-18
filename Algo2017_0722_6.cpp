/*Horner Rule for Taylor Series*/
#include<iostream>
using namespace std;

double exp1(int x,int n)
{
    static double s = 1;
    if ( n == 0)
        {
            double s1 = s;
            s = 1;
            return s1;
        }
    s = 1+s*x/n;
    return exp1(x,n-1);
}

double exp2(int x, int n)
{
    double s = 1;
    for (; n> 0 ;n --)
        s = 1+s*x/n;
    return s;
}

int main()
{
    cout<<exp1(4,10)<<endl;
    cout<<exp2(4,10)<<endl;
}
