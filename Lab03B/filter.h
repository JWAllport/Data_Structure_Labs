/* Jake Allport
 * Eeshita Biswas
 * 9/27/17
 * This file contains functions for PART2 of LAB3. The functions aren't necessarily related
 * in any way other than that they are required for lab1.
*/

#ifndef LAB3_FILTER_H
#define LAB3_FILTER_H

#include <iostream>
#include <math.h>
#include <array>
#include<string>
#include <time.h>
#include <algorithm>

class filter {
    /*
    int* array;
    int* filteredArray;
    int lowValue;
    int highValue;
    int length;
    int weight;
    int window;
*/


public:

    int arrayLength1 = (25+(rand() % (49 - 25 + 1))); // Sets random array length between 25 and 49

    int arrayHigh1=(5+(rand()%(9-5+1))); // sets the max high value of the array between 5 and 9

    int arrayLow1 = -10+(rand() % (-5-(-10)+1)); // sets the max low value of the array between -10 and -5

    int i=0;

    int window =5;


    static int* prob1(int, int , int);

    static int prob2(int*, int*, int*, int);

    static void prob3(int[],int,int);


    static void prob4(int[], int*, int, int);

    static int* prob5(int[], int, int);

    static int prob6(int[], int, int, int);

};
// Filter header



#endif //LAB3_FILTER_H
