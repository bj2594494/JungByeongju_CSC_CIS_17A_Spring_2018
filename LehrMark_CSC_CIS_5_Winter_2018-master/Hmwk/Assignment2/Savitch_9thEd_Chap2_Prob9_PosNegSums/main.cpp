/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on January 9, 2018, 12:36 PM
 * Purpose:  Calculating Pos/Neg/Sums for 10 numbers
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
    int number,negSum,posSum;
    
    //Initialize Variables
    negSum=posSum=0;
    
    //Process/Map inputs to outputs
    //Heading
    cout<<"This program adds 10 numbers"<<endl;
    cout<<"It determines the negative, positive and total sum"<<endl;
    cout<<"Input 10 numbers, 1 at a time"<<endl;
    
    cin>>number;
    negSum+=number<0?number:0;
    posSum+=number>0?number:0;
    
    cin>>number;
    negSum+=number<0?number:0;
    posSum+=number>0?number:0;
    
    cin>>number;
    negSum+=number<0?number:0;
    posSum+=number>0?number:0;
   
    cin>>number;
    negSum+=number<0?number:0;
    posSum+=number>0?number:0;
    
    cin>>number;
    negSum+=number<0?number:0;
    posSum+=number>0?number:0;
    
    cin>>number;
    negSum+=number<0?number:0;
    posSum+=number>0?number:0;
    
    cin>>number;
    negSum+=number<0?number:0;
    posSum+=number>0?number:0;
    
    cin>>number;
    negSum+=number<0?number:0;
    posSum+=number>0?number:0;
    
    cin>>number;
    negSum+=number<0?number:0;
    posSum+=number>0?number:0;
    
    cin>>number;
    negSum+=number<0?number:0;
    posSum+=number>0?number:0;
    
    //Output data
    cout<<"The negative sum = "<<negSum<<endl;
    cout<<"The positive sum = "<<posSum<<endl;
    cout<<"The total sum    = "<<negSum+posSum<<endl;
    
    //Exit stage right!
    return 0;
}