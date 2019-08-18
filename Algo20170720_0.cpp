/*Finding and counting duplicate numbers in an array */
/*Main Idea: Inner Loop*/
/*2019-07-20*/
#include <iostream>
using namespace std;

int main()
{
    int A[10] = {3,6,8,8,10,12,15,15,15,20};

    for (int i = 0 ; i < 9 ; i++)
    {
        if (A[i] == A[i + 1 ])
        {
            int j = i + 1;
            while (A[j] == A[i]) j++;
            cout<<j-i<<" is the duplicate times of "<<A[i]<<endl;
            i = j - 1;
        }
    }
}
