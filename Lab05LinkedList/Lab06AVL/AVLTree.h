//
// Created by jallport on 11/3/2017.
//

#ifndef LAB6_AVLTREE_H
#define LAB6_AVLTREE_H


#include <iostream>
#include <stdlib.h>
#include "NodeT.hpp"


using namespace std;

class AVLTree{
    friend class Game;
    NodeT *root; // holds the root of the bst

    bool AVL;// flag for whether to adjust bst to be an avl tree


public:

    AVLTree(bool); //constructor

    void insert(NodeT *s);

    NodeT* AVLinsert(string s,NodeT *aroot);

    bool findWord(string s, NodeT *n);; // finds whether s is in the bst. Returns true (if found) and false otherwise.

    void addNode(string s,NodeT*,int,NodeT*); //Adding s to the tree


    void printIO(NodeT *root);


    void printPre(NodeT *root);
    void printPost(NodeT *root);
    NodeT* adjustHeights(NodeT *n);
    int getMax(NodeT *n);

    //Just for AVL Trees, only called when AVL flag is set to true
    NodeT *rotateRight(NodeT *n);
    NodeT * rotateLeft(NodeT *n);
    int getDiff(NodeT *n);

};


#endif //LAB6_AVLTREE_H
