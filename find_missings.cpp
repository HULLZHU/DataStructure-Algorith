#include<iostream>
using namespace std;

//method 1: using the theoretical sum to minus real sum to get the missing number
void findMissingSingleElement1(int *array, int length)
{
    int minimum = array[0];
    int maximum = array[length-1];
    int theoretical_total = (minimum+maximum)*(length+1)/2;
    int real_total = 0;
    for ( int i = 0 ; i < length ; i++)
    {
        real_total += array[i];
        cout<<array[i]<<endl;
    }
    cout<<"Number "<<theoretical_total - real_total<<" missing\n";
}

void findMissingSingleElement2(int *array, int length)
{
    int diff = array[0];
    for ( int i = 1 ; i < length; i++)
    {
        cout<<array[i];
        if ( array[i] - i != diff)
        {
            cout<<"The number "<<i+diff<<" is missing"<<endl;
            diff ++;
        }
    }
}

int main()
{
    int a[8]={2,3,4,5,6,7,8,10};
    findMissingSingleElement1(a,8);
    findMissingSingleElement2(a,8);
}
