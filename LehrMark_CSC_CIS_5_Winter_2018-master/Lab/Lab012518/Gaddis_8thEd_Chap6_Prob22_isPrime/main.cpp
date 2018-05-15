/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on January 25, 2018, 12:45 PM
 * Purpose:  isPrime function
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cmath>     //Math Library
#include <iomanip>   //Formatting Library
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
bool isPrime(int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    
    //Initialize Variables
    
    //Process/Map inputs to outputs
    for(int i=2;i<=100;i++){
        cout<<setw(3)<<i<<(isPrime(i)?" is ":" is not ")<<"Prime"<<endl;
    }
    
    //Output data
    
    //Exit stage right!
    return 0;
}

bool isPrime(int n){
    bool test=true;
    float nLoop=sqrt(n);
    for(int num=2;num<=nLoop&&test;num++){
        if(n%num==0)test=false;
    }
    return test;
}