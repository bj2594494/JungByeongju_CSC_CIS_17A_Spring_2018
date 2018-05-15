/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on January 24, 2018, 10:20 AM
 * Purpose:  Factorial
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
    unsigned int n,fact;
    
    //Initialize Variables
    cout<<"This program solves the factorial n!"<<endl;
    cout<<"Input an integer n"<<endl;
    cin>>n;
    
    //Process/Map inputs to outputs
    fact=1;
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    
    //Output data
    cout<<n<<"!="<<fact<<endl;
    
    //Exit stage right!
    return 0;
}