//
// Created by 38516 on 2019/5/1.
//
#include <iostream>
using namespace std;

int power(int m, int n)
{
    if ( n <= 0 )
        return 1;
    else
        return m * power(m,n-1);
}

int simple_power(int m, int n)
{
    if ( n > 0 )
    {
        if ( n % 2 == 0 )
            return simple_power( m * m, n/2);
        else
            return m*simple_power(m*m,n/2);
    }

    else
        return 1;
}


int main()
{
    cout<<power(2,5);
    cout<<simple_power(2,6);
}