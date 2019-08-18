//
// Created by HeZhu on 2019/5/1.
//
#include <iostream>
using namespace std;

int func_nonstatic(int n) //Every time this function is called, a new copy of n will be created in the stack memory
{

    if ( n > 0)
    {
        return func_nonstatic(n-1)+n;
    }

    return 0;
}

int func_static(int n) //Every time this function is called, only the value of static variable x will be changed
{                      //static variable x is stored in a subsection of the code section of main memory
                       //The final output should be n*x, because every call of the function will use the same copy of x
    static int x = 0;
    if(n > 0)
    {
        x ++;
        return func_static(n-1)+x;
    }

    return 0;
}

int main()
{
    cout<<func_nonstatic(5);
    cout<<func_static(5);
}
