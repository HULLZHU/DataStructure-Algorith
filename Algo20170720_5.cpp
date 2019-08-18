/*Find sum pair of K; Hash Method*/
#include<iostream>
using namespace std;

int main()
{
    int sum = 10;
    int A[10] = {6,3,8,10,16,7,5,2,9,14};
    int HT[16] = {0};

   for ( int i = 0 ; i < 10 ; i ++ )
   {
       int sumMinusElement = sum - A[i];

       if(sumMinusElement > 0)
        {
            if(HT[sumMinusElement] != 0)
            cout<<"Pair: "<<A[i] <<" and "<<sumMinusElement<<endl;
        }

       HT[A[i]] = 1;
   }
}
