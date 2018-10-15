//
// Created by Jake on 10/8/2017.
//

#include <algorithm>
#include "hex.h"

val::val(int decimal){
    m_decimal=decimal;
    m_hex=setDecimal(decimal,"");


}

val::val(string hex){

    m_decimal=setHex(hex,15,hex.size()-1,0,0);

    m_hex=hex;

}
string val::getHex(){

    return m_hex;
}

int val::getDecimal(){
    return m_decimal;
}


int val::getRandom() {
    int min=0;
    int max=900;

    return (min +(rand()%(int)(max-min+1)));
}

int val::setHex(string hex,int j,int i,int decimal,int position) {
    string hexVals="0123456789ABCDEF";

    if (i>=0) {

        if (hex[i] != hexVals[j]){
            j--;

            return setHex(hex, j, i,decimal,position);
        }

        decimal+=((j)*(pow(16,position)));
        position++;
        i--;
        return setHex(hex, 15, i,decimal,position);

    }
    return decimal;
}


string val::setDecimal(int decimal, string totalHex){
    string hexvals="0123456789ABCDEF";
    totalHex+=hexvals[decimal%16];

    if (decimal/16!=0) {
        return setDecimal(decimal / 16, totalHex);
    }
    (reverse(totalHex.begin(),totalHex.end()));
    return totalHex;
}
