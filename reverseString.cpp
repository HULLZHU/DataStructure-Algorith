#include<iostream>
using namespace std;

char* reverseString1(char *str)
{
    char *str2 = new char[30];
    int j;
    int i;

    for ( i = 0 ; str[i] != '\0' ; i++){}
    i = i - 1;//Very important

    for ( j = 0 ; i >= 0; j++,i--)
        str2[j] = str[i];

    str2[j] = '\0';
    return str2;
}

void reverseString2(char *str)
{
    int i ;
    int j ;
    for (i = 0 ; str[i] != '\0'; i ++ ){}
    i--;

    for ( j = 0 ; j < i ; j++,i--)
    {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
}

int main()
{
    char str[] = "Python";
    char *s = reverseString1(str);
    cout<<s<<endl;

    char str2[] = "Java";
    reverseString2(str2);
    cout<<str2<<endl;
}
