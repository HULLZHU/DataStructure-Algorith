#include<iostream>
#include<typeinfo>
#include<string>
using namespace std;

int fun1()
{
    return 10;
}

string fun2()
{
    return "He Zhu is the best engineer";
}

int main()
{
    decltype(fun1()) x =10;
    decltype(fun2()) y = "Hello Hello Hello";

    cout<<typeid(x).name()<<endl;
    cout<<typeid(y).name()<<endl;

}