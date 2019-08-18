//
// Created by 38516 on 2019/5/1.
//
#include <iostream>
using namespace std;

//output by head recursion
void func_rec(int n)
{
    if ( n > 0 )
    {
        func_rec(n-1);
        cout<<n<<endl;
    }

}

//output by simple loop
void func_loop(int n)
{
    int i = 1;
    while ( i <= n)
    {
        cout<<i<<endl;
        i ++;
    }
}

int main()
{
    func_loop(10);
    func_rec(10);

}
