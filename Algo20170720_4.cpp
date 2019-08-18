/*Find sum pair of K*/
/*Naive Method, double loop, O(n^2)*/

#include<iostream>
using namespace std;

int main()
{
    int sum = 8;
    int A[10] = {6,3,8,10,16,7,5,2,9,14};

    for ( int i = 0 ; i < 9 ; i ++ )
    {
        for ( int j = i + 1; j < 10; j ++ )
        {
            if (A[i] + A[j] == sum)
                cout<<A[i]<<"+"<<A[j]<<"="<<sum<<endl;
        }
    }
}
