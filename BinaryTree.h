// (1)2019/08/23：记得再实现一遍 Rinsert()和remove()的功能，以增强理解return到底是如何影响递归结果的
// (2)Rinsert() DONE! Remove() DONE!
// (3)createpreBST()还是没有搞明白，需要搞懂i你


#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include<iostream>
#include"Queue.h"
#include"Stack.h"
using namespace std;

template <class T>
class BinaryTree
{
/*Declaration: (1) This class initializes the tree by levels*/
/*Declaration: (2) This class provides 3 method to traverse the tree*/
private:
    int num_node;
    Node<T> *root;
    Queue<Node<T>*> *queue;//This queue is used as the cache to store the node
    T *values;
    void init_tree();//The method initialize by using the array values
    void preorder(Node<T>* p);
    void postorder(Node<T>* p);
    void inorder(Node<T>* p);
    int count(Node<T>*p);
    int height(Node<T>*p);
    T sum(Node<T>*p);
    Node<T>* Rsearch(Node<T>*p,T key);
    Node<T>* Rinsert(Node<T>*p, T key);
    void clear(Node<T>* p);
    Node<T>* remove(Node<T>*p ,T key);
    Node<T>* inPre(Node<T>* p);//get the inorder predecessor
    Node<T>* inSucc(Node<T> *p);//get the inorder successor
   

public:

    BinaryTree(){root = new Node<T>();queue = new Queue<Node<T>>();};//The default capacity of Queue is 10
    BinaryTree(int N){root = new Node<T>();queue = new Queue<Node<T>*>(N); };//Initialize the Queue with the capacity = N
    BinaryTree(int N, T *_values_, int _num_node){root = new Node<T>();queue = new Queue<Node<T>*>(N); values = _values_;num_node = _num_node;init_tree();}//Initialize the Queue with the capacity = N and set tree nodes
    
    //this function will transfer to 3 types of traversal function
    int Height(Node<T> *root);
    //recursive traversal
    void preorder();
    void postorder();
    void inorder();
    //iterative traversal
    void itpreorder();
    void itinorder();
    void itpostorder();
    //level order
    void levelorder();
    //count and height
    int count();
    int height();
    T sum();
    //initialize the tree
    void init_tree(T *_values_, int _num_node);
    //Binary Search Tree APIs
    Node<T>* search(T key);//iterative search
    Node<T>* Rsearch(T key);//recursive search
    void insert(T key);//Iterative insert
    Node<T>* Rinsert(T key);//Recursive insert
    Node<T>* remove(T key);
    void createPreBST(T *pre, int n);
    void initRoot(T key);
    /*CLEAR THE NODES*/
    void clear();

};

template<class T>
void BinaryTree<T>::createPreBST(T*pre, int n)
{
    num_node = n;
    Stack<Node<T>*> *st = new Stack<Node<T>*>(20);
    Node<T> *t;
    values = pre;
    int i = 0;
    initRoot(pre[i++]);
    Node<T>* p = root;
    while(i<n)
    {   
        if(pre[i]<p->data)
        {   
            t = new Node<T>;
            t->data = pre[i];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            st->push(p);
            p = t;
            i++;
        }
        else
        {   
            if(pre[i]>p->data && st->isEmpty())
            {   
                t = new Node<T>;
                t->data = pre[i++];
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                p = t;
            }
            else if(pre[i]>p->data && pre[i] < st->stacktop()->data)
            {   
                t = new Node<T>;
                t->data = pre[i++];
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                p = t;
            }
            else
            {   
                p = st->pop();//Move p to the previous node
            }
        }
    }
};

template<class T>
Node<T>* BinaryTree<T>::inPre(Node<T>* p)
{
    while(p && p->rchild != NULL)p = p->rchild;
    return p;
};

template<class T>
Node<T>* BinaryTree<T>::inSucc(Node<T> *p)
{
    while(p && p->lchild!=NULL)p = p->lchild;
    return p;
};

template<class T>
Node<T>* BinaryTree<T>::remove(T key)
{
    remove(root,key);
};

