/*Recursive sum of first n numbers*/
#include<iostream>
using namespace std;

int sum(int n)
{
    if ( n == 0 )
        return 0;
    else
        return sum(n-1)+n;
}

int main()
{

    cout<<sum(10)<<endl;
}
