/*
 * File:   main.cpp
 * Author: Jake Allport
 *
 *
 */

/* Jake Allport
 * Eeshita Biswas
 * 9/20/17
 * This file contains functions for lab2. The functions aren't necessarily related
 * in any way other than that they are required for lab1.
*/


#include <iostream>
#include <math.h>
#include <array>
#include<string>
#include <time.h>

using namespace std;


//************************ function declaration **************************************

void reverseStr(string astring,string stringBuild,int count);// Problem 1

int sumOfDigit(int aVal,int sum); // Problem 2

int lowestVal(int anArray[], int size,int counter,int small); // Problem 3

bool elfish(string word); // Problem 4

bool perfectNum(int aNumb,int counter,int total);// Problem 5

char starFunc(int anInt,char star,int,int,int,string );
char starFunc2(int anInt,char star,int,int,int,string );
char starFunc3(int anInt, char star,int,int,int,string);


bool order1(int *x, int *y); //PT2 PROBLEM 1

bool order2(int &x, int &y); //PT2 PROBLEM 2

void pointer(int *val1); // PT2 PROBLEM 3

void prob4Func(int *aVal); // PT2 PROBLEM 4

void arrayFunc(int[], int length); // PT2 PROBlEM 5

void prob6Func(int[],int*); //PT2 PROBLEM 6

void prob7Func(int[],int length,int val_1,int val_2); // PT2 PROBLEM 7

void prob8Func(int[],int length); // PT2 PROBLEM 8

void prob9Func(double[],int length); //PT2 PROBLEM 9

