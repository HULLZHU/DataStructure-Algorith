/* Tower of Hanoi*/
#include<iostream>
using namespace std;

void TOH(int n, char a='A', char b ='B', char c ='C')
{
    if ( n > 0)
    {
        TOH(n-1,a,c,b);
        cout<<"FROM "<< a <<" TO "<<c<<" Using "<<b<<endl;
        TOH(n-1,b,a,c);
    }

}


int main()
{
    TOH(10);
}
