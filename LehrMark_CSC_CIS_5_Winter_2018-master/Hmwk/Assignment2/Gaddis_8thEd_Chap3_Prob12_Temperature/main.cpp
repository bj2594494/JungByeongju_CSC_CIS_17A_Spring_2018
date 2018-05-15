/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on January 9, 2018, 1:36 PM
 * Purpose:  Calculating Temperature
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
    float degF,degC,dgChk;
    float x1,x2,y1,y2;
    
    //Initialize Variables
    x1=32; //Interpolation 32 degrees Fahrenheit
    x2=212;//Interpolation 212 degrees Fahrenheit
    y1=0;  //Interpolation 0 degrees centigrade
    y2=100;//Interpolation 100 degrees centigrade
    
    //Input the temperature to convert
    cout<<"Input the temperature in degrees Fahrenheit"<<endl;
    cout<<"to convert to degrees Celsius"<<endl;
    cin>>degF;
    
    //Process/Map inputs to outputs
    degC=5.0f/9*(degF-32);
    dgChk=y1+(y2-y1)*(degF-x1)/(x2-x1);
 
    //Output data
    cout<<degF<<" degrees Fahrenheit = "
            <<dgChk<<" degrees Celsius = "
            <<degC<<" degrees Celsius"<<endl;
    
    //Exit stage right!
    return 0;
}