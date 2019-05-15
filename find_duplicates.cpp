#include <iostream>
using namespace std;

//using intermediate variable to determine whether an element is a duplicate or not in a sorted array
void find_duplicates1(int *a, int length)
{
    int last_duplicate= -1;
    for ( int i = 0 ; i < length ; i ++)
    {
        if (a[i+1]== a[i] )
        {
            if (a[i+1] != last_duplicate)
            {
                last_duplicate = a[i+1];
                cout<<"Duplicate Element "<<last_duplicate<<endl;
            }
        }
    }
}

//using hashing method to find the duplicate number and determine the duplicate time
void find_duplicates2(int *a, int length,int maximum)
{
    int *ht = new int[maximum];
    for ( int i = 0; i< maximum ; i++)
        ht[i] = 0;

    for ( int i = 0 ; i < maximum;i++)
        ht[a[i]]++;

    for ( int i = 0 ; i < maximum;i++)
    {
        if ( ht[i] > 1)
            cout<<"Number" << i<<" Missing for "<<ht[i]<<"times"<<endl;
    }
}

int main()
{
    int a[10] = {1,1,1,2,3,4,4,5,6,7};
    find_duplicates1(a,10);
    find_duplicates2(a,10,7);

}
