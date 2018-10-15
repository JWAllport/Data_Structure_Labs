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

using namespace std;

int *prob1(int *arrayLength,int *arrayHigh,int *arrayLow);
void prob2(int *arrayLength,int *arrayHigh,int *arrayLow,int i);
void prob3(int[],int);
void prob4(int *array,int *sum,int window,int randLength);
int * prob5(int[], int,int);
int prob6(int array[],int,int,int);
//void prob4 (int[],int);

int main() {
//Local variable declaration
    srand((time(NULL)));
    int arrayLength;
    int arrayHigh;
    int arrayLow;
    int arrayLength_2;
    int arrayHigh_2;
    int arrayLow_2;

    int i=0;
    cout<<"************************** PROBLEM 1 ************************"<<endl;

    prob1(&arrayLength,&arrayHigh,&arrayLow);


    cout<<endl;
    cout<<"************************** PROBLEM 2 ************************"<<endl;
    prob2(&arrayLength,&arrayHigh,&arrayLow,i);

    cout<<"************************** PROBLEM 3 ************************"<<endl;
    int prob3array[]={4,3,4,5,3,2};


    prob3(prob3array,6);

    cout<<endl<<endl;
    cout<<"************************** PROBLEM 4 ************************"<<endl;
    int randLength= 13; // The size of the array
    int sum=0; // Value that holds the average of current window
    int prob4Array[randLength]; // Initializes array to be observed. To manually set array do that here, remove random generator
    int window=5; // The size of the window
    cout<<"The array is: ";

    for(int i=0;i<randLength;i++) { // Creates a random array of length specified in randLength
        int randVal = -10 + (rand() % (20-(-10)+1)); // random values between -10 and 20
        cout << randVal;
            cout << " ";

        prob4Array[i]=randVal; // The array builder, sets random values to the array of position i (0-randLength)
    }
    for (int i=0;i<=randLength-window;i++){ // Prevents window sizes for exceeding array boundaries (length-window)
        prob4(&prob4Array[i],&sum,window,randLength); // Sends the array @ position i, the hanning (and averaged) sum, window size, and array length through the function

    }

    cout<<endl<<"************************** PROBLEM 5 ************************"<<endl;

    //int prob5array[35]={6, -2, -4, 5, -3, -4, -3, -1, 5, 2, -2, 0, -7, 2, -3, -4, -3, -1, -5, -3, 1, 7, 3, -7, -7, 3, -8, 1, -5, -4, -2, -5, -8, 0, -4};
    //int size=35;
    //int window5=13;


    //prob5(prob5array,size,window5); // Function is called in Function six.



    cout<<endl<<"************************** PROBLEM 6 ************************"<<endl;


    prob6(prob1(&arrayLength,&arrayHigh,&arrayLow),arrayLength,arrayHigh,arrayLow); // using random array from problem 4



    return 0;
}

//************ PROBLEM 1***************

int *prob1(int *arrayLength,int *arrayHigh,int *arrayLow) {

    int randLength = 25+(rand() % (49 - 25 + 1)); // Sets random array length between 25 and 49

    int randHigh=5+(rand()%(9-5+1)); // sets the max high value of the array between 5 and 9

    int randLow = -10+(rand() % (-5-(-10)+1)); // sets the max low value of the array between -10 and -5

    int *prob1Array;

    prob1Array= new int[randLength];

    for (int i = 0; i < randLength; i++) {


        prob1Array[i] = randLow+(rand() % (randHigh - randLow + 1)); // Creates array with the random values

        /*
        cout << prob1Array[i];
        if (i < randLength - 1) {
            cout << ",";
        }
         */
    }//for
    *arrayLength=randLength;
    *arrayHigh=randHigh;
    *arrayLow=randLow;

    //cout<<endl<<"ArrayLength: "<<*arrayLength<<endl<<"ArrayHigh: "<<*arrayHigh<<endl<<"ArrayLow: "<<*arrayLow<<endl;

    return prob1Array;
}

//************ PROBLEM 2***************

void prob2(int *arrayLength_2,int *arrayHigh_2,int *arrayLow_2,int i){

    int randLength = 25+(rand() % (49 - 25 + 1));

    int randHigh2=5+(rand()%(9-5+1));

    int randLow2 = -10+(rand() % (-5-(-10)+1));

    int prob1Array[randLength];

    if (i<randLength){
        prob1Array[i]=randLow2+rand()%(randHigh2-randLow2+1);

        cout<<prob1Array[i]<<" ";

        return prob2(arrayLength_2,arrayHigh_2,arrayLow_2,i+1);


    }//if

    *arrayLength_2=randLength;
    *arrayHigh_2=randHigh2;
    *arrayLow_2=randLow2;
    cout<<endl<<"ArrayLength: "<<*arrayLength_2<<endl<<"ArrayHigh: "<<*arrayHigh_2<<endl<<"ArrayLow: "<<*arrayLow_2<<endl;
}

//************ PROBLEM 3***************



void prob3(int prob1Array[],int randHigh){

    for (int i=0;i<randHigh;i++){
        cout<<prob1Array[i];
        if(i<randHigh-1){
            cout<<" ";
        }//if
    }//for
}
//************ PROBLEM 4***************

void prob4(int prob4array[],int *sum,int window,int randLength){
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


//********************* PROBLEM 5 *******************

int * prob5(int prob5array[], int size,int window) {

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
//***************** PROBLEM 6 *******************************

int prob6(int prob6array[],int size6,int high6,int low6){
    int window6=13;

    cout<<"Size is: "<<size6;
    cout<<endl<<"High is: "<<high6;
    cout<<endl<<"Low is: "<<low6;
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
    for(int i=high6;i>=low6;i--){ // prints the max low to max high values vertically
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
    for(int i=high6;i>=low6;i--){
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
