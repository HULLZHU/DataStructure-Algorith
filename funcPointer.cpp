#include<iostream>
using namespace std;

int product(int x, int y)
{
    return x*y;
}

int useProd(int m, int n, int pf(int a, int b))
{   
    cout<<"Number<< "<<m<<" "<<n<<endl;
    cout<<"The product is"<<pf(m,n)<<endl;
}

int retProduct(int x, int y)
{
    using F = decltype(product);
    //F is function type
    F *f = product;
    return f(3,3);
}

int retProduct2(int x, int y)
{
    using F = int(int,int);
    //F is function type
    F *f = product;
    return f(x,y);
}

int retProduct3(int x, int y)
{
    using F = int(*)(int,int);
    //This time F is function pointer type 
    F f = product;
    f(9,9);
}

int retProduct4(int x, int y)
{
    int (*f1)(int x, int y);
    f1 = product;
    return f1(x,y);
}

int retProduct5(int x, int y)
{
    decltype(product) *f;
    f = product;
    return f(x,y);
}

int main()
{
    //general function pointer
    int(*pd) (int m, int n);
    pd = product;
    cout<<pd(10,10);

    /*using typdef key word to create 
    a function pointer type for 
    reusability and readability*/
    /*Following 2 are function types*/
    typedef int func2(int m, int n) ;
    typedef decltype(product) func3;
    func2 f2;
    func3 f3;

    /*Following 2 are function pointer type*/
    typedef int(*func4)(int m, int n);
    func4 f4 = product;
    typedef decltype(product) *func5;
    func5 f5 = product;
    /*Pass function pointer*/
    useProd(10,10,f4);
    useProd(12,12,f5);

    cout<<retProduct(3,3)<<endl;
    cout<<retProduct2(6,7)<<endl;
    cout<<retProduct3(9,9)<<endl;
    cout<<retProduct4(12,31)<<endl;
    cout<<retProduct5(13,31)<<endl;
}