template<class T>
Node<T>* BinaryTree<T>::remove(Node<T>*p, T key)
{
    //临时节点q
    Node<T>*q;
    //若想删除的节点是空节点即没有找到符合的leaf，
    //返回NULL
    if(p == NULL)
        return NULL;
    //若想删除的节点是一个degree = 0的节点，则直接删除该节点，不做任何
    //其他操作
    if(p->lchild==NULL && p->rchild == NULL)
    {
        if(p == root)root=NULL;
        delete p;
        return NULL;
    }

    //若想删除的key小于目前所在的node，则递归至下一个左节点
    if(key < p->data)
        p->lchild = remove(p->lchild,key);
    //若想删除的key大于目前所在的node，则递归至下一个右节点
    else if(key > p->data)
        p->rchild = remove(p->rchild,key);
    else
    {   //通过比较左树与右数的高度来决定用predecessor还是
        //successor
        if(height(p->lchild)> height(p->rchild))
        {   //用q来承接
            q = inPre(p->lchild);
            p->data = q->data;
            p->lchild = remove(p->lchild,q->data);
        }
        else
        {
            q = inSucc(p->rchild);
            p->data = q->data;
            p->rchild = remove(q->rchild, q->data);
        }
    }
    return p;
};

template<class T>
void BinaryTree<T>::clear(Node<T>*p)
{
    if(p)
    {
        clear(p->lchild);
        clear(p->rchild);
        delete p;
    }
}

template<class T>
void BinaryTree<T>::clear()
{
    Node<T> *p = root;
    clear(p);
    cout<<"THE TREE IS TOTALLY CLEARED\n";
};
template<class T>
void BinaryTree<T>::initRoot(T v)
{   
    if(root)clear();
    root = new Node<T>;
    root->data = v;
    root->lchild=NULL;
    root->rchild=NULL;
    cout<<"THE TREE IS INITIALIZED WITH VALUE "<<v<<endl;

};

