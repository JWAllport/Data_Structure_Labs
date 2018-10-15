//
// Created by Jake on 10/8/2017.
//
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#ifndef LAB4_HEX_H
#define LAB4_HEX_H


class val{

private:

    int m_decimal;
    string m_hex;


public:

    val(int decimal); // constructor

    val(string hex); // constructor


    string getHex();


    int getRandom();

    int getDecimal();


    int setHex(string,int,int,int,int);

    string setDecimal(int,string);



};
#endif //LAB4_HEX_H
