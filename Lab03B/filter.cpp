/*
 * File:   main.cpp
 * Author: Jake Allport
 *
 *
 */

/* Jake Allport
 * Eeshita Biswas
 * 9/27/17
 * This file contains functions for PART1 of LAB3. The functions aren't necessarily related
 * in any way other than that they are required for lab1.
*/

#include <iostream>
#include <math.h>
#include <array>
#include<string>
#include <time.h>
#include <algorithm>

#include "filter.h"

using namespace std;


//************ PROBLEM 1***************

int* filter::prob1(int arrayLength1,int highvalue1,int arrayLow1) {


    int *prob1Array;

    prob1Array= new int[arrayLength1];

    for (int i = 0; i < arrayLength1; i++) {


        prob1Array[i] = arrayLow1+(rand() % (highvalue1 - arrayLow1 + 1)); // Creates array with the random values
        cout<<prob1Array[i]<<" ";
    }//for

    cout<<endl<<"ArrayLength: "<<arrayLength1<<endl<<"ArrayHigh: "<<highvalue1<<endl<<"ArrayLow: "<<arrayLow1<<endl;

    return prob1Array;

}

int filter::prob2(int *arrayLength1, int *arrayHigh1, int *arrayLow1,int i){

    int prob1Array[*arrayLength1];

    if (i<*arrayLength1){
        prob1Array[i]= (*arrayLow1 + (rand() % (*arrayHigh1 - *arrayLow1 + 1)));

        cout<<prob1Array[i]<<" ";
        return prob2(arrayLength1,arrayHigh1,arrayLow1, i + 1);


    }//if


    cout<<endl<<"ArrayLength: "<<*arrayLength1<<endl<<"ArrayHigh: "<<*arrayHigh1<<endl<<"ArrayLow: "<<*arrayLow1<<endl;
}
void filter::prob3(int array[],int arrayHigh1,int arrayLength1){


    for (int i=0;i<arrayHigh1;i++){
        cout<<array[i]<<" ";

    }//for
}

void filter::prob4(int prob4array[],int *sum,int window,int randLength){

    cout<<endl;
    int acount=1; // The weights

    for (int i=0;i<=(window/2)+1;i++){

        if(acount==(window/2)+1){ // if statement is for decreasing the weights once the center is reached.
            while(acount>0){

                *sum+=(prob4array[i])*acount; // the value in the array times its weight
                cout<<"The weight of "<<prob4array[i]<<" is: "<<acount<<endl;
                acount--;
                i++;
            }

        }
        else if(acount!=0) {
            *sum += prob4array[i] * acount; // the value in the array times its weight
            cout<<"The weight of "<<prob4array[i]<<" is: "<<acount<<endl;
            acount++;
        }
    }
    *sum =*sum/randLength;

    //cout<<"The hanning average is: "<<*sum<<endl;
}


int * filter::prob5(int prob5array[], int size,int window) {

    int average = 0;
    int distancestart = (size - window);

    int *newarray;
    newarray = new int[size];

    //append zeros to begining of array
    for (int z = 0; z < ((size) - (distancestart + 1)) / 2; z++) {
        newarray[z] = 0;

    }
    //append zeros to end of array
    for (int z = size - 1; z >= size - (((size) - (distancestart + 1)) / 2); z--) {
        newarray[z] = 0;
    }


    for (int i = 0; i < (size - window) + 1; i++) { //for loop determines starting value of the window

        int weight = 1;
        int sum = 0;

        for (int j = i; j <= window + i; j++) { // for loop creates each window after starting point is determined
            if (weight == ((window) / 2 + 1)) { // once weight is equal to center of window, it starts decreasing
                while (weight > 0) {
                    sum += (prob5array[j]) * (weight);
                    weight--;
                    j++;
                }//while
            }//if
            else if (weight != 0) { // adds +1 to weight and adds value of the locationg in array times the weight to the sum
                sum += (prob5array[j]) * weight;
                weight++;
            }//else if

        }//for
        average = sum / size; // divides sum by the total size of the array

        newarray[i + ((size) - (distancestart + 1)) / 2] = average; // sets values in the array to average
        //cout<< newarray[i + ((size) - (distancestart + 1)) / 2];

    }//for

    //for (int z=0;z<size;z++){ // prints out the array
    //cout<<newarray[z];
    //}
    return newarray;

}

int filter::prob6(int prob6array[],int size6,int arrayHigh1,int arrayLow1){
    int window6=5;

    cout<<"Size is: "<<size6;
    cout<<endl<<"High is: "<<arrayHigh1;
    cout<<endl<<"Low is: "<<arrayLow1;
    cout<<endl;
    cout<<"Hanning window: ";
    for(int j=0;j<size6;j++){ // prints the array created in problem 5 with values for problem 6
        cout<<prob5(prob6array,size6,window6)[j]<<" ";
    }//for
    cout<<endl;
    cout<<"Array itself is: ";
    for (int i=0;i<size6;i++){// prints the array without the hanning window(applied by calling problem 5 above)
        cout<<prob6array[i]<<" ";
    }//for
    cout<<endl<<endl;
    // ************ for the array *****************
    for(int i=arrayHigh1;i>=arrayLow1;i--){ // prints the max low to max high values vertically
        cout<<i<<":";
        for(int k=0;k<size6;k++){ // iterates though length of array
            if(i==prob6array[k]){ // prints a * if i is equal to the position in the array (from k for loop)
                cout<<'*'<<"    ";
            }
            else{ // otherwise print a space
                cout<<" ";
            }

        }
        cout<<endl;
    }
    cout<<endl<<endl<<endl;


    //************* for hanning array ******************
    for(int i=arrayHigh1;i>=arrayLow1;i--){
        cout<<i<<":";
        for(int k=0;k<size6;k++){
            if(i==prob5(prob6array,size6,window6)[k]){
                cout<<'*'<<" ";
            }
            else{
                cout<<" ";
            }

        }
        cout<<endl;
    }


}