template<class T>//Remember!!!: This API is only valid for BST Tree
Node<T>* BinaryTree<T>::search(T key)
{
    Node<T>* p = root;
    while(p)
    {
        if(p->data == key)return p;
        else if( key < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return NULL;
};

template<class T>//Recursive search in BST
Node<T>* BinaryTree<T>::Rsearch(T key)
{
    Node<T>*p = root;
    return Rsearch(p, key);
};

template<class T>
Node<T>* BinaryTree<T>::Rsearch(Node<T>*p, T key)
{
    if(p == NULL){cout<<"NOT FOUND\n";return NULL;}
    if(key == p->data)return p;
    else if(key < p->data)return Rsearch(p->lchild,key);
    else return Rsearch(p->rchild,key); 
}

template<class T>
void BinaryTree<T>::insert(T key)
{
    if(!root)cout<<"Please set a root first";
    Node<T> *p = root;
    Node<T> * r;
    while(p)
    {
        if(key == p -> data)
        {
            cout<<"You are allowed to insert a duplicate value in BST\n";
            return;
        }
        else if( key < p-> data )
        {   
            r = p;
            p = p->lchild;
        }
        else
        {
            r = p;
            p = p->rchild;
        }
    }
    p = new Node<T>;
    p->data = key;
    p ->lchild = p -> rchild = NULL;
    //connect
    if(key < r->data)r->lchild = p;
    else r->rchild = p;
};

template<class T>
Node<T>* BinaryTree<T>::Rinsert(T key)
{
    return Rinsert(root, key);
};

template<class T>
Node<T>* BinaryTree<T>::Rinsert(Node<T>*p, T key)
{   
    Node<T> *t = new Node<T>;
    if(p == NULL)
    {
        
        t->data = key;
        t->lchild = NULL;
        t->rchild = NULL;
        return t;
    }
    else
    {
        if(key < p->data)p->lchild = Rinsert(p->lchild,key);
        else if(key > p->data)p->rchild = Rinsert(p->rchild,key);
    }
    return p;
};

template<class T>
int BinaryTree<T>::count()
{
    return count(root);
};

template<class T>
int BinaryTree<T>::count(Node<T> *p)
{
    if(p)
    {
        int lcount = count(p->lchild);
        int rcount = count(p->rchild);
        return lcount + rcount + 1;
    }
    return 0;
};

template<class T>
int BinaryTree<T>::height()
{
    return height(root);
};

template<class T>
int BinaryTree<T>::height(Node<T>* p)
{
    int lheight =0, rheight = 0;
    if(p)
    {
        lheight = height(p->lchild);
        rheight = height(p->rchild);
        if(lheight > rheight)
            return lheight + 1;
        else
            return rheight + 1;
    }
    return 0;
};

template<class T>
T BinaryTree<T>::sum()
{
    return sum(root);
}

template<class T>
T BinaryTree<T>::sum(Node<T> *p)
{
    int lsum,rsum;
    if(p != NULL)
    {
        lsum = sum(p->lchild);
        rsum = sum(p->rchild);
        return lsum+rsum+p->data;
    }
    return 0;
};

template<class T>
void BinaryTree<T>::levelorder()
{
    Queue<Node<T>*>* q = new Queue<Node<T>*>(30);
    Node<T>* p =root;
    cout<<p->data<<", ";
    q -> enqueue(p);
    while(!q->isEmpty())
    {
        p = q->dequeue();
        if(p->lchild)
        {
            cout<< p->lchild->data<<", ";
            q->enqueue(p->lchild);
        }

        if(p->rchild)
        {   
            cout<<p->rchild->data<<", ";
            q->enqueue(p->rchild);
        }
    }
}
template<class T>
void BinaryTree<T>::itpreorder()
{
    Stack<Node<T>*>* st = new Stack<Node<T>*>(20);
    Node<T>* p = root;
    while(p || !st->isEmpty())
    {
        if(p)
        {
            cout<<p->data<<", ";
            st->push(p);
            p = p ->lchild;
        }
        else
        {
            p = st->pop();
            p = p->rchild;
        }
        
    }
};

template<class T>
void BinaryTree<T>::itinorder()
{
    Stack<Node<T>*>* st = new Stack<Node<T>*>(20);
    Node<T>* p = root;
    while(p||!st->isEmpty())
    {
        if(p)
        {
            st->push(p);
            p = p -> lchild;
        }
        else
        {
            p = st->pop();
            cout<<p->data<<", ";
            p = p->rchild;   
        }
    }
};

template <class T>
void BinaryTree<T>::init_tree()
{
    Node<T> *p, *t;
    root -> data  = values[0]; 
    root -> lchild = NULL;
    root -> rchild = NULL;
    queue->enqueue(root);

    int i = 1;
    while((!queue->isEmpty()))
    {   
        int temp = 2;
        p = queue->dequeue();
        if(values[i] != -1&& i < num_node)
        {   
            t = new Node<T>;
            t ->data = values[i++];
            t ->lchild = t->rchild = NULL;
            temp --;
            p ->lchild = t;
            queue->enqueue(t);          
        }
        if(values[i] != -1&& i < num_node)
        {   
            t = new Node<T>;
            t ->data = values[i++];
            t ->lchild = t->rchild = NULL;
            temp --;
            p ->rchild = t;
            queue->enqueue(t);
        }
        i= i + temp;
    }
};

template <class T>
void BinaryTree<T>::init_tree(T *_values_, int _num_node)
{
    num_node = _num_node;
    values = _values_;
    init_tree();
};

template <class T>
void BinaryTree<T>::preorder()
{
    Node<T> *p = root;
    if(p)
    {
        cout<<p->data<<", ";
        preorder(p->lchild);
        preorder(p->rchild);
    } 
};

template <class T>
void BinaryTree<T>::preorder(Node<T>* p)
{   
    if(p)
    {
        cout<<p->data<<", ";
        preorder(p->lchild);
        preorder(p->rchild);
    } 
};

template <class T>
void BinaryTree<T>::postorder()
{
    Node<T> *p = root;
    if(p)
    {
        preorder(p->lchild);
        preorder(p->rchild);
        cout<<p->data<<", ";
    } 
};

template <class T>
void BinaryTree<T>::postorder(Node<T>* p)
{   
    if(p)
    {
        preorder(p->lchild);
        preorder(p->rchild);
        cout<<p->data<<", ";
    } 
};

template <class T>
void BinaryTree<T>::inorder()
{
    Node<T> *p = root;
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<", ";
        inorder(p->rchild);
    } 
};

template <class T>
void BinaryTree<T>::inorder(Node<T>* p)
{   
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<", ";
        inorder(p->rchild);
    } 
};
#endif