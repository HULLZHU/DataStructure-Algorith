//
// Created by 38516 on 2019/5/1.
//

#include <iostream>
using namespace std;

int func(int n)
{
    if ( n > 100)
        return n-10;
    else
        return func(func(n+11));
}



int main()
{
    int a = func(90);
    cout <<a<<endl;
}