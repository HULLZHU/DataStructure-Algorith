#include <iostream>
using namespace std;

void swap(char &a, char &b)
{
    char temp;
    temp = a;
    a = b;
    b = temp;
}

//length: length of string
void perm(char s[], int begin, int length)
{
    int current;
    if( begin == length)
        cout<<s<<endl;
    else
    {
        for( current = begin; current < length; current ++)
        {
            swap(s[begin], s[current]);
            perm(s,begin+1,length);
            swap(s[begin],s[current]);
        }
    }
}

int main()
{
    char A[] = "ABCD";
    perm(A,0,4);
}
