/*利用首尾逼近法寻找 sumpair*/
#include<iostream>
using namespace std;

int main()
{
    int sum = 10;
    int A[10] = {1,3,4,5,6,8,9,10,12,14};
    int i = 0, j = 9;

    while ( i < j )
    {
        if ( A[i]+A[j] == sum )
        {
            cout<<"Pair: "<< A[i] << " and "<<A[j]<<endl;
            i ++, j--;
        }
        else if ( A[i]+A[j] < sum )
            i ++ ;
        else
            j -- ;
    }
}
