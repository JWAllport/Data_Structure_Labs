//
// Created by jallport on 11/29/2017.
//

#ifndef LAB7_MAKESEAUS_H
#define LAB7_MAKESEAUS_H


#include "hashMap.h"
#include <iostream>
using namespace std;
class makeSeuss {
    hashMap *ht;
    string fn; // file name for input (“DrSeuss.txt”)
    string newfile; // name of output file
public:
    makeSeuss(string file,string newf,bool h1, bool c1);
    void readFile();
    void writeFile();
};

#endif /* MAKESEUSS_H_ */
