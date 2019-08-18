/*TOH*/
#include<iostream>
using namespace std;

void TOH(int n, char a, char b, char c)
{
    if ( n == 1)
        cout<<"From "<<a<<"to "<<c<<" by "<< b <<endl;
    else
    {
        TOH(n-1,a,c,b);
        TOH(1,a,b,c);
        TOH(n-1,b,a,c);
    }


}

int main()
{
    TOH(10,'A','B','C');
}
