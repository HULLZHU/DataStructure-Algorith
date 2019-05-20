#include <iostream>
using namespace std;

void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *str, int l, int r)
{
    int i;
    if ( l == r)
        cout<<str<<endl;
    else
    {
        for( i = l ; i <= r; i ++ )
        {
            swap(str[l],str[i]);
            permute(str,l+1,r);
            swap(str[l],str[i]);
        }
    }
}

int main()
{
    char str[] = "Hellobaby";
    permute(str,0,8);

}
