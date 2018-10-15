//
// Created by jallport on 11/3/2017.
//
#include <windef.h>
#include "AVLTree.h"
#include "Game.hpp"


using namespace std;



AVLTree::AVLTree(bool AVLFlag){
    bool (AVL = AVLFlag);
    root=NULL;



}

bool AVLTree::findWord(string s, NodeT *n){

    if(n==NULL || n->word==s){
        if(n==NULL)
            return false;
        else if(n->word==s){
            return true;
        }
    }
    else if(n->word<s){
        return findWord(s,n->right);
    }
    return findWord(s,n->left);

}

void AVLTree::addNode(string s,NodeT *r,int x,NodeT *OG_root) {


    if(AVL==true) {
        if (root == NULL) {

            root = new NodeT(s);
            root->word = s;
            root->left = NULL;
            root->right = NULL;
        } else if (r->word < s) {
            if (r->right == NULL) {
                NodeT *tmp = new NodeT(s);
                r->right = tmp;
                //cout <<"left max ";
                //cout << getMax(root->left);
                //cout<< "right max ";
                //cout <<endl<< getMax(root->right);

                //cout <<" get diff "<<getDiff(root);



                OG_root = adjustHeights(OG_root);
                x++;
                tmp->height = x;
                root = OG_root;
                //r->right->height=r->right->height+1;
            } else if (r->right != NULL) {
                //r->right->height=r->right->height+1;
                addNode(s, r->right, (x + 1), OG_root);
            }
        } else if (r->word > s) {
            if (r->left == NULL) {
                NodeT *tmp = new NodeT(s);
                r->left = tmp;
                adjustHeights(OG_root);

                OG_root = adjustHeights(OG_root);
                x++;
                tmp->height = x;
                root = OG_root;


                x++;
                tmp->height = x;
                //r->right->height=r->right->height+1;

            } else if (r->left != NULL) {
                //r->right->height=r->right->height+1;
                addNode(s, r->left, (x + 1), OG_root);
            }


        }

    }

    else if((AVL)==false) {
        if (root == NULL) {
            root = new NodeT(s);

            //x++;
        } else if (r == NULL) {
            NodeT *tmp = new NodeT(s);
            r = tmp;

        } else if (r->word < s) {
            if (r->right == NULL) {
                NodeT *tmp = new NodeT(s);
                r->right = tmp;
                x++;
                tmp->height = x;


            } else if (r->right != NULL) {
                addNode(s, r->right, (x + 1),OG_root);
            }


        } else if (r->word > s) {
            if (r->left == NULL) {
                NodeT *tmp = new NodeT(s);
                r->left = tmp;
                x++;
                tmp->height = x;
                //r->right->height=r->right->height+1;

            } else if (r->left != NULL) {
                //r->right->height=r->right->height+1;
                addNode(s, r->left, (x + 1),OG_root);
            }


        }
    }

}


void AVLTree::printIO(NodeT *root){
    //cout<<root->word<<endl;
    if(root!=NULL) {
        printIO(root->left);
        cout << root->word << endl;
        printIO(root->right);
    }
}
void AVLTree::printPre(NodeT *root){
    if(root!=NULL){
        cout<<root->word<<endl;
        printPre(root->left);
        printPre(root->right);

    }


}

void AVLTree::printPost(NodeT *root){

    if (root!=NULL){
        printPost(root->left);
        printPost(root->right);
        cout<<root->word<<endl;
    }
}

//only called when AVL flag is set to true

NodeT* AVLTree::adjustHeights(NodeT *n) {

    int balance=getDiff(n);

    if(balance>1){
        if(getDiff(n->left)>0){
            n=rotateLeft(n);
        }
        else{
            NodeT *tmp;
            tmp=n->left;
            n->left=rotateRight(tmp);
            rotateLeft(n);
        }
    }
    else if (balance <-1){
        if (getDiff(n->right)>0){
            NodeT *tmp;
            tmp=n->right;
            n->right=rotateLeft(tmp);
            rotateRight(n);
        }
        else {
            n=rotateRight(n);
        }
    }

return n;
}



int AVLTree::getMax(NodeT *n){

    int count=0;
    NodeT *tmp=n;
    if(tmp!=NULL){
       int x=getMax(tmp->left);
       int y=getMax(tmp->right);
       int max_height=std::max(x,y);
        count=max_height+1;
    }
    return count;
}

// JUST for AVL Trees, only called when AVL flag is true

NodeT* AVLTree::rotateRight(NodeT *n){

    NodeT *tmp = n->right;
    n->right=tmp->left;
    tmp->left=n;
    return tmp;
}
NodeT* AVLTree::rotateLeft(NodeT *n){

    NodeT *tmp=n->left;
    n->left=tmp->right;
    tmp->right=n;
    return tmp;
}
int AVLTree::getDiff(NodeT *n){
    NodeT *tmp=n;
    int leftH = getMax(tmp->left);
    int rightH = getMax(tmp->right);
    int difference= leftH-rightH;
    cout<<difference<<"     ";
    return difference;

}
