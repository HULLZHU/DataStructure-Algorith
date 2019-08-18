//
// Created by 38516 on 2019/5/1.
//
#include <iostream>
using namespace std;

int fac( int n) {
    if (n <= 0)
        return 1;
    else
        return n * fac(n - 1);
};


int main()
{
    int result = fac(3);
    cout <<result<<endl;
}
