#include<iostream>
using namespace std;

void findDuplicateChar(char *str)
{
    int ht[26]= {0};
    for( int i = 0 ; str[i] != '\0';i++)
    {
        if ( str[i] <= 'Z' && str[i] >='A' )
            ht[str[i]-'A'] += 1;

        else if ( str[i] <= 'z' && str[i] >='a' )
            ht[str[i]-'a'] += 1;
    }

    for (int i = 0 ; i < 26 ; i++ )
    {
        if ( ht[i] > 1)
            cout<<"Duplicate Character : "<<char('A'+ht[i])<<" for "<<ht[i]<< "Times\n";
    }
}


int main()
{
    char str[] = "Dhjaofhaowifdhaoiwfdhawoi:famsoigsenoisnosa";
    findDuplicateChar(str);

}
