//
// Created by jallport on 11/5/2017.
//

#include <stdlib.h>
#include <fstream>
#include <chrono>
#include <cmath>
#include "LL.h"
#include "Game.hpp"
#include <algorithm>

using namespace std;

//constructor – sets to NULL and 0, respectively
LL::LL() {
    first=NULL; // first pointer
    last=NULL; // last pointer
    size=0;
    score=0;


}

void LL::getScore(){
    NodeL *tmp=first;

    while(tmp!=NULL){
        score+=tmp->wscore;
        tmp=tmp->next;
    }
}

//adds very first node to list
void LL::addFirst(string x){
    NodeL *n=new NodeL(x);
    first=n;
    first->next=NULL;
    size++;

}


//add new node to end of list
void LL::push(string x){

    if(first==NULL){
        addFirst(x);
    }
    else {
        NodeL *n = new NodeL(x);
        NodeL *curr = first;
        int count = 1;

        while (curr->next != NULL) {
            count++;
            curr = curr->next;
        }
        curr->next = n;
        size = count;
    }
}

void LL::printList() {
        cout<<endl<<endl;
        NodeL *tmp = first; // copy of first pointer
        for (int i=0;i<=size;i++){

            cout << tmp->word<<" "<<tmp->wscore<<endl;
            tmp=tmp->next;

        }

        cout<<endl;

}



