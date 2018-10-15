//
// Created by jake and sury on 10/18/17.
//


#include "Document.hpp"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <chrono>
#include <cmath>
#include "LLSE.hpp"
#include <algorithm>
using namespace std;

//constructor – sets to NULL and 0, respectively
LLSE::LLSE() {
    first=NULL; // first pointer
    last=NULL; // last pointer
    size=0;
    wordcount=0;


}
// destructor – goes through whole list and deletes
LLSE::~LLSE(){
    cout << "I deleted: "<< last << endl;

}

//adds very first node to list
void LLSE::addFirst(string x){
    Node *n=new Node(x);
    first=n;
    first->next=NULL;
    size++;

}

//adds new node to beginning of list
void LLSE::addAtFirst(string x){
    Node *tmp=first;
    Node *n=new Node(x);
    first=n;
    first->next=tmp;
    size++;
}

//add new node to end of list
void LLSE::push(string x){

    Node* n = new Node(x);
    Node *curr = first;
    int count = 1;

    while(curr->next != NULL)
    {
        count++;
        curr = curr->next;
        }
        curr->next = n;
        size = count;
}


// Called by document first base function of LLSE
void LLSE::insertUnique(string x) {

    // creates first node
    if(first==NULL){
        addFirst(x);
        wordcount++;

    }

    // pushes new node to begining
    else if(x<(first->word)){
        addAtFirst(x);
        wordcount++;
    }
    //puts new node at the end
    else{
        //push(x);
        findInsert(x);
        wordcount++;
    }

}

//for each node, prints word, and count
void LLSE::printLL() {
    cout<<endl<<endl;
    Node *tmp = first; // copy of first pointer
    cout<<size<<endl;
    for (int i=0;i<size;i++){

        cout << tmp->word <<" count: "<<tmp->count<<flush<<endl;
        tmp=tmp->next;

    }

    cout<<endl;

}
//returns node that occurs right alphabetically right before where to insert new node
Node* LLSE::findInsert(string x) {
    Node *tmp=first;
    Node *n=new Node(x);
    //if next is null add to end of LL
    if(tmp->next==NULL){
        push(x);
        return NULL;
    }
    // if the next word in the LL and the word to be inserted are the same. Increase the count of the word already in the LL
    else if(tmp->next->word==x){
        tmp->next->count=tmp->next->count+1;
        return NULL;
    }
    // while X is greater than the word in next (ex a<b)
    while(tmp->next->word<x){

        tmp=tmp->next;
        if(tmp->next==NULL){
            push(x);
            return NULL;
        }
        else if(tmp->next->word==x){
            tmp->next->count=tmp->next->count+1;
            return NULL;
        }
    }
    Node *tmp2=tmp->next;
    tmp->next=n;
    n->next=tmp2;
    size++;

}

void LLSE::normalizeCounts() {
    Node *tmp=first;
    Node *tmp2=first->next;

    for(int i=0;i<size;i++){

        first->next=tmp;
        first->count=first->count/wordcount;
        tmp->next=tmp2;

    }
}
string LLSE::remFirst(){

    string x=first->word;
    delete first;
    first=first->next;
    size--;
    return x;
}
string LLSE::pop(){

    if(size>0){
        Node *tmp=first;
        for(int i=0;i<size-1;i++){
            tmp=tmp->next;

        }
        string x=last->word;
        delete last;
        last=tmp;
        last->next=NULL;
        size--;
        return x;
    }

}

string LLSE::remNext(Node *n){
    Node *tmp=first;
    while(tmp!=n) {
        tmp=tmp->next;
    }
    string x=tmp->next->word;
    Node *tmp2=tmp->next;
    tmp->next=tmp->next->next;
    delete tmp2;
    return x;

}

void LLSE::eliminateLowWords(){

    Node *tmp=first;

    for(int i=0;i<size;i++){
        if(tmp->count<0.02){
            Node *tmp2=tmp->next;
            remNext(tmp);
            Node *tmp=tmp2;
        }

        tmp=tmp->next;
    }
}
