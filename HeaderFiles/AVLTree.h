//
// Created by Ali on 20/12/2022.
//

#ifndef DSA_SPOTIFY_PROJ_AVLTREE_H
#define DSA_SPOTIFY_PROJ_AVLTREE_H
#include <iostream>
using namespace std;
#define pow2(n) (1 << (n))


template <class T>
class avl_tree {
public:
    class node {
    public:
        T d;
        node *l;
        node  *r;
        node():l(NULL),r(NULL){};
    };
    node *root;
    int height(node *t){
        int h = 0;
        if (t != NULL) {
            int l_height = height(t->l);
            int r_height = height(t->r);
            int max_height = max(l_height, r_height);
            h = max_height + 1;
        }
        return h;
    }

    int difference(node *t){
            int l_height = height(t->l);
            int r_height = height(t->r);
            int b_factor = l_height - r_height;
            return b_factor;
    };
    node *rr_rotat(node *parent){
        node *t;
        t = parent->r;
        parent->r = t->l;
        t->l = parent;
        cout<<"Right-Right Rotation";
        return t;
    }
    node *ll_rotat(node *parent){
        node *t;
        t = parent->l;
        parent->l = t->r;
        t->r = parent;
        cout<<"Left-Left Rotation";
        return t;
    };
    node *lr_rotat(node*parent){
        node *t;
        t = parent->l;
        parent->l = rr_rotat(t);
        cout<<"Left-Right Rotation";
        return ll_rotat(parent);
    };
    node *rl_rotat(node *parent){
        node *t;
        t = parent->r;
        parent->r = ll_rotat(t);
        cout<<"Right-Left Rotation";
        return rr_rotat(parent);
    };
    node * balance(node *t){
        int bal_factor = difference(t);
        if (bal_factor > 1) {
            if (difference(t->l) > 0)
                t = ll_rotat(t);
            else
                t = lr_rotat(t);
        } else if (bal_factor < -1) {
            if (difference(t->r) > 0)
                t = rl_rotat(t);
            else
                t = rr_rotat(t);
        }
        return t;
    };

    bool Search(node *r,T x){
        if(r==nullptr)
            return false;
        if(r->d==x)
            return true;
        Search(r->l,x);
        Search(r->r,x);
    }

    node * insert(node *r,T v){

        if (r == NULL) {
            r = new node;
            r->d = v;
            r->l = NULL;
            r->r = NULL;
            root = r;
            return r;
        }
        //else if(v==r->d){
          //  return nullptr;

        else if (v< r->d) {
            r->l = insert(r->l, v);
            r = balance(r);
        } else if (v >= r->d) {
            r->r = insert(r->r, v);
            r = balance(r);
        } return r;
    }
    void inorderPrint(node *t) {
        if (t == NULL)
            return;
        inorderPrint(t->l);
        cout << t->d << " ";
        inorderPrint(t->r);
    }

    /*void show(node*, int);
    void inorder(node *);
    void preorder(node *);
    void postorder(node*);
     */
    avl_tree() {
        root = NULL;
    }
};




/*template <class T>
node *avl_tree<T>::insert(node *r, T v) {
    if (r == NULL) {
        r = new node;
        r->d = v;
        r->l = NULL;
        r->r = NULL;
        return r;
    } else if (v< r->d) {
        r->l = insert(r->l, v);
        r = balance(r);
    } else if (v >= r->d) {
        r->r = insert(r->r, v);
        r = balance(r);
    } return r;
}
 */
/*template <class T>
void avl_tree<T>::show(node *p, int l) {
    int i;
    if (p != NULL) {
        show(p->r, l+ 1);
        cout<<" ";
        if (p == root)
            cout << "Root -> ";
        for (i = 0; i < l&& p != root; i++)
            cout << " ";
        cout << p->d;
        show(p->l, l + 1);
    }
}
 ?\*/

/*
template <class T>
void avl_tree<T>::preorder(node *t) {
    if (t == NULL)
        return;
    cout << t->d << " ";
    preorder(t->l);
    preorder(t->r);
}
template <class T>
void avl_tree<T>::postorder(node *t) {
    if (t == NULL)
        return;
    postorder(t ->l);
    postorder(t ->r);
    cout << t->d << " ";
}
*/


#endif //DSA_SPOTIFY_PROJ_AVLTREE_H
