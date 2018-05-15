/*
 * File:   main.cpp
 * Author: Byeongju Jung
 * Created on April 2, 2018, 1:20 PM
 * Purpose: Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare Variables
    long number=1;
    for(int i=1;i<=25;i++){
        number*=i;
        cout<<fixed;
        //cout<<i<<" "<<number<<endl;
    }
    //Initialize Variables
    
    //Process/Map inputs to outputs
    
    //Output data
    cout<<"Prob 5, factorial problem:"<<endl;
    cout<<"a. largest factorial for char:     5!, unsigned char:     6!"<<endl;
    cout<<endl;
    cout<<"b. largest factorial for short:    7!, unsigned short:    8!"<<endl;
    cout<<"   largest factorial for int:     12!, unsigned int:     12!"<<endl;
    cout<<"   largest factorial for long:    20!, unsigned long:    20!"<<endl;
    cout<<"   largest factorial for float:   34!"<<endl;
    cout<<"   largest factorial for double: 170!"<<endl;
    cout<<"   largest factorial for long double: 1754!"<<endl;
    //Exit stage right!
    return 0;
}

