#include"BinaryTree.h"
#include<iostream>
using namespace std;

int main()
{
    double array[]={1,2,3,4,5,6,7,8,9,10};
    BinaryTree<double> *tree = new BinaryTree<double>(100, array,10);
    
    cout<<"Pre: ";
    tree->preorder();
    cout<<endl;

    cout<<"Post: ";
    tree->postorder();
    cout<<endl;

    cout<<"In: ";
    tree->inorder();
    cout<<endl;

    cout<<"Pre: ";
    tree->preorder();
    cout<<endl;

    cout<<"In: ";
    tree->itinorder();
    cout<<endl;

    cout<<"Post:";
    tree->postorder();
    cout<<endl;

    cout<<"Level:";
    tree->levelorder();
    cout<<endl;

    cout<<"Height:";
    cout<<tree->height();
    cout<<endl;

    cout<<"Count:";
    cout<<tree->count();
    cout<<endl;

    cout<<"Sum: ";
    cout<<tree->sum();
    cout<<endl;

    Node<double> *s1 = tree->search(9);
    cout<<"@Iterative Search: "<<s1<<"Value: "<<s1->data<<endl; 


}