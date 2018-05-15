/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on January 2, 2018, 1:30 PM
 * Purpose:  Add 2 numbers
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    short a,b,c;//Three integer variables
    
    //Initialize Variables
    a=2000;
    b=3000;
    
    //Process/Map inputs to outputs
    c=a+b;
    
    //Output data
    cout<<c<<" = "<<a<<" + "<<b<<endl;
    
    //Exit stage right!
    return 0;
}