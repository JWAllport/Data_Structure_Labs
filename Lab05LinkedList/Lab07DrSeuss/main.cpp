#include <iostream>
#include <time.h>
#include "makeSeuss.h"
makeSeuss *seuss1(string,string,bool,bool);

makeSeuss *seuss2(string,string,bool,bool);

makeSeuss *seuss3(string,string,bool,bool);

makeSeuss *seuss4(string,string,bool,bool);

using namespace std;


int main() {

    srand(time(NULL));


   makeSeuss *seuss1 = new makeSeuss("DrSeuss","output",true,true);

    makeSeuss *seuss2= new makeSeuss("DrSeuss","output",true,false);

    makeSeuss *seuss3= new makeSeuss("DrSeuss","output",false,true);

    makeSeuss *seuss4= new makeSeuss("DrSeuss","output",false,false);





    return 0;
}
