/*
 * File:   main.cpp
 * Author: Jake Allport
 *
 * Created on August 31, 2017, 10:13 AM
 */

/* Jake Allport, Steve Etgen, Cecelia O'Neill
 * Eeshita Biswas
 * 9/06/17
 * This file contains functions for lab1. The functions aren't necessarily related
 * in any way other than that they are required for lab1.
*/


#include <iostream>
#include <math.h>
#include <array>
#include<string>

using namespace std;

bool isPrime(int x); // function declarations

int theSum(int x, int y);

int leapYear(int currentYear);

int triangle(int x);

int armstrong(int x);

int largestNumber(int x[],int size);

bool isPalindrome(int x[],int size);

int listOfNum(int x[],int size);


int main() {

    int myArray[]={1,2,3,2,1}; // Array used for problem 7, 8 and 9

    int myArraySize = 5;

    int myArray2[]={5};

    int myArraySize2= 1;

    int myArray3[]={9,5,4,3,4,5};

    int myArraySize3=6;

    /* Problem 1
     * Should print "Hello World!"
     */
    cout << "Problem 1"<<endl << "Hello, World!";
    cout<<endl<<"****************************************" <<endl;

    /* Problem 2
     * Should print 1 then 0, then 1
    */
    cout <<"Problem 2"<<endl;
    cout<< isPrime(3)<< endl;
    cout<<isPrime(4)<<endl;
    cout<<isPrime(5)<<endl;
    cout<<"****************************************"<<endl;

    /*Problem 3
     * Should print 10 then 5 then 45
    */
    cout <<"Problem 3"<<endl;
    cout<<theSum(5,1)<<endl;
    cout<<theSum(2,4)<<endl;
    cout<<theSum(1,10)<<endl;
    cout<<"****************************************"<<endl;

    /*Problem 4
     * Should print... a lot of years
    */
    cout <<"Problem 4"<<endl;
    cout<<"Test 1 Problem 4-From 2017 to 2417"<<endl;
    leapYear(2017);
    cout<<endl<<"Test 2 Problem 4-From 2042 to 2442"<<endl;
    leapYear(2042);
    cout<<endl<<"Test 3 Problem 4-From 2093 to 2293"<<endl;
    leapYear(2093);

    cout<<"****************************************"<<endl;

    /* Problem 5
     * Should print triangle of #s, starting w/ 1 and ending number in parameter
     * First Triangle ends w/ seven fours horizontally aligned
     * Second Triangle ends w/ nine fives horizontally aligned
     * Third Triangle ends w/ seventeen nines horizontally aligned
     */
    cout <<"Problem 5"<<endl;
    triangle(4);
    cout<<endl;
    triangle(5);
    cout<<endl;
    triangle(9);

    cout<<endl<<"****************************************"<<endl;

    /* Problem 6
     * Should print 1, 2, 3, 4, 5, 6, 7, 8, 9, 153, 370, 371, 407, 1634, 8208, 9474, 54748..etc
     * First test ends at 10
     * Second test ends at 100
     * Third test ends at 10000
     */
    cout <<"Problem 6" <<endl;
    cout<<"Test one with limit ten"<<endl;
    armstrong(10);
    cout<<endl;
    cout<<"Test two with limit 100"<<endl;
    armstrong(100);
    cout<<endl;
    cout<<"Test three with limit 10000"<<endl;
    armstrong(10000);
    cout<<endl<<"****************************************"<<endl;

    /* Problem 7
     * Should print 3, then 5, and then 9
    */
    cout<<"Problem 7"<<endl;

    largestNumber(myArray,myArraySize);
    cout<<endl;
    largestNumber(myArray2,myArraySize2);
    cout<<endl;
    largestNumber(myArray3,myArraySize3);

    cout<<endl<<"****************************************"<<endl;

    /* Problem 8
     * Should print true (or 1) and then true (or 1) and then false (or 0)
    */
    cout <<"Problem 8"<<endl;

    isPalindrome(myArray,myArraySize);
    cout<<endl;

    isPalindrome(myArray2,myArraySize2);
    cout<<endl;

    isPalindrome(myArray3,myArraySize3);

    cout<<endl<<"****************************************"<<endl;

    /*Problem 9
     * Should print 12321, then 5, then 954345
    */
    cout <<"Problem 9"<<endl;
    listOfNum(myArray,myArraySize);
    cout<<endl;
    listOfNum(myArray2,myArraySize2);
    cout<<endl;
    listOfNum(myArray3,myArraySize3);
    cout<<endl<<"****************************************"<<endl;

    return 0;
}

