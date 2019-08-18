//
// Created by 38516 on 2019/5/1.
//
#include <iostream>
using namespace std;

//ascending recursion
void func1(int n)
{
    if ( n > 0 )
    {
        cout<<n<<endl;
        func1(n-1);
    }

}

//descending recursion
void func2(int n)
{
    if ( n > 0 )
    {
        func2(n-1);
        cout<<n<<endl;
    }

}
int main()
{
    func1(10);
    func2(10);
    return 0;
}
