#include <iostream>
using namespace std;

class LowerTri
{
private:
    int n;
    int *A;

public:
    LowerTri()
    {
        this->n = 3;
        A = new int[3*(3+1)/2];
    }

    LowerTri(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }

    ~LowerTri(){delete []A;};

    bool set(int i, int j ,int x);

    int get(int i, int j);

    int get_dimension(){return n;};

    friend ostream &operator<<(ostream &os, LowerTri &diag);

};


bool LowerTri::set(int i, int j, int x)
{
    if(i >= j)
    {
        A[i*(i-1)/2 + j - 1]= x;
        return true;
    }
    return false;
}

int LowerTri::get(int i, int j)
{
    if ( i>=j )return A[i*(i-1)/2+j-1];
    else return 0;
}

ostream& operator<<(ostream &os, LowerTri &diag)
{
    for(int i = 1 ; i <= diag.n; i ++ )
    {
        for ( int j = 1 ; j <= diag.n; j ++ )
        {
            if ( j == 1)
                cout<<"|";

            if ( i >= j)
                cout<<diag.A[i*(i-1)/2+j-1]<<",";
            else
                cout<<0<<",";

            if (j == diag.n)
            cout<<"|\n";
        }
    }
}

int main()
{
    int d;
    cout<<"Enter Dimensions"<<endl;
    cin >>d;
    LowerTri lm(d);
    int x;

    cout<<"Enter All Elements"<<endl;

    for ( int i = 1; i <= d; i ++ )
    {

        for ( int j = 1; j <= d;j++)
        {
            cin >>x;
            lm.set(i,j,x);
        }
    }
    cout<<lm;

}
