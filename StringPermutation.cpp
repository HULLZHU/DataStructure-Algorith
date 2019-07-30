#include<iostream>
using namespace std;

void swap(int&a, int&b)
{
    int temp = a;
    a = b;
    b = temp;
};


void perm(char A[], int begin, int length)
{
    if(begin == length)
        cout<<A<<endl;
    else
    {
        for(int i = begin ; i < length; i ++ )
        {
            swap(A[begin],A[i]);
            perm(A,begin+1,length);
            swap(A[begin],A[i]);
        }
    }
};

int main()
{
    char A[] = "Hello";
    perm(A,0,5);
}