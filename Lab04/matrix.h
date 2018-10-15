//
// Created by jallport on 10/10/2017.
//
#include <iostream>
#include <string>
#include <math.h>

#ifndef LAB4_MATRIX_H
#define LAB4_MATRIX_H

using namespace std;

class matrix{

private:

    int m_rows;
    int m_cols;

public:


    matrix(int,int);



    void setArray(int,int); // set matrix with random xs

    void setArray0(int,int); // set matrix with 0s

    int getRandom(); // generates random number 3-9

};
#endif //LAB4_MATRIX_H
