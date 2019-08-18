#include <iostream>
using namespace std;

class Diagonal
{
private:
    int n;
    int *A;

public:
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }

    ~Diagonal(){delete []A;};

    bool set(int i, int j ,int x);

    int get(int i, int j);

    friend ostream &operator<<(ostream &os, Diagonal &diag);

};


bool Diagonal::set(int i, int j, int x)
{
    if(i == j)
    {
        A[i-1]= x;
        return true;
    }
    return false;
}

int Diagonal::get(int i, int j)
{
    if ( i==j )return A[i-1];
    else return 0;
}

ostream& operator<<(ostream &os, Diagonal &diag)
{
    for(int i = 0 ; i < diag.n; i ++ )
    {
        for ( int j = 0 ; j < diag.n; j ++ )
        {
            if ( j == 0)
                cout<<"|";

            if ( i == j)
                cout<<diag.A[i]<<",";
            else
                cout<<0<<",";

            if (j == diag.n-1)
            cout<<"|\n";
        }
    }
}

int main()
{
    Diagonal *diag = new Diagonal(5);
    diag->set(1,1,5);
    diag->set(2,2,4);
    diag->set(3,3,3);
    diag->set(4,4,2);
    diag->set(5,5,1);
    cout<<*diag;

}
