#include<iostream>
using namespace std;

class LowerTriangle
{
private:
    int *A;
    int n;
public:
    LowerTriangle()
    {
        n=2;
        A = new int[2*(2+1)/2];
    }
    LowerTriangle(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];     
    }

    ~LowerTriangle()
    {
        delete []A;
    }

    void set(int i, int j, int x);
    int get(int i, int j);
    void print();
};

void LowerTriangle::set(int i, int j, int x)
{
    if( i >= j )
        A[ i*(i-1)/2 + j - 1 ] = x;
}

int LowerTriangle::get(int i, int j)
{
    if( i == j )
        return A[ i*(i-1)/2 + j - 1];
    return 0;
}

void LowerTriangle::print()
{
    for(int i = 1 ; i <= n ; i ++ )
    {
        for(int j = 1 ; j <= n; j ++ )
        {
            if(i==j)
                cout<<A[i*(i-1)/2 + j - 1]<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    LowerTriangle *lt = new LowerTriangle(3); 
    lt->set(1,1,1);
    lt->set(2,2,2);
    lt->set(3,3,3);
    lt->print(); 
}