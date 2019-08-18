//
// Created by 38516 on 2019/4/30.
//
#include <iostream>
using namespace std;


void swap(double &x, double &y) //standard swap operations
{
    int t;
    t = x;
    x = y;
    y = t;
}

void bitwise_swap(int &a, int &b)
{
    if (a != b)
    {
        a ^= b; // a^=b equals a = a^b
        b ^= a; // b^=a equals b = b^a = b^(a^b) = b^b^a = 0 ^ a = a
        a ^= b; // a^b = b equals a= a^b  = (a^b)^a = a^a^b = b
    }
}

int sum(int array[], int &n)
{
    int s,i;
    s = 0;
    for ( i = 0 ; i < n ; i ++ )
    {
        s = s+array[i];
    }
    return s;
}

int** add(int &n, int *A, int *B)
{
    int **c = new int*[n]; //创建一个有n个元素的的指针数组 [int *, int *, int *]
    for ( int i = 0 ; i < n; i ++ ) //n + 1
    {
        c[i] = new int[n];//创建一个含有N个元素的数组，并指向c[i]
        for ( int j = 0; j <n; j ++) // n *（n+1)
        {
            c[i][j] = A[i] + B[i]; //n*n
        }
    }
    return c;


}
int main()
{
    int A[3] = {1,2,3};
    int B[3] = {4,5,6};
    int n = 3;
    int **C;
    C = add(n,A,B);

    for ( int i = 0 ; i < 3; i ++ )
    {
        for ( int j = 0; j < 3; j ++ )
        {
            std::cout<<(C[i][j]);
        }
    }

    int total = sum(A,n);

    int x = 0;
    int y = 1;
    bitwise_swap(x,y);
    cout<<x<<endl;
    cout<<y<<endl;

}

