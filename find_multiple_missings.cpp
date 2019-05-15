#include <iostream>
using namespace std;

//using differentiation method to get multiple missing elements
void findMultipleMissings1(int *a, int length)
{
    int diff = a[0];
    for ( int i = 0 ; i < length ; i++)
    {
        if ( a[i] - i != diff )
        {
            while(diff + i < a[i])
            {
                cout<<"Missing Number "<< diff+i<<endl;
                diff ++;
            }
        }
    }
}

//using hashing method to find multiple missing elements
void findMultipleMissings2(int *a, int length, int minimum, int maximum)
{
    //usually we can create a static global hash to save time
    int *ht = new int[maximum-minimum+1];
    for ( int i = 0 ; i <= maximum-minimum;i++)
        ht[i] = 0;
    ht[0] = 1;
    for ( int i = 0 ; i < length; i++)
        ht[a[i]]=1;

    for ( int i = 0 ; i <= maximum-minimum;i++)
    {
        if(ht[i] == 0)
            cout<<"Number "<<i<<" is missing"<<endl;
    }
}

int main()
{
    int a[10] = {1,2,3,5,8,9,10,14,15,16};
    findMultipleMissings1(a,10);
    findMultipleMissings2(a,10,1,16);
}
