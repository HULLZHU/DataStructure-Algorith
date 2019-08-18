//
// Created by 38516 on 2019/5/1.
//
#include <iostream>
using namespace std;

static int count = 0;

//function declarations
void funcA(int n);
void funcB(int n);

//function definitions
void funcA(int n)
{
    if ( n > 0)
    {
        count++;
        cout<<count<<":"<<n<<endl;
        funcB(n-1);
    }

}

void funcB(int n)
{
    if ( n > 0 )
    {
        count ++ ;
        cout<<count<<":"<<n<<endl;
        funcA(n/2);
    }
}

int main()
{
    int n = 100;
    funcA(n);

}
