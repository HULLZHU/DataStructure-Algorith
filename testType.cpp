#include<iostream>
using namespace std;

template<class A, class B>
auto findMin(A a, B b) ->decltype(a<b ? a: b)
{
    return (a<b)?a:b;
}

template<class A, class B>
auto findMax(A a, B b)
{
    return a>b?a:b;

}

int main()
{
    cout<<findMin(4,3.44)<<endl;
    cout<<findMax(4,3.44)<<endl;
}