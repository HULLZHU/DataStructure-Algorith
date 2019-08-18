#include<iostream>
using namespace std;
#include <stdio.h>
int main()
{

    /*Method 1: Double Pointer Method*/
    int **A = new int*[3];//Create a double pointer
                          //The double pointer points
                          //to the array of pointers
                          //in the type of integer
    A[0] = new int[4];
    A[1] = new int[4];
    A[2] = new int[4];

    for ( int i =0 ; i < 3; i++)
    {

        for ( int j = 0 ; j < 4;j ++ )
            A[i][j]=(i+1)*(j+1);
    }

    /*Method 2: Static Method */
    int B[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    //Store an array in a continuous stack memory

    /*Method 3: an array of integer pointer*/
    int *C[3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];

     for ( int i =0 ; i < 3; i++)
    {

        for ( int j = 0 ; j < 4;j ++ )
            C[i][j]=(i+1)*(j+1);
    }

    //print arrays
    for ( int i =0 ; i < 3; i++)
    {

        for ( int j = 0 ; j < 4;j ++ )
            cout<<A[i][j]<<":"<<B[i][j]<<":"<<C[i][j]<<endl;
    }



}
