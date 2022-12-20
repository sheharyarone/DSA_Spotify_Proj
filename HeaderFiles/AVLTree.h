//
// Created by Ali on 20/12/2022.
//

#ifndef DSA_SPOTIFY_PROJ_AVLTREE_H
#define DSA_SPOTIFY_PROJ_AVLTREE_H
#include <iostream>
using namespace std;
template <class T>
class AVLNode{
public:
    T data;
    AVLNode<T> *LeftChild;
    AVLNode<T> *RightChild;
    int height;
};
template <class T>
class AVLTree{
public:
    int max(int a,int b){
        return (a>b) ? a:b;
    }
    int height(AVLNode<T> *x){
        if(x==NULL)
            return 0;
        return x->height;
    }
    AVLNode<T> * NewNode(int key){
        AVLNode<T> *node=new AVLNode<T>;
        node->data=key;
        node->RightChildChild=NULL;
        node->LeftChildChild=NULL;
        node->height=1;
        return node;
    }
    AVLNode<T> *RightChildRotate(AVLNode<T> *y){
        AVLNode<T> *x=y->LeftChildChild;
        AVLNode<T> *T2=x->RightChildChild;
        x->RightChildChild=y;
        y->LeftChildChild=T2;
        y->height=max(height(y->LeftChildChild, height(y->RightChildChild)))+1;
        x->height=max(height(x->LeftChildChild), height(x->RightChildChild))+1;
        return x;
    }
    AVLNode<T> *LeftChildRotate(AVLNode<T> *x){
        AVLNode<T> *y=x->RightChildChild;
        AVLNode <T> *T2=y->LeftChildChild;
        y->LeftChildChild=x;
        x->RightChildChild=T2;
        x->height=max(height(x->RightChildChild),height(x->LeftChildChild))+1;
        y->height=max(height(y->RightChildChild), height(y->LeftChildChild))+1;
        return y;
    }
    int getBalanceFactor(AVLNode <T> *x){
        if(x==NULL)
            return 0;
        return (height(x->LeftChildChild)- height(x->RightChildChild));
    }
    AVLNode<T> *InsertNode(AVLNode<T> *x,int key){
        if(x==NULL)
            return (NewNode(key));
        if(key<x->data)
            x->LeftChildChild= InsertNode(x->LeftChildChild,key);
        if(key>x->data)
            x->RightChildChild= InsertNode(x->RightChildChild,key);
        else
            return x;
        x->height=1+max(height(x->LeftChildChild), height(x->RightChildChild));
        int BalanceFactor= getBalanceFactor(x);
        if(BalanceFactor>1){
            if(key<x->LeftChildChild->data){
                return RightChildRotate(x);
            }
            else if (key>x->LeftChildChild->data){
                x->LeftChildChild= LeftChildRotate(x->LeftChildChild);
                return RightChildRotate(x);
            }
        }
        if(BalanceFactor<-1){
            if(key>x->RightChildChild->data)
                return LeftChildRotate(x);
            else if(key<x->RightChildChild->data){
                x->RightChildChild= RightChildRotate(x->RightChildChild);
                return LeftChildRotate(x);
            }
        }
        return x;
    }
    // Node with minimum value
    AVLNode<T> *nodeWithMimumValue(AVLNode<T> *x) {
        AVLNode<T> *current = new AVLNode<T>;
        while (current->LeftChildChild != NULL)
            current = current->LeftChildChild;
        return current;
    }

// Delete a node
    AVLNode<T> *deleteNode(AVLNode<T> *x, int value) {
        // Find the node and delete it
        if (x == NULL)
            return x;
        if (value < x->data)
            x->LeftChildChild = deleteNode(x->LeftChildChild, value);
        else if (value > x->data)
            x->RightChildChild = deleteNode(x->RightChildChild, value);
        else {
            if ((x->LeftChildChild == NULL) ||
                (x->LeftChildChild == NULL)) {
                AVLNode<T> *temp = x->LeftChildChild ? x->LeftChildChild : x->RightChildChild;
                if (temp == NULL) {
                    temp = x;
                    x = NULL;
                } else
                    *x = *temp;
                free(temp);
            } else {
                AVLNode<T> *temp = nodeWithMimumValue(x->RightChildChild);
                x->data = temp->data;
                x->RightChildChild = deleteNode(x->RightChildChild,
                                         temp->data);
            }
        }

        if (x == NULL)
            return x;

        // Update the balance factor of each node and
        // balance the tree
        x->height = 1 + max(height(x->LeftChildChild),
                               height(x->RightChild));
        int balanceFactor = getBalanceFactor(x);
        if (balanceFactor > 1) {
            if (getBalanceFactor(x->LeftChild) >= 0) {
                return RightChildRotate(x);
            } else {
                x->LeftChild = LeftChildRotate(x->LeftChild);
                return RightChildRotate(x);
            }
        }
        if (balanceFactor < -1) {
            if (getBalanceFactor(x->RightChild) <= 0) {
                return LeftChildRotate(x);
            } else {
                x->RightChild = RightChildRotate(x->RightChild);
                return LeftChildRotate(x);
            }
        }
        return x;
    }

// Print the tree
    void printTree(AVLNode<T> *x, string indent, bool last) {
        if (x != nullptr) {
            cout << indent;
            if (last) {
                cout << "R----";
                indent += "   ";
            } else {
                cout << "L----";
                indent += "|  ";
            }
            cout << x->key << endl;
            printTree(x->LeftChild, indent, false);
            printTree(x->RightChild, indent, true);
        }
    }


};



#endif //DSA_SPOTIFY_PROJ_AVLTREE_H
