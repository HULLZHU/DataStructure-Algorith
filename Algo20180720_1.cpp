/*Finding duplicates in a sorted array*/
/*Main Idea : Intermediate variable to store the last duplicate*/
#include<iostream>
using namespace std;

int main()
{
    int A[10] = {3,6,8,8,10,12,15,15,15,20};

    int lastDuplicate = 0;//last duplicate should be given a number not in the array

    for (int i = 0 ; i < 10 ; i ++ )
    {
        if ( A[i] == A[i+1] && A[i] != lastDuplicate)
        {
            cout<<"Number "<<A[i] <<" is duplicate"<<endl;
            lastDuplicate = A[i];
        }
    }
}
