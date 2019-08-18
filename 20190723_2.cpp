/*1-D and 3-D array*/
#include<iostream>
using namespace std;

void printArray(int *p_array, int n)
{
    for(int i = 0 ; i < n ; i ++ )
        cout<<p_array[i];
    cout<<endl;
}

int main()
{
    int A[4] = {1,2,3,4};
    for (int i = 0 ; i <4 ; i ++ )
        cout<<A[i];
    cout<<endl;

    int* B = new int[4];
    for (int i = 0 ; i < 4; i ++ )
        B[i] = 2*i;

    printArray(B,4);

    delete []B;

    int C[3][3];
    for(int i = 0 ; i < 3; i ++ )
        for(int j = 0; j < 3; j ++ )
            C[i][j] = i+j;

    int* D[3]; //Array of integer pointer with length = 3 in stack
    D[0] = new int[4];
    D[1] = new int[5];
    D[2] = new int[6];

    for (int i = 0 ; i < 6; i ++ )
        D[2][i] = i;

    printArray(D[2],6);

    int* *E;//Double pointer; Integer Pointer to array of Integer pointers in the heap
    E = new int* [3]; // Array of integer pointer in heap because of new operator
    E[0] = new int[4];
    E[1] = new int[4];
    E[2] = new int[5];

    for (int i = 0 ; i < 4 ; i ++ )
        E[0][i] = i;

    printArray(E[0],4);
}