int prob10Func(int[],int[] ,int ,int ,int,int); // PT2 PROBLEM 10
//************************ function declerations end **************************************
int main() {

    // ************************ RANDOM NUMBER GEN ************************

    srand(time(NULL));
    int a = rand()%(51) + 0;
    int b = rand()%(51) + 0;



    // ************************ Problem 1 ************************

    cout<<endl<<"************************ Problem 1 **************************************"<<endl;

    string theString="Hello";
    int prob1count= theString.size()-1;
    string stringBuild=" ";
    reverseStr(theString,stringBuild,prob1count);

    cout<<endl;

    string theString1="Irma";
    int prob1count2= theString1.size();
    reverseStr(theString1,stringBuild,prob1count2);

    cout<<endl;

    string theString2="World";
    int prob1count3= theString1.size();
    reverseStr(theString2,stringBuild,prob1count3);

    cout<<endl;
    // ************************ Problem 2 ************************
    cout<<"************************ Problem 2 **************************************"<<endl;
    int sum=0;
    sumOfDigit(4321,sum);
    cout<<endl;
    sumOfDigit(55,sum);
    cout<<endl;
    sumOfDigit(2893,sum);
    cout<<endl;
   // ************************ Problem 3 ************************
    cout<<endl<<"************************ Problem 3 **************************************"<<endl;
    int anArray[]={-10,0,-43,3,4,5};
    int size=6;
    int anArray_1[]={-11,3,4,23,4,4,3};
    int size1=7;
    int anArray_2[]={3,4,7,2,-4};
    int size2=5;

    int positionIn=0;
    int small=0;

    lowestVal(anArray,size,positionIn,small);
    cout<<endl;
    lowestVal(anArray_1,size1,positionIn,small);
    cout<<endl;
    lowestVal(anArray_2,size2,positionIn,small);
    cout<<endl;

    //************************ Problem 4 ************************
    cout<<endl<<"************************ Problem 4 **************************************"<<endl;

    string word="word";

    string word1="whiteleaf";

    string word2="not";


    cout<<elfish(word); //Should print false

    cout<<endl;

    cout<<elfish(word1); // Should print true

    cout<<endl;

    cout<<elfish(word2); // Should print false

    cout<<endl;

    //************************Problem 5 ************************

    cout<<endl<<"************************ Problem 5 **************************************";

    cout<<perfectNum(496,1,0); // Print true
    cout<<endl;
    cout<<perfectNum(6,1,0);// Print true
    cout<<endl;
    cout<<perfectNum(33,1,0); // Print false

    // ************************ Problem 6 ************************
    cout<<endl<<"************************ Problem 6 **************************************"<<endl;
    int count1=0;
    int count2=1;
    int count3=0;
    string space=" ";
    starFunc(4,'x',count1,count2,count3,space);

    cout<<endl;

    starFunc(10,'x',count1,count2,count3,space);

    cout<<endl<<endl;

    starFunc(20,'x',count1,count2,count3,space);

    cout<<endl<<endl;

    //  ************ CALL BY VALUE/POINTER/REFERENCE PROBLEMS *****************

    //************************ Problem 1 **************************************
    cout<<endl<<"************************ PT2 Problem 1 **********************************"<<endl;

    // See top of main for Random number generator

    cout<<"First value before function: "<<a;
    cout<<endl;
    cout<<"second value before function: "<<b;
    cout<<endl;

    cout<<order1(&a,&b);

    cout<<endl<<"First value after function: "<<a;
    cout<<endl<<"second value after function: "<<b;
    cout<<endl;

    // Test without random generation

    int a_1=10;
    int b_1=15;
    cout<<endl;
    cout<<"First value before function test_1: "<<a_1;
    cout<<endl;
    cout<<"second value before function test_1: "<<b_1;
    cout<<endl;
    cout<<order1(&a_1,&b_1);

    cout<<endl<<"First value after function test_1: "<<a_1;
    cout<<endl<<"second value after function test_1: "<<b_1;
    cout<<endl;

    // Test 2 without random generation

    int a_2=25;
    int b_2=11;
    cout<<endl;

    cout<<"First value before function test_2: "<<a_2;
    cout<<endl;

    cout<<"second value before function test_2: "<<b_2;
    cout<<endl;
    cout<<order1(&a_2,&a_2);
    cout<<endl<<"First value after function test_2: "<<a_2;
    cout<<endl<<"second value after function_2: "<<b_2;



    //************************ Problem 2 **************************************
    cout<<endl<<"************************ PT2 Problem 2 **********************************";

    // See top of main for random generator
    cout<<endl<<"First value before function: "<<a;
    cout<<endl;
    cout<<"second value before function: "<<b;

    order2(a,b);

    cout<<endl<<"First value after function: "<<a;
    cout<<endl<<"second value after function: "<<b;
    cout<<endl;
    // Test 2

    int test1_a=10;
    int test1_b= 15;

    cout<<endl<<"First value before function: "<<test1_a;
    cout<<endl;
    cout<<"second value before function: "<<test1_b;

    order2(a,b);

    cout<<endl<<"First value after function: "<<test1_a;
    cout<<endl<<"second value after function: "<<test1_b;
    cout<<endl;
    //Test 3
    int test2_a=43;
    int test2_b=2;

    cout<<endl<<"First value before function: "<<test2_a;
    cout<<endl;
    cout<<"second value before function: "<<test2_b;

    cout<<order2(test2_a,test2_b);

    cout<<endl<<"First value after function: "<<test2_a;
    cout<<endl<<"second value after function: "<<test2_b;

    // ************************ PT2 PROBLEM 3 ************************

    cout<<endl<<"************************ PT2 PROBLEM 3 *********************************"<<endl;

    int x=10;
    cout<<"Address of x is "<<&x<<endl;

    pointer(&x);
    cout<<endl;
    cout<<endl;

    int x_1=4;

    cout<<"Address of x_1 is :" <<&x_1<<endl;
    pointer(&x_1);

    int x_2=54;
    cout<<endl;
    cout<<endl;
    cout<<"Address of x_2 is :" <<&x_1<<endl;
    pointer(&x_2);


    // ************************ PT2 PROBLEM 4 ************************

    cout<<endl<<"************************ PT2 PROBLEM 4 *********************************"<<endl;

    int y=25;

    cout<<"Value of y is: "<<y;
    cout<<endl;
    cout<<"Address of y is: "<<&y;
    prob4Func(&y);
    cout<<endl;
    int y_1=30;
    cout<<endl;
    cout<<"Value of y is: "<<y_1;
    cout<<endl;
    cout<<"Address of y is: "<<&y_1;
    prob4Func(&y_1);
    cout<<endl;
    int y_2=25;
    cout<<endl;
    cout<<"Value of y is: "<<y_2;
    cout<<endl;
    cout<<"Address of y is: "<<&y_2;
    prob4Func(&y_2);
    // ************************ PT2 PROBLEM 5 ************************
    cout<<endl<<"************************ PT2 PROBLEM 5 *********************************";

    cout<<endl;
    int someArray[20];
    arrayFunc(someArray,20);

    // ************************ PT2 PROBLEM 6 ************************
    cout<<endl<<"************************ PT2 PROBLEM 6 ************************";

    int prob6Array[5]={1,2,4,4,5};
    int prob6Length = 5;


    prob6Func(prob6Array,&prob6Length);

    int prob6Array_2[10]={4,3,5,6,2,3,6,6,7,8};
    int prob6Length_2=10;
    cout<<endl;
    prob6Func(prob6Array_2,&prob6Length_2);

    cout<<endl;
    int prob6_array_3[20]={5,6,7,8,7,6,5,4,8,99,3,4,5,66,7,8,88,66,33,22};
    int prob6length_3=20;
    prob6Func(prob6_array_3,&prob6length_3);


    // ************************ PT2 PROBLEM 7 ************************
    cout<<endl<<"************************ PT2 PROBLEM 7 ************************"<<endl;

    int a_prob7 = -1;
    int b_prob7 = -1;

    int prob7array[5]={1,2,4,4,5};
    int prob7Length=5;

    int prob7array_1[10]={4,3,5,6,2,3,6,6,7,8};
    int prob7length_1=10;

    int prob7_array_3[20]={5,6,7,8,7,6,5,4,8,99,3,4,5,66,7,8,88,66,33,22};
    int prob7length_3=20;

    prob7Func(prob7array,prob7Length,a_prob7, b_prob7); //The smallest value is: 1 It's position is: 0
    cout<<endl;

    prob7Func(prob7array_1,prob7length_1,a_prob7,b_prob7); //The smallest value is: 2 It's position is: 4
    cout<<endl;

    prob7Func(prob7_array_3,prob7length_3,a_prob7,b_prob7); //The smallest value is: 3 It's position is: 10
    cout<<endl;


    // ************************ PT2 PROBLEM 8 ************************
    cout<<endl<<"************************ PT2 PROBLEM 8 ************************"<<endl;

    prob8Func(prob6Array,prob6Length);

    cout<<endl<<endl;

    prob8Func(prob7array,prob7Length);

    cout<<endl<<endl;
    prob8Func(prob7array_1,prob7length_1);

    // ************************ PT2 PROBLEM 9 ************************
    cout<<endl<<"************************ PT2 PROBLEM 9 ************************"<<endl;

    double prob9Array[]={1.1,2.2,3.3,4.4};

    int prob9length=4;
    prob9Func(prob9Array,prob9length);
    cout<<endl;

    double prob9array_1[]={1.1,33.2};
    int prob9length_1=2;
    prob9Func(prob9Array,prob9length_1);
    cout<<endl;

    double prob9array_2[]={5.5,4.3,88.9,9.9,7.6};
    int prob9length_2=5;

    prob9Func(prob9array_2,prob9length_2);
    // ************************ PT2 PROBLEM 10 ************************
    cout<<endl<<"************************ PT2 PROBLEM 10 ************************"<<endl;
    cout<<endl;
    int prob10_array_1[2]={100,2};

    int prob10_array_2[2]={50,4};

    int prob10_length_1=2;
    int prob10_length_2=2;

    int first=0;
    int second=0;
    //should print 1
    cout<<prob10Func(prob10_array_1,prob10_array_2,prob10_length_1,prob10_length_2,first,second);

    cout<<endl;
    int prob10_array_3[3]={100,2,4};

    int prob10_array_4[3]={500,4,7};

    int prob10_length_3=3;
    int prob10_length_4=3;

    //should print -1
    cout<<prob10Func(prob10_array_3,prob10_array_4,prob10_length_1,prob10_length_2,first,second);

    cout<<endl;
    int prob10_array_5[4]={100,2,4,1};

    int prob10_array_6[4]={100,2,4,1};

    int prob10_length_5=4;
    int prob10_length_6=4;


    //should print 0
    cout<<prob10Func(prob10_array_5,prob10_array_6,prob10_length_5,prob10_length_6,first,second);


    return 0;
}
//************************ PROBLEM 1 ************************

    void reverseStr(string theString,string stringBuild, int count){

        if(count>=0){

            stringBuild+=theString[count];
            count--;
            return reverseStr(theString,stringBuild,count);
        }
        cout<<stringBuild;
    }
