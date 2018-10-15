/* Jake Allport
 * Eeshita Biswas
 * 9/27/17
 * This file contains functions for PART2 of LAB3. The functions aren't necessarily related
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



int main() {
//Local variable declaration
    srand((time(NULL)));

    int arrayLength1 = (25+(rand() % (49 - 25 + 1))); // Sets random array length between 25 and 49

    int arrayHigh1=(5+(rand()%(9-5+1))); // sets the max high value of the array between 5 and 9

    int arrayLow1 = -10+(rand() % (-5-(-10)+1)); // sets the max low value of the array between -10 and -5

    int i=0;

    int window =5;

    int sum=0;


    cout<<"************************** PROBLEM 1 ************************"<<endl;

    filter::prob1(arrayLength1,arrayHigh1,arrayLow1);
    cout<<"************************** PROBLEM 2 ************************"<<endl;

    filter::prob2(&arrayLength1,&arrayHigh1,&arrayLow1,i);
    cout<<"************************** PROBLEM 3 ************************"<<endl;

    filter::prob3(filter::prob1(arrayLength1,arrayHigh1,arrayLow1),arrayHigh1,arrayLength1);

    cout<<endl<<"************************** PROBLEM 4 ************************"<<endl;

    filter::prob4( filter::prob1(arrayLength1,arrayHigh1,arrayLow1),&sum,window,arrayLength1);
    cout<<"************************** PROBLEM 5 ************************"<<endl;

    filter::prob5( filter::prob1(arrayLength1,arrayHigh1,arrayLow1),arrayLength1,window);
    cout<<"************************** PROBLEM 6 ************************"<<endl;

    filter::prob6( filter::prob1(arrayLength1,arrayHigh1,arrayLow1),arrayLength1,arrayHigh1,arrayLow1);

    return 0;
}
