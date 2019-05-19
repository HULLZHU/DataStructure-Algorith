#include <iostream>
using namespace std;

bool checkPalindrome(char  *str)
{
    int length = 0;
    for (; str[length] != '\0'; length ++){}

    length --;
    for (int i = 0; i < length ; length --, i++)
    {
        if ( str[i] != str[length])
            return false;
    }

    return true;

}

int main()
{
    char str[] = "madam";
    char str2[] = "AppleppA";
    cout<<checkPalindrome(str)<<endl;
    cout<<checkPalindrome(str2)<<endl;


}
