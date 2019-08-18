/*Power(m,n)*/
#include<iostream>
using namespace std;

int power1(int m, int n)
{
    if(n == 0)
        return 1;
    return m*power1(m,n-1);
}

int power2(int m, int n)
{
    if( n == 0 )
        return 1;
    else if( n % 2 == 0 )
        return power2(m*m,n/2);
    else
        return power2(m*m,n/2)*m;

}

int main()
{
    cout<<power2(2,5)<<endl;
    cout<<power2(2,5);
}
