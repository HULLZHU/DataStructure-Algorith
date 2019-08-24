#include"Queue.h"
using namespace std;

int main()
{
    Node<char> *root = new Node<char>;
    root->data = 'A';

    Node<char> *right = new Node<char>;
    right->data= 'B';

    Node<char> *left = new Node<char>;
    left->data = 'C';

    root->rchild = right;
    root->lchild = left;

    right->lchild=right->rchild = NULL;
    left->lchild= left->rchild = NULL;

    char temp1 = root->lchild->data;
    cout<<temp1;
}