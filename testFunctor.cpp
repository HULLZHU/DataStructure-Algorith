#include <iostream>
#include <algorithm>
using namespace std;

class multiply
{
private:
    int m;
public:
    multiply( int _m):m(_m){};
    int operator()(int arr_num)const{return m*arr_num;};
};

int increment(int n)
{
    return n + 1;
}

void test(int m, int n, int pf(int x))
{
    int _m = m + pf(1)+1;
    int _n = n + pf(2)+2;
    cout<<_m<<endl;
    cout<<_n<<endl;
    cout<<endl;
}

int main()
{
    int a[] ={1,3,4,5,6,7};
    int n = 6;
    int m1 = 3;
    int m2 = 4;

    transform(a,a+6,a,multiply(m1));
    for(int i = 0 ; i < n ; i++ )
        cout<<a[i]<<", ";
    
    cout<<endl;

    transform(a,a+6,a,multiply(m2));
    for(int i = 0 ; i < n ; i++ )
        cout<<a[i]<<", ";  

    cout<<endl; 

    int (*ic)(int n);
    ic = increment;
    cout<<ic<<endl;
    cout<<(*ic)(10)<<endl;

    ic = &increment;
    cout<<ic<<endl;
    cout<<ic(10)<<endl;

    test(10,20,ic);
    cout<<endl;
    test(20,30,increment);
    
}