//************************ PROBLEM 2 ************************


int sumOfDigit(int aVal,int sum){

    if (aVal>0){

        sum += aVal % 10; // Sum is global variable

        return sumOfDigit(aVal / 10,sum);
    }
    else{
        cout<< sum;
    }
}


// ************************ PROBLEM 3 ************************

int lowestVal(int anArray[], int arraySize,int counter,int small) {



    if (anArray[counter] <= small && (arraySize)>counter) {
        small = anArray[counter];
        counter++;

        return (lowestVal(anArray, arraySize, counter,small));
    }

    else if(anArray[counter]>small && (arraySize)>counter){
        counter++;
        return (lowestVal(anArray,arraySize,counter,small));
        }

    else {
        cout<< small;
    }
}

// ************************ PROBLEM 4 ************************

bool elfish(string word){

    return(word.find('e')!=std::string::npos && word.find('l')!=std::string::npos && word.find('f')!=std::string::npos);

    }


// ************************ PROBLEM 5 ************************

bool perfectNum(int aNumb,int counter,int total){

    if (total==aNumb){
        cout<<endl;
        return true;

    }
    else if(aNumb<counter && total!=aNumb){
        cout<<endl;
        return false;
    }
    else if(aNumb%counter==0){
        total+=counter;
        return perfectNum(aNumb,counter+1,total);

    }
    else if(aNumb%counter!=0){
        return perfectNum(aNumb,counter+1,total);
    }


}

