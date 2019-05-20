#include<iostream>
using namespace std;

int main()
{
    char str1[] = "decimal";
    char str2[] = "medical";
    char H[25]={0};

    bool isAnagram = true;

    for( int i = 0 ; str1[i] != '\0'; i++ )
        H[str1[i] -'a']+=1;

    for ( int i = 0 ; str2[i] !='\0'; i ++)
        H[str2[i]-'a'] -= 1;

    for ( int i = 0 ; i < 25; i ++ )
    {
        if(H[i] != 0)
        {
            isAnagram = false;
            break;
        }
    }

    cout<<isAnagram<<endl;




}
