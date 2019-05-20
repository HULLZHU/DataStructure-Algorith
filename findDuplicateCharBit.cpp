#include<iostream>
using namespace std;

int main()
{
    char str[] = "finding";
    long int H =0;
    long int x = 0;
    for ( int i = 0 ; str[i]!='\0'; i ++ )
    {
        x = 1;
        x = x<<(str[i] - 'a');
        cout<<str[i] - 'a'<<endl;
        if ( H & x > 0){
            cout<<str[i]<<" is duplicate"<<endl;
        }
        else{
            H = H|x;
        }

    }


}
