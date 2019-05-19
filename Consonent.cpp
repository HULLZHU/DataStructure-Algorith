#include<iostream>
using namespace std;

int main()
{
    char A[]= "How are you";
    int vcount = 0;
    int ccount = 0;
    for ( int i = 0 ; A[i] != '\0'; i ++ )
    {
        if (A[i] =='a'||A[i]=='e'||A[i]=='o'||A[i]=='u'||A[i]=='i'
            ||A[i] =='a'- 32||A[i]=='e' - 32||A[i]=='o' -32 ||A[i]=='u' - 32||A[i]=='i' - 32)
        {
            vcount ++;
            cout<<"***"<<endl;
        }
        else
            ccount ++;
    }

    cout<<"The Vowel count is "<<vcount<<endl;
    cout<<"The Consonant count is "<<ccount<<endl;
}
