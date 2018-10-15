//
// Created by jallport on 11/29/2017.
//

#include <iostream>
#include <cmath>
#include <time.h>

#include "hashNode.h"

using namespace std;

hashNode::hashNode(){
    valuesSize=0;
    currSize=0;
    values=NULL;

}

hashNode::hashNode(string s){

    keyword=s;
    valuesSize=100;
    currSize=0;
    values= new string[valuesSize];

}


hashNode::hashNode(string s,string v){

    keyword=s;
    currSize=0;

    valuesSize=100;
    //string values=NULL;

    values= new string[valuesSize];

    values[currSize]=v;

}

void hashNode::addValue(string v){

    if(currSize>=valuesSize){
        dblArray();
    }
    values[currSize]=v;
    currSize++;



}




void hashNode::dblArray(){

    values= new string[valuesSize];

    string *valuesCopy=new string[valuesSize*2];

    int i=0;
    while(i<valuesSize){
        valuesCopy[i]=values[i];
        i++;
    }
    valuesSize=valuesSize*2;

    values=valuesCopy;



}


string hashNode::getRandValue() {

    int randNum = rand() % ((currSize) - 0 + 1) + 0;

    return values[randNum];
}
