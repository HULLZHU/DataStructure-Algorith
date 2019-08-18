#include<iostream>
using namespace std;

int main()
{
    char str[] = "finding";
    long int HT = 0;
    long int x = 0;

    for(int i = 0 ; str[i] != '\0' ; i ++ )
    {
        x = 1;
        x = x<<(str[i] - 'a');
        if (HT & x)
            cout<<str[i]<<" is a duplicate number in the string"<<endl;
        else
            HT = HT | x;
    }
}
