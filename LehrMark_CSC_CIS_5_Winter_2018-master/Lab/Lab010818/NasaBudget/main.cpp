/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 4th, 2018  12:15PM
 * Purpose:  How big is NASA's budget?
 * Federal Budget ->  4.094 trillion https://en.wikipedia.org/wiki/2018_United_States_federal_budget
 * NASA Budget -> 19.1 billion https://www.nasa.gov/press-release/nasa-acting-administrator-statement-on-fiscal-year-2018-budget-proposal-0
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const float BLLN=1e9f;  //1x10^9  = Billion
const float TRLLN=1e12f;//1x10^12 = Trillion
const int   PRCNT=100;  //Conversion to Percent

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float nasaBdg,fedBdgt,nasaPct;
    
    //Initialize values here
    nasaBdg=19.1e09f;//NASA Budget = 19.1 Billion
    fedBdgt=4.094e12f;//Federal Budget  = 4.094 Trillion
    
    //Process/Calculations Here
    nasaPct=nasaBdg/fedBdgt*PRCNT;//Percentage NASA of Total Budget
    
    //Output Located Here
    cout<<fixed<<setprecision(1)<<showpoint;
    cout<<"The NASA Budget     = $"<<setw(6)
            <<nasaBdg/BLLN<<"   billion"<<endl;
    cout<<setprecision(3);
    cout<<"The Federal Budget  = $"<<setw(8)
            <<fedBdgt/TRLLN<<" trillion"<<endl;
    cout<<setprecision(2);
    cout<<"The NASA Percentage = "<<setw(8)
            <<nasaPct<<"  percent"<<endl;
    
    //Exit
    return 0;
}