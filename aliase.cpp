#include<iostream>
#include<string>
#include <set>
#include<typeinfo>
using namespace std;

typedef int I;
typedef string S;
typedef int II [10];
typedef double* DP;

int main()
{
    I i = 10;
    S s = "HELLO HEZHU";
    II ii ={1,2,3,4,5};
    DP dp = new double[10];

    cout<<i<<endl;
    cout<<s<<endl;

    for(int i = 0 ; i < 5 ; i ++ )
    {
        cout<<ii[i]<<", ";
    }

    cout<<endl;

    cout<<typeid(i).name()<<endl;
    cout<<typeid(s).name()<<endl;

    set<string> st;
    st.insert({"He","Zhu","is","the","best","engineer"});

    for(auto it = st.begin(); it!= st.end(); it++)
    {
        cout<<*it<<" ";
        cout<<typeid(it).name()<<endl;
    }
    
    return 0;
}