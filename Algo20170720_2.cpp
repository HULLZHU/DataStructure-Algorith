/*Hashing Method*/

#include<iostream>
using namespace std;

int main()
{
    int A[10] = {3,6,8,8,10,12,15,15,15,20};
    int HT[20] = {0};

    for ( int i = 0 ; i < 10; i ++ )
        HT[A[i]] ++;

    for (int i = 0 ; i < 20 ; i ++ )
    {
        if (HT[i] > 1 )
        {
            cout<<i<<" Duplicate "<< HT[i] <<"Times"<<endl;
        }

    }


}
