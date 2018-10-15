#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <ctime>
#include "hex.h"
#include "matrix.h"

using namespace std;

string prob1(string, int);
int prob2(string,int,int,int,int);

string prob3 (int,string);

int arrayProb(int,int);

int main() {

    srand(time(NULL));


    val &my_val = *new val(my_val.getRandom());

    val &my_val1 = *new val(my_val1.getRandom());

    val &my_val2 = *new val(my_val2.getRandom());

    val &my_val3 = *new val(my_val3.getRandom());

    val &my_val4 = *new val(my_val4.getRandom());

    val &my_val5 = *new val(my_val5.getRandom());


    //********** PROB1 ********************
    string word="Balsmic";
    prob1(word,word.size() );
    word="Cat";
    cout<<endl;
    prob1(word,word.size());
    word="Cover";
    cout<<endl;
    prob1(word,word.size());

    cout<<endl;




    //********** PROB 2-3  ********************
    // PRINTS RANDOM HEX AND CORRESPONDING DECIMAL

    cout<<"Hex: "<<my_val.getHex()<<" Decimal: "<<my_val.getDecimal();
    cout<<endl;

    cout<<"Hex: "<<my_val1.getHex()<<" Decimal: "<<my_val1.getDecimal();
    cout<<endl;


    cout<<"Hex: "<<my_val2.getHex()<<" Decimal: "<<my_val2.getDecimal();
    cout<<endl;

    cout<<"Hex: "<<my_val3.getHex()<<" Decimal: "<<my_val3.getDecimal();
    cout<<endl;

    cout<<"Hex: "<<my_val4.getHex()<<" Decimal: "<<my_val4.getDecimal();
    cout<<endl;

    cout<<"Hex: "<<my_val5.getHex()<<" Decimal: "<<my_val5.getDecimal();
    cout<<endl;

    cout<<endl;

    matrix &arrayProb=*new matrix(arrayProb.getRandom(),arrayProb.getRandom()); // create object arrayProb

    delete &my_val;
    delete &my_val1;
    delete &my_val2;
    delete &my_val3;
    delete &my_val4;
    delete &my_val5;
    delete &arrayProb;

    return 0;
}


string prob1(string theString, int length){
    string addTo="ithag";

    for (int i=0;i<length;i++){
        if(theString[i]=='a'||theString[i]=='e'||theString[i]=='i'||theString[i]=='o'||theString[i]=='u'||theString[i]=='y'){
            theString.insert(i,addTo);
            length+=5;
            i+=5;
        }

    }
    cout<<theString<<", "<<theString.size();
}

