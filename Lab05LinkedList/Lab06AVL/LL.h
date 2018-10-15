//
// Created by jallport on 11/5/2017.
//

#ifndef LAB6_LL_H
#define LAB6_LL_H


#include <iostream>
#include <stdlib.h>
#include "NodeL.hpp"

struct LL {
    friend class Game;
    NodeL *first;
    NodeL *last;
    int size;
    int score;

//public:
    LL();
    void getScore();
    void printList();
    void addFirst(string x);
    void push(string x);

};


#endif //LAB6_LL_H
