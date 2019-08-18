#include<iostream>
using namespace std;

int main()
{
    int *p, *q;

    p = new int[5];
    q = new int[10];
    p[0] = 3;p[1] = 5;p[2] = 7;p[3] = 9;p[4] = 11;



    for ( int i = 0 ; i < 5; i ++ )
        q[i] = p[i];

    delete [] p; //delete the memory pointed by p in the heap
    p = q; // p points to the memory pointed by q
    q = nullptr; //q points to no memory

    for ( int i = 0 ; i< 5; i ++ )
        cout<<p[i]<<endl;

    q = new int[10];


}
