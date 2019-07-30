#include <iostream>
using namespace std;

int C(int m, int n)
{
    if( n == m || n == 0 )
        return 1;
    else
        return C(m-1,n-1)+C(m-1,n);
}

int main()
{
    cout<<"C(10,2): "<<C(10,2)<<endl;
}