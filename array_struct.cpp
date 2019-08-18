#include<iostream>
#include<stdio.h>
using namespace std;

struct Array
{
    int *array;
    int size;
    int length=0;

    /*print*/
    void display()
    {
        for ( int i = 0; i < length ; i ++)
            printf("%d;",array[i]);
    }

    /*Methods*/
    int get(int index)const
    {
        if ( index >= 0 && index < length)
            return array[index];
        return -1;
    }

    //Set Method
    bool set(int index, int value)
    {
        if (index >= 0 && index < length)
        {
            array[index] = value;
            return true;
        }
        return false;
    }

    //get Max element
    int Max()
    {
        int max = array[0];
        for ( int i = 0 ; i <length; i ++)
        {

            if ( array[i] > max)
                max = array[i];
        }
        return max;
    }

    //get Min element
    int Min()
    {
        int min = array[0];
        for ( int i = 0 ; i <length; i ++)
        {
            if ( array[i] < min)
                min = array[i];
        }
        return min;
    }

    //get the sum of array
    int sum()
    {
        int s = 0;
        int i;
        for ( int i = 0 ; i <length ; i ++ )
            s += array[i];

        return s;
    }

    int sum_recursive( int n = -2)
    {
        if ( n == -2)
            return sum_recursive(length);

        if ( n <0 )
            return 0;
        else
            return array[n] + sum_recursive(n-1);

    }
    //reverse by creating new array
    void reverse_cp()//Reverse the Array by copying
    {
        int *new_array = new int[length];
        for ( int i = length - 1, j = 0 ; i >= 0 ; i --,j ++ )
            new_array[j] = array[i];

        delete []array; // delete the originally pointed memory space
        array = new_array;// array now points to
        new_array = nullptr;
    }
    //reverse by swapping
    void reverse_s()//Reverse the Array by swap
    {
        for ( int low=0, high = length-1; low < high; low ++, high --)
        {

            int temp = array[low];
            array[low] = array[high];
            array[high] = temp;
        }
    }

    // left shift
    bool left_shift(int position)
    {
        if( position <= length)
        {

            for ( int  i = 0 ; i < length ; i++)
            {
                if( i + position >= length)
                    array[i] = 0;
                else
                    array[i] = array[i + position];
            }
            return true;
        }
        return false;
    }

    //right shift
    bool right_shift(int position)
    {
        if(position <= length)
        {
            for (int i = length -1; i >= 0 ; i -- )
            {
                if ( i -position < 0)
                    array[i] = 0;
                else
                    array[i] = array[i-position];
            }
            return true;
        }
        return false;
    }

    //is sorted or not
    bool isSorted() //O(n)
    {
        for ( int i = 1 ; i < length; i ++)
        {
            if(array[i-1]>array[i])
                return false;
        }
        return true;
    }

    //insertion for sorted array
    bool insert(int value) //O(n)
    {
        if(isSorted())
        {
            int i = 0;
            for (  i = length -1; array[i]>value  && i >=0 ; i--)
                array[i+1] = array[i];
            array[i+1] = value;
            length++;
            return true;
        }
        return false;
    }

    //compute average
    double average()//O(n)
    {
        return (double)sum()/length;
    }

    //append new element at tail, push_back()
    void append(int x) //O(1)
    {
        array[length] = x;
        length ++;
    }

    bool insert(int index, int value)
    {
        if(index >= 0 && index < length)
        {

            for ( int i = length; i > index; i--)
                array[i] = array[i-1];
            array[index] = value;
            length ++;
            return true;
        }
        return false;
    }

    bool remove(int index)
    {
        if ( index >= 0 && index < length)
        {
            for ( int i = index ; i < length ; i ++ )
                array[i] = array[i+1]; //shift right elements to left
            length -- ;
            return true;
        }
        return false;
    }

    void cluster()
    {

        for( int i =0, j = length - 1; i < j ;)
        {

            while(array[i] < 0 )
                i++;
            while(array[j] >0 )
                j--;
            if ( i < j)
                swap(i,j);
        }
    }

    int search_linear(int key)
    {
        for ( int i = 0; i < length; i ++ )
        {

            if ( key == array[i])
                return i;
        }
        return -1;
    }

    int search_binary(int key)
    {
        int l =0, h = length-1;
        while (l <= h)
        {
            int mid = (l+h)/2;
            if ( array[mid] == key)
                return mid;
            else if(array[mid]>key)
                h = mid - 1;
            else if(array[mid]<key)
                l = mid + 1;
        }
        return -1;
    }

