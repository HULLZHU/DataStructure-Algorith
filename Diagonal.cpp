#include<iostream>
#include<vector>
using namespace std;

class Diagonal
{
private:
    int width;
    int* A;
public:
    Diagonal()
    {
        width = 0;
        A = new int[0];
    };

    Diagonal(int _width, int *B)
    {
        width = _width;
        A = B;
    }

    ~Diagonal()
    {
        delete []A;
    }

    friend void operator<<=(Diagonal &diag, vector<int> &v);
    friend ostream& operator<<(ostream& os, Diagonal& diag);    
};

ostream& operator<<(ostream& os, Diagonal& diag)
{
    for(int i = 0 ; i < diag.width ; i ++ )
    {
        for(int j = 0 ; j < diag.width; j++)
        {
            if(i == j)
                cout<<diag.A[i]<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
}

void operator<<=(Diagonal &diag, vector<int>&v)
{
    diag.A = new int[v.size()];
    std::copy(v.begin(),v.end(),diag.A);
    diag.width = v.size();  
};

int main()
{
    int A[] = {1,2,3,4,5};
    vector<int> v(A,A+sizeof(A)/sizeof(A[0]));
    Diagonal *p_diag = new Diagonal();
    *p_diag <<= v;
    cout<<*p_diag;
}