/*can be used to find duplicate elements and duplicate numbers in the array*/
#include<iostream>
using namespace std;

int main()
{
    int A[20] = {3,6,8,3,4,7,5,6,13,10,12,14,13,15,16,18,7,19,20,7};
    for (int i = 0 ; i < 19 ; i ++ )
    {
        int count = 1;
        for ( int j = i + 1; j < 20 ; j++ )
        {
            if(A[j] == A[i])
            {
                count ++;
                A[j] = -1;
            }
        }

        if (count > 1 &&A[i] != -1)
            cout<<A[i]<<" is duplicate for "<<count<<" times"<<endl;
    }

}