    int search_binary_recursive(int key, int l = 0, int h = -1)
    {
        //switch the argument
        if ( h == -1)
            return search_binary_recursive(key,l,length-1);

        if ( l <= h)
        {
            int mid = (l+h)/2;
            if( key == array[mid])
                return mid;
            else if( key < array[mid])
                return search_binary_recursive(key,l,mid-1);
            else
                return search_binary_recursive(key,mid+1,h);
        }

        return -1;
    }

    int search_transposition(int key)
    {

        for ( int i = 0 ; i < length ; i ++ )
        {

            if ( array[i] == key)
            {
                if ( i > 0)
                {
                    swap(i,i-1);//Every time the key is searched, move it more front
                    return i -1;
                }
                else
                    return i;
            }
        }
        return -1;
    }

    void swap(int i, int j)
    {

        if ( i >= 0 && j >= 0 && i < length && j < length)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    Array merge(Array array2)
    {
        //create a new Array pointer
        Array merged_array;
        merged_array.size = size + array2.size;//define the size
        int *a = new int[merged_array.size];//define the embedded array
        merged_array.array = a;
        merged_array.length = 0;

        int i = 0, j = 0, k = 0;
        while ( i < length  && j < array2.length)
        {
            if ( array[i] < array2.array[j])
            {
                merged_array.array[k] = array[i];
                merged_array.length++;
                i ++;
            }

            else
            {
                merged_array.array[k] = array2.array[j];
                merged_array.length++;
                j ++;
            }
            k++;
        }

        //append those are not merged
        for ( ;i < length; i ++ )
            merged_array.append(array[i]);

        for ( ;j < array2.length; j ++ )
            merged_array.append(array2.array[j]);

        return merged_array;
    }

    Array Union_unsorted(Array& array2)
    {//We cannot return a reference of local variable
     //Because local variable will be destroyed as the called function terminates
        Array result;
        result.size = size + array2.size;
        int *a = new int[size];
        result.array = a;

        //first copy the first array onto the new array
        for(int i = 0 ; i < length; i++ )
            result.append(array[i]);

        for (int i = 0 ; i <  array2.length;i++)
        {
            bool has_same = false;
            for (int j = 0 ; j < result.length;j++)
            {
                if (array2.array[i] == array[j])
                {
                    has_same = true;
                    break;
                }
            }
            if ( has_same)
                    continue;
                else
                    result.append(array2.array[i]);
        }
        return result;
    }

    Array Union_sorted(Array &array2)
    {
        Array result;
        result.size = size + array2.size;
        int *a = new int[size];
        result.array = a;

        int i = 0, j = 0;
        while ( i < length && j < array2.length)
        {
            if(array[i] == array2.array[j])
            {
                result.append(array[i]);
                i++;
                j++;
            }
            else if ( array[i] < array2.array[j])
            {
                result.append(array[i]);
                i ++;
            }
            else
            {
                result.append(array2.array[j]);
                j++;
            }
        }

        for ( ; i < length;i++)
            result.append(array[i]);

        for( ; j< array2.length; j++)
            result.append(array2.array[j]);

        return result;
    }

    Array Difference_unsorted(Array &array2)
    {
        //create the target Array object
        Array result;
        result.size = size + array2.size;
        int *a = new int[size];
        result.array = a;
        //First Copy the first Array onto target Array

        for ( int i =0; i < length ; i ++ )
        {
            bool has_same = false;
            int j = 0;
            for (; j < length ; j ++ )
            {
                if(array[i] == array2.array[j])
                {
                    has_same = true;
                    break;
                }
            }
            if ( !has_same)
            {
                result.append(array[i]);
            }
        }

        return result;



    }

    Array Difference_sorted(Array &array2)
    {
        //create the target Array object
        Array result;
        result.size = size + array2.size;
        int *a = new int[size];
        result.array = a;

        int i = 0, j = 0 ;
        while ( i < length && j < array2.length)
        {
            if (array[i] < array2.array[j])
            {
                result.append(array[i]);
                i++;
            }
            else if ( array[i] > array2.array[j])
            {
                result.append(array2.array[j]);
                j ++;
            }
            else
            {
                i ++;
                j ++;
            }
        }

        for ( ; i < length;i++)
            result.append(array[i]);

        for( ; j< array2.length; j++)
            result.append(array2.array[j]);

        return result;
    }

    Array Intersection_sorted(Array &array2)
    {
        //create the target Array object
        Array result;
        result.size = size + array2.size;
        int *a = new int[size];
        result.array = a;

        int i = 0, j = 0;
        while ( i < length && j < array2.length)
        {
            if( array[i] < array2.array[j])
                i++;
            else if( array[i] > array2.array[j])
                j++;
            else
            {
                result.append(array[i]);
                i++;
                j++;
            }
        }
        return result;
    }

    Array Intersection_unsorted(Array &array2)
    {
        //create the target Array object
        Array result;
        result.size = size + array2.size;
        int *a = new int[size];
        result.array = a;

        for (int i = 0 ; i < length ; i++)
        {
            for ( int j = 0 ; j < array2.length ; j ++ )
            {
                if ( array[i] == array2.array[j])
                {
                    result.append(array[i]);
                    break;
                }
            }
        }
        return result;
    }
};

/* cout<< overloading*/
ostream& operator<<(ostream &os, const Array &arr)
{
    for ( int i = 0; i < arr.length;i++ )
        os<<arr.array[i]<<";";
    return os;
}


int main()
{
    struct Array myarr;
    myarr.array = new int[10];
    myarr.size = 10;
    myarr.length = 0;

    myarr.append(10);
    myarr.append(11);
    myarr.append(12);
    myarr.append(13);
    myarr.append(14);

    myarr.insert(3,999);
    myarr.insert(4,999);
    myarr.display();

    cout<<endl;
    cout<<"Position"<<myarr.search_linear(14)<<endl;
    cout<<"Position"<<myarr.search_transposition(14)<<endl;
    cout<<"Position"<<myarr.search_transposition(14)<<endl;
    cout<<"Position"<<myarr.search_transposition(14)<<endl;
    cout<<"Position"<<myarr.search_transposition(14)<<endl;
    cout<<"Position"<<myarr.search_transposition(14)<<endl;
    cout<<"Position"<<myarr.search_transposition(14)<<endl;
    cout<<"Position"<<myarr.search_transposition(14)<<endl;
    cout<<"Position"<<myarr.search_transposition(14)<<endl;
    cout<<"Position"<<myarr.search_transposition(14)<<endl;
    cout<<"Position"<<myarr.search_transposition(14)<<endl;


    struct Array myarr2;
    myarr2.array = new int[10];
    myarr2.size = 10;
    myarr2.length = 0;

    myarr2.append(10);
    myarr2.append(11);
    myarr2.append(12);
    myarr2.append(13);
    myarr2.append(14);

    myarr2.insert(3,999);
    myarr2.insert(4,999);
    myarr2.remove(0);
    myarr2.remove(3);
    myarr2.remove(5);
    myarr2.display();

    cout<<endl;
    cout<<myarr2.search_binary(999)<<endl;
    cout<<myarr2<<endl;
    cout<<myarr2.sum()<<endl;
    cout<<myarr2.average()<<endl;
    cout<<myarr2.Max()<<endl;
    cout<<myarr2.Min()<<endl;

    myarr2.reverse_cp();
    cout<<myarr2<<endl;

    myarr2.reverse_s();
    cout<<myarr2<<endl;

    myarr2.left_shift(2);
    cout<<myarr2<<endl;

    myarr2.right_shift(1);
    cout<<myarr2<<endl;

    struct Array arr3;
    arr3.size = 20;
    arr3.length = 0;
    arr3.append(1);
    arr3.append(-1);
    arr3.append(-3);
    arr3.append(3);
    arr3.append(-10);
    arr3.append(5);
    arr3.append(7);
    arr3.append(9);
    arr3.append(-10);
    arr3.append(11);
    arr3.append(13);
    arr3.append(-12);
    arr3.append(15);
    arr3.cluster();
    cout<<arr3<<endl;

    /*Test merge method*/
    Array a1;
    a1.size = 10;
    a1.array = new int[10];
    a1.append(-3);
    a1.append(-2);
    a1.append(3);
    a1.append(6);
    a1.append(10);

    Array a2;
    a2.size =10;
    a2.array = new int[10];
    a2.append(-4);
    a2.append(1);
    a2.append(5);
    a2.append(7);
    a2.append(8);

    struct Array merged_array = a1.merge(a2);
    cout<<merged_array<<endl;

    Array u_arr1 = a2.Union_unsorted(a1);
    cout<<u_arr1<<endl;

    Array a3;
    a3.size =10;
    a3.array = new int[10];
    a3.append(-4);
    a3.append(1);
    a3.append(5);
    a3.append(7);
    a3.append(8);
    a3.append(9);

    Array a4;
    a4.size =10;
    a4.array = new int[10];
    a4.append(-3);
    a4.append(-2);
    a4.append(5);
    a4.append(6);
    a4.append(9);


    Array u_arr2 = a3.Union_sorted(a4);
    cout<<u_arr2<<endl;

    Array d_arr1 = a3.Difference_unsorted(a4);
    cout<<d_arr1<<endl;

    Array d_arr2 = a3.Difference_sorted(a4);
    cout<<d_arr2<<endl;

    Array i_arr2 = a3.Intersection_sorted(a4);
    cout<<"Intersection"<<i_arr2<<endl;

    Array i_arr1 = a3.Intersection_unsorted(a4);
    cout<<"Intersection"<<i_arr1<<endl;
}
