//
// Created by 38516 on 2019/5/1.
//
#include <iostream>
using namespace std;

int cum_sum( int n) // We only need to use formula sum = n*(n+1)/2 in practice
{
    if ( n > 0)
    {
        return n + cum_sum(n-1);
    }
    return n;
}

int main()
{
    int sum = cum_sum(100);
    cout <<sum<<endl;
}