// PROBLEM 2

bool isPrime(int x){
    int i=2;

    while(i<x){

        if(x%i!=0 & i==x-1){

            return true;
        }//if
        else if(x%i!=0 & i!=x-1){
            i++;
        }//else if
        else{
            return false;
        }//else
    }//while
    if(i>x){
        return false;
    }//if

}//isPrime

//PROBLEM 3


int theSum(int first, int second) {


    int count = 0;
    if (second>first){

        //x=x+1;
         for (first; first < second; first++) {

         count += first;
        }//for
         return count;
    }//if

    else if(first>second){

        //y=y+1;
        for (second; first>second;second++){

            count+=second;
        }//for
        return count;
    }//else if



}//theSum


//PROBLEM 4

int leapYear(int currentYear) {

    int limit = currentYear + 400; // Maximum year to observe

    for (currentYear; currentYear <= limit; currentYear++) {


        if ((currentYear % 4 == 0 && currentYear % 100 != 0) ||
            (currentYear % 4 == 0 && currentYear % 100 == 0 && currentYear % 400 == 0) && currentYear < limit) {

            cout << currentYear << endl;


        }//for


    }//leapYear
}


//PROBLEM 5

    int triangle(int endValue) {

        char space = ' ';

        int spacesInBetween = 1;

        for (int i = 1; i <= endValue; i++) {

            for (int j = 1; j <= endValue - i; j++) {
                cout << space;
            }//for
            cout << i;

            if (i > 1) {
                for (int k = 1; k <= spacesInBetween; k++) {
                    if (i < endValue)
                        cout << space;
                    else
                        cout << endValue;
                }//for
                spacesInBetween += 2; // after first center space, the center space increases by two
                cout << i;
            }//if
            cout << endl;
        }//for

    }//triangle




//PROBLEM 6


    int armstrong(int x) {

        for (int i = 0; i < x; i++) { // i is the digits between 1 and the parameter

            int sum = 0;

            int count = 0;// Number of digits in a number
            int j = i; //copy of i to avoid mutating it

            int k = i; // copy of i to avoid mutating it

            int sumOf = 0; // Sum of a number with each digit to the power of count

            while (j) { // Used to determine the number of digits in any given number

                j = j / 10;

                count += 1;

            }//while

            for (int l = 0; l < count; l++) { // increments from 1 to count

                sumOf += float(pow(k % 10, count));
                k = k / 10; // removes end digit of k (which is a copy of i)

            }//for
            if (i == sumOf) //
                cout << i << ' ';

        }//for



    }//armstrong

// PROBLEM 7

    int largestNumber(int x[], int size) {
        int largest = 0;
        for (int i = 0; i < size; i++) { //loop to iterate through array

            if (x[i] > largest) {

                largest = x[i];

            }//if

        }//for


        cout << largest;

    }//largestNumber

//PROBLEM 8


    bool isPalindrome(int x[], int size) {
        string combined_left; // puts (values in array) into string from left to right
        string combined_right;// puts (values in array) into a string from right to left

        for (int i = 0; i < size; i++) {

            int left = x[i];

            combined_left = to_string(left);


        }//for

        for (int j = size - 1; j >= 0; j--) {

            int right = x[j];

            combined_right = to_string(right);

        }//for


        cout << (combined_right == combined_left); // if they are the same, it is a Palindrome


    }//isPalindrome

//Problem 9

    int listOfNum(int x[], int size) {

        for (int i = 0; i < size; i++) {

            cout << x[i];
        }//for

    } //listOfNum