// ************************ PROBLEM 6 ************************



char starFunc2(int anInt, char star,int count1,int count2, int count3,string space) {

    if(count3<(anInt*2)-3){
        cout<< space;
        count3++;

        return starFunc2(anInt,star,count1,count2,count3,space);
    }

}


char starFunc3(int anInt, char star,int count1,int count2, int count3,string space) {

    if(count3<(anInt*2)){

        cout<< space;
        count3++;
        return starFunc3(anInt,star,count1,count2,count3,space);
    }

}

char starFunc(int anInt, char star,int count1,int count2, int count3,string space) {


    if(count1>0){
        cout<<space;
        count1--;

        return starFunc(anInt,star,count1,count2,count3,space);
    }
    if (count2<=(anInt*2)-2) {
        cout<<star;

        if (count3<(anInt*2)-3) {
            starFunc2(anInt,star,count1,count2,count3,space);
            cout << star;
            count3+=2;
            cout<<endl;
            count1+=count2;
            count2++;
            return starFunc(anInt, star, count1, count2, count3, space);
        }


        else if (count3>(anInt*2)-3){
            starFunc3(anInt,star,count1,count2,count3,space);
            //cout << star;
            count3+=1;
            cout<<endl;
            count1+=count2;
            count2++;
            return starFunc(anInt, star, count1, count2, count3, space);

        }
    }
}





// ************************ PT2 PROBLEM 1 ************************

bool order1(int *a,int *b) {

    if (*a<*b)
        return true;
    else {
        int temp = *a;
        *a=*b;
        *b=temp;
        return false;
    }

}

// ************************ PT2 PROBLEM 2 ************************

bool order2(int &x,int &y){

    int temp = x;
    x=y;
    y=temp;



}

// ************************ PT2 PROBLEM 3 ************************

void pointer(int *a){

    cout<<"Value at "<<a<<" is "<<*a;
    cout<<endl<<"The address of the parameter is "<< &a;
    cout<<endl<<"The address in the parameter is "<< a;
}
// ************************ PT2 PROBLEM 4 ************************

void prob4Func(int *y){

    cout<<endl<<"Address of parameter is: "<< &y;
    cout<<endl<<"Value of parameter is: "<< *y;
}

// ************************ PT2 PROBLEM 5 ************************

void arrayFunc(int anArray[],int length){
    srand(time(NULL));
    for (int i=0;i<length;i++){


        int x=rand()% 99;
        anArray[i]=x;

        cout<<anArray[i]<<" ";
    }

}

// ************************ PT2 PROBLEM 6 ************************

void prob6Func(int anotherArray[], int *length){
    cout<<endl;
    for(int i =0; i<*length;i++){
        if(i==*length-1){
            cout<<anotherArray[i];
        }
        else {
            cout << anotherArray[i] << ",";
        }
    }

    cout<<endl;
}

// ************************ PT2 PROBLEM 7 ************************

void prob7Func(int prob6Array[],int prob6Length,int smallest, int position) {
    smallest = prob6Array[0];
    for (int i = 0; i < prob6Length; i++) {

        if(prob6Array[i]<=smallest) {
            smallest = prob6Array[i];
            position = i;
        }
    }
    cout<< "The smallest value is: "<<smallest<<" It's position is: "<<position;
}

//************************ PT2 PROBLEM 8 ************************

void prob8Func(int anArrayhurray[], int alength){

    for(int i=0;i<alength;i++){

        cout<<&(anArrayhurray[i])<<",";
    }

}

//************************ PT2 PROBLEM 9 ************************

void prob9Func(double anArrayhurray[], int alength){

    for(int i=0;i<alength;i++){

        cout<<&(anArrayhurray[i])<<",";
    }

}
//************************ PT2 PROBLEM 10 ************************

int prob10Func(int anArray[],int anotherArray[],int prob10_length_1,int prob10_length_2,int first, int second){

    for (int i=0;i<prob10_length_1;i++){
        first+=anArray[i];

        }
    for(int j=0;j<prob10_length_2;j++){
        second+=anotherArray[j];
    }
    if(first>second){
        return 1;
    }
    else if(first==second){
        return 0;
    }
    else if(second>first){
        return -1;
    }
}
