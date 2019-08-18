//
// Created by 38516 on 2019/5/1.
//
#include <iostream>
using namespace std;

void func(int n)
{
    static int count = 0;
    if ( n > 0)
    {
        count ++;
        cout<<count<<":"<<n<<endl;
        func(n-1);
        func(n-1);
    }
}


int main()
{
    func(4);
}
