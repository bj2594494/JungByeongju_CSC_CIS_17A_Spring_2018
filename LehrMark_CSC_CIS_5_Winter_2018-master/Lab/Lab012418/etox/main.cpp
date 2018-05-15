/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on January 24, 2018, 10:20 AM
 * Purpose:  etox
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned int n,fact,nterms;
    float etox,x;
    
    //Initialize Variables
    cout<<"This program solves the e^x sequence"<<endl;
    cout<<"Input x and the number of terms in the sequence"<<endl;
    cout<<"Number of terms >= 0"<<endl;
    cin>>x>>nterms;
    
    //Process/Map inputs to outputs
    etox=0;
    for(int n=0;n<nterms;n++){
        fact=1;
        for(int i=1;i<=n;i++){
            fact*=i;
        }
        etox+=pow(x,n)/fact;
    }
    
    //Output data
    cout<<"e^"<<x<<"="<<etox<<" with "<<nterms<<" terms"<<endl;
    cout<<"e^"<<x<<"="<<exp(x)<<" with the math library"<<endl;
    //Exit stage right!
    return 0;
}