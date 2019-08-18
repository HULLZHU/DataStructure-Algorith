#include<iostream>
using namespace std;

struct Element
{
    int i,j,x;
};

struct SparseMatrix
{
    int m;
    int n;
    int num; //Number of Elements
    struct Element *e;//Dynamic Array
};

void create(SparseMatrix *s, int m, int n, int num)
{
    s ->m = m;//Assign Row Number
    s ->n = n;//Assign Column Number
    s ->num = num;//Assign non-zero element number 
    s ->e = new Element[num];
}

void print(SparseMatrix *s)
{
    int k = 0;
    for(int i = 1; i < s->m ; i++)
    {
        for(int j = 1  ; j < s->n; j++)
        {
            if( i== s->e[k].i && j == s->e[k].j)
                cout<<s->e[k++].x<<" "; 
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
}

struct SparseMatrix* add(struct SparseMatrix *s1, struct SparseMatrix *s2)
{
    struct SparseMatrix *sum;

    int i,j,k;
    i =j = k = 0;
  
    sum = new SparseMatrix;
    sum ->e = new Element[s1->num + s2->num];

      while( i < s1-> num && j < s2 -> num)
    {
        if(s1 ->e[i].i > s2 ->e[j].i)
            sum ->e[k++] = s1->e[i++];
        else if(s1 ->e[i].i < s2 ->e[j].i)
            sum -> e[k++] = s2 -> e[j++];
        else
        {
            if(s1 -> e[i].j < s2 ->e[j].j)
                sum -> e[k++] = s1 -> e[i++];
            else if(s1 -> e[i].j > s2 -> e[j].j)
                sum -> e[k++] = s2 ->e[j++];
            else
            {
                sum -> e[k] = s1 -> e[i];
                sum -> e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }

    for(; i < s1->num;i++)
        sum->e[k++] = s1->e[i];

    for(; j < s2->num;j++)
        sum->e[k++] = s2->e[j];
    
    //Set the size of the resulting matrix
    sum ->m = s1 ->m;
    sum ->n = s1 ->n;

    return sum;
}

int main()
{
    SparseMatrix sm;
    create(&sm,10,10,10);
    
    sm.e[0].i=1;
    sm.e[0].j=1;
    sm.e[0].x=10;

    sm.e[1].i=2;
    sm.e[1].j=2;
    sm.e[1].x=3;

    sm.e[2].i=3;
    sm.e[2].j=4;
    sm.e[2].x=9;

    sm.e[3].i=3;
    sm.e[3].j=5;
    sm.e[3].x=7;

    sm.e[4].i=4;
    sm.e[4].j=3;
    sm.e[4].x=8;

    sm.e[5].i=5;
    sm.e[5].j=7;
    sm.e[5].x=6;

    sm.e[6].i=7;
    sm.e[6].j=9;
    sm.e[6].x=10;

    sm.e[7].i=9;
    sm.e[7].j=6;
    sm.e[7].x=7;

    print(&sm);
    SparseMatrix *sm2 = add(&sm,&sm);
    print(sm2);
    print(&sm);
}