/*Recursion local variable, local static variable, and global variable*/

#include <iostream>
using namespace std;

int fun(int n )
{
    if ( n > 0 )
    {
        return fun(n-1)+n;
    }
    return 0;
}

int fun2(int n)
{
    static int x = 0;
    if ( n > 0 )
    {
        x++;
        return fun2(n-1)+x;
    }
    return 0;
}


int main()
{
    int r = fun(5);
    cout<<r<<endl;
    r = fun2(5);
    cout<<r<<endl;

}
