#include"BinaryTree.h"
#include<iostream>
using namespace std;

int main()
{
    double array[]={10,20,30,40,50,60};
    BinaryTree<double> *tree = new BinaryTree<double>(100, array,10);
    tree->initRoot(9);
    tree->insert(8);
    tree->insert(7);
    tree->insert(10);
    tree->insert(11);
    tree->insert(12);
    tree->insert(3);
    tree->insert(6);
    tree->insert(4);
    tree->insert(16);

    tree->preorder();

    cout<<endl;

    /*Test search*/
    cout<<"Test Iterative Search"<<endl;
    Node<double> *s1 = tree->search(9);
    cout<<"@Iterative Search: "<<s1<<"Value: "<<s1->data<<endl;
    s1 = tree->search(12);
    cout<<"@Iterative Search: "<<s1<<"Value: "<<s1->data<<endl; 
    s1 = tree->search(16);
    cout<<"@Iterative Search: "<<s1<<"Value: "<<s1->data<<endl; 
    s1 = tree->search(9);
    cout<<"@Iterative Search: "<<s1<<"Value: "<<s1->data<<endl;  

    cout<<"Test Recursive Search"<<endl;
    /*Test recursive search*/
    s1 = tree->Rsearch(10);
    cout<<"@Iterative Search: "<<s1<<"Value: "<<s1->data<<endl; 
     cout<<"@Iterative Search: "<<s1<<"Value: "<<s1->data<<endl;
    s1 = tree->Rsearch(12);
    cout<<"@Iterative Search: "<<s1<<"Value: "<<s1->data<<endl; 
    s1 = tree->Rsearch(16);
    cout<<"@Iterative Search: "<<s1<<"Value: "<<s1->data<<endl; 
    s1 = tree->Rsearch(9);
    cout<<"@Iterative Search: "<<s1<<"Value: "<<s1->data<<endl; 


    /*Test recursive insert*/
    cout<<"Test recursive insert"<<endl;
    tree->initRoot(9);
    tree->Rinsert(8);
    tree->Rinsert(7);
    tree->Rinsert(10);
    tree->Rinsert(11);
    tree->Rinsert(12);
    tree->Rinsert(3);
    tree->Rinsert(6);
    tree->Rinsert(4);
    tree->Rinsert(16);

    tree->preorder();

    cout<<endl;

    /*Test search*/
    cout<<"Test Iterative Search"<<endl;    
    s1 = tree->search(9);
    cout<<"@Iterative Search: "<<s1<<"Value: "<<s1->data<<endl;
    s1 = tree->search(12);
    cout<<"@Iterative Search: "<<s1<<"Value: "<<s1->data<<endl; 
    s1 = tree->search(16);
    cout<<"@Iterative Search: "<<s1<<"Value: "<<s1->data<<endl; 
    s1 = tree->search(9);
    cout<<"@Iterative Search: "<<s1<<"Value: "<<s1->data<<endl;   

    double array2[]={30,20,10,15,25,40,50,45};
    tree = new BinaryTree<double>(100, array2,8);
    tree->createPreBST(array2,8);
    cout<<endl;
    cout<<"Print"<<endl;
    tree->preorder();


}