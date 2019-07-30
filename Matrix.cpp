#include<iostream>
#include<vector>
using namespace std;

class Matrix
{
private:
    int m;//Row Number
    int n;//Column Number
    int num;//Number of elements
    int *A;
public:
    Matrix()
    {
        m=0, n= 0, num=0;
        A = new int[0];
    }
    Matrix(int _m, int _n)
    {
        num = m * n;
        A = new int[num];
    }
    Matrix(int _m, int _n, int *B, int length)
    {
        if(_m * _n != length)
            cout<<"Invalid Matrix Size or Invalid array length."<<endl;
        else
        {
            m = _m, n= _n;
            A = B;
        }
    }
    ~Matrix()
    {
        delete [] A;
    }

    friend ostream& operator<<(ostream& os, const Matrix& m);
};

ostream& operator<<(ostream &os, const Matrix &m)
{
    if(m.m !=0 || m.n !=0){
        for(int i = 0 ; i < m.m ; i ++ )
        {
            for (int j = 0; j < m.n; j ++ )
                cout<<m.A[(m.n*i+j)];
            cout<<endl;
        }
    }
    return os;
};

int main()
{
    int *B = new int[9];
    for (int i = 0 ; i < 9 ; i ++ )
        B[i] = i;

    Matrix *m = new Matrix(3,3,B,9);
    cout<<*m<<endl;
}
