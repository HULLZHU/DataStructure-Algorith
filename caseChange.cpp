#include<iostream>
using namespace std;

char* changeCase(char *str)
{
    for ( int i = 0 ; str[i] != '\0'; i++)
    {
        if ( str[i] <='Z' &&str[i]>='A')
            str[i] = str[i] + 32;
        else if(str[i] >='a' && str[i] <= 'z')
            str[i] = str[i] -32;
    }
    return str;
}

int main()
{
    char str[] = "apple I love My Apple";
    char *p_str = changeCase(str);
    cout<<p_str<<endl;
}
