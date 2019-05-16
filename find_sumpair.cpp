#include <iostream>
using namespace std;

void findSumPair1(int *a, int length,int sum)
{
    for ( int i = 0 ; i < length-1 ; i ++ )
    {
        for(int j = i+1 ; j < length ; j ++ )
        {
            if ( a[i] + a[j] == sum)
                cout<<"Pair: "<<a[i]<<" and "<<a[j]<<endl;
        }
    }
}

//using hashing method find sum pair
void findSumPair2(int *a, int length,int sum, int maximum)
{
    //initialize hash
    int *ht = new int [maximum];
    for ( int i = 0 ; i < maximum;i++)
        ht[i] = 0;
    //mark hash

    for ( int i = 0; i < length;i++)
    {
        if (ht[sum - a[i]] == 1)
            cout<<"Pair"<<a[i]<<"and"<<sum-a[i]<<endl;
        ht[a[i]] = 1;
    }
}

//find a sum pair in a sorted array, using convergence from 2 sides
void findSumPair3(int *a, int length,int sum)
{
    for ( int i = 0 , j = length - 1; i < j; )
    {
        if ( a[i] + a[j] == sum )
            cout<<"Pair"<<a[i++]<<":"<<a[j--]<<endl;
        else if ( a[i] + a[j] < sum)
            i ++;
        else
            j--;
    }
}

int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    findSumPair1(a,10,7);
    findSumPair2(a,10,7,10);
    findSumPair3(a,10,7);
}
