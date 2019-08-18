#include <iostream>
using namespace std;

class Array
{

private:
    int *A;//Pointer
    int size;
    int length;
    void Swap(int *x, int *y);
public:
    //Default Constructor
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    //Constructor
    Array(int sz)
    {
        size= sz;
        length = 0;
        A = new int[size];
    }
    //Destructor
    ~Array()
    {
        delete []A;//Delete Dynamic Memory
    }

    //methods declaration
    void append(int x);
    void insert(int index, int i);
    int Remove(int index);//Remove the value with the specified index, and then return the value
    //void Swap(int *x, int *y);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int get(int index);
    int set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();//Reverse by converge
    void Reverse2();//Reverse by swap
    bool InsertSort(int x);//Insert a number into a sorted array
    bool isSorted(bool);//Return the index which conflict
    void Rearrange();
    Array *Merge(Array &arr2);
    Array *Union(Array &arr2);
    Array *Diff(Array &arr2);
    Array *Inter(Array &arr2);
    //Access Private Attributes
    int length(){return length;};
    int index(int idx){return A[idx];};
    int size(){return size;};

    //Friend Functions which can directly access the private members of a class
    friend ostream& operator<<(ostream &os,Array &arr);
};

void Array::append(int x)
{
    if ( length < size)
        A[length ++ ]=x;
}

void Array::insert(int index, int x)
{
    int i;
    if ( index >= 0 && index <= length)
    {
        for ( i = length; i > index; i--)
            A[i] = A[i-1]; //Move the left number to the right number's position
        A[index] = x;
        length ++;
    }
}

int Array::Remove(int index)
{
    int x = 0;
    int i;

    if ( index >= 0 && index < length )
    {
        x = A[index];// Assign the value at the indexed position
        for ( i = index; i < length - 1; i++) //Move right to left
            A[i] = A[i+1];
        length --;
        return x; // return the assigned value
    }
    return 0;
}

void Array::Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int Array::LinearSearch(int key)
{
    int i;
    for ( i = 0; i < length ; i++)
    {
        if ( key == A[i])
        {
            Swap(&A[i],&A[0]);
            return i;
        }
    }
    return -1;
}

int Array::BinarySearch(int key)
{
    int l = 0, h = length -1, mid;

    while( l <= h)
    {
        mid = (l+h)/2;
        if ( key == A[mid])
            return mid;
        else if(key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int Array::get(int index)
{
    if (index >= 0 && index < length)
        return A[index];
    return -1;
}

int Array::set(int index, int x)
{
    if ( index >= 0 && index < length )
        return A[index];
    return -1;
}

int Array::Max()
{
    int max = A[0];
    int i;
    for ( i = 1; i < length; i ++)
    {
        if( A[i] > max)
            max = A[i];
    }
    return max;
}

int Array::Min()
{
    int min = A[0];
    int i;
    for ( i = 1; i < length ; i ++)
    {

        if( A[i] < min )
            min = A[i];
    }

    return min;
}

int Array::Sum()
{
    int s = 0;
    int i;
    for ( i = 0 ; i < length; i ++ )
        s+=A[i];
    return s;
}

float Array::Avg()
{
    return (float)Sum()/length;
}

void Array::Reverse()
{
    int *B;
    int i,j;

    B = new int[length];
    for (i=length-1,j=0;i>0;i--,j ++)
        B[j] = A[i];

    delete []A;//delete the pointed memory
    A = B;//switch pointer to new memory
}


void Array::Reverse2()
{

    int i,j;
    for ( i = 0 , j = length - 1; i < j;i++, j--)
    {
        Swap(&A[i],&A[j]);
    }
}

bool Array::InsertSort(int x) //O(n)
{
    int i = length - 1;
    if ( length == size )
        return false;//return nothing to terminate the block

    while ( i>= 0 && A[i] > x)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length ++;
    return true;
}

//check if it is a sorted array
bool Array::isSorted(bool checkAscendant)
{
    int i;
    if ( checkAscendant )//check if it is ascendant
    {
        for( i = 0 ; i < length ; i++)
        {
            if ( A[i] > A[i+1] )
                return false;
        }
    }
    else
    {
        for( i = 0 ; i < length ; i++) //check if it descendant
        {
            if ( A[i] < A[i+1] )
                return false;
        }
    }

    return true;
}

//Rearrange
void Array::Rearrange() //Move negative to left, move positive to right
{
    int i = 0 ,j = length - 1;

    while ( i < j )
    {
        while (A[i] < 0 )i++;
        while (A[j] < 0 )j--;
        if ( i < j)
            Swap(&A[i],&A[j]);
    }
}

//Merge
Array* Array::Merge(Array &arr2)
{
    int i,j,k;
    i = j = k = 0;

    //create a new array which will be returned as a result
    Array *arr3 = new Array(length+arr2.length());
    while ( i < length && j < arr2.length())
    {
        if ( A[i] < arr2.index(j)
            arr3 -> A[k++] = A[i++];
        else
            arr3 -> A[k++] = arr2.index(j++);
    }

    for ( ; i < length;i++)
        arr3 -> A[k++] = A[i];

    for ( ; j < arr2.length();i++)
        arr3 -> A[k++] = arr2.index(j);

    arr3 -> length = length + arr2.length();
    return arr3;
}

//Union
Array* Array::Union(Array &arr2)//Get the union of 2 sorted array
{
    int i=0,j=0,k=0;

    Array *arr3 = new Array(length + arr2.length());

    while ( i < length && j < arr2.length())
    {
        if (A[i] < arr2.index(j))
            arr3 -> A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            arr3 -> A[k++] = arr2.index(j++);
        else
        {
            arr3 -> A[k++] = A[i++];
            j++;
        }
    }

    for ( ; i < length;i++)
        arr3 -> A[k++] = A[i];

    for ( ; j < arr2.length();i++)
        arr3 -> A[k++] = arr2.index(j++);

    arr3 -> length = length + arr2.length();
    return arr3;
}

Array* Array::Inter(Array &arr2)
{
    int i=0,j=0,k=0;
    Array *arr3 = new Array(length+arr2.length());
    while ( i < length && j< arr2.length())
    {
        if (A[i] < arr2.index(j)
            i++;
        else if (arr2.index(j) < A[i])
            j ++;
        else
        {
            arr3 -> A[k++] = A[i++];
            j++;
        }
    }
    return arr3;
}

Array* Array::Diff(Array &arr2)
{
    int i=0,j=0,k=0;

    Array *arr3 = new Array(length + arr2.length());

    while ( i < length && j < arr2.length())
    {
        if (A[i] < arr2.index(j))
            arr3 ->A[k++] = A[i++];
        else if(arr2.index(j) < A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];
    arr3->length = k;
    return arr3;
}

/* cout<< Array overloading*/
ostream& operator<<(ostream &os, Array &arr)
{
    for ( int i = 0; i < arr.length();i++ )
        os<<arr.A[i]<<",";
    return os;
}

int main()
{
    //Create 2 Array Objects
    Array *arr1 = new Array();
    Array *arr2 = new Array();

    //Appending values
    arr1->append(1);
    arr1->append(2);
    arr1->append(3);
    arr1->append(4);
    arr1->append(5);
    arr1->append(6);


    arr2->append(2);
    arr2->append(4);
    arr2->append(5);
    arr2->append(7);
    arr2->append(9);

    cout<<*arr1<<endl;
    cout<<*arr2<<endl;

    return 0;
}
