#include <iostream>
using namespace std;

int main()
{
    int *A,n,x,ch=1;
    cout<<("Enter Dimension");
    cin>>n;
    //Create an array
    A = new int[n];

    int i,j;

    do
    {
        switch(ch)
        {
        case 1:
            cout<<"Enter Elements"<<endl;
            for ( i = 1; i <= n;i++)
                cin>>A[i-1];
            break;

        case 2:
            cout<<"Enter indices"<<endl;
            cin >>i;
            cin >>j;
            if ( i == j)
                cout<<A[i-1]<<endl;
            else
                cout<<0<<endl;
            break;

        case 3:
            cout<<"Enter i,j,element\n";
            cin>>i;
            cin>>j;
            cin>>x;
            if ( i == j)
                A[i-1]=x;
            break;
        case 4:
            for ( i = 0 ;i < n ; i ++ )
            {
                for ( j = 0; j < n;j++)
                {
                    if ( i == j)
                        cout<<A[i]<<", ";
                    else
                        cout<<0<<", ";
                    if ( j == n - 1 )
                        cout<<endl;
                }
            }
            break;
        }
        cout<<"Enter your Option"<<endl;
    }
    while ( cin >> ch);


}
