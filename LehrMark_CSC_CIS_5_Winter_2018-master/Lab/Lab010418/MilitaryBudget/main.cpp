/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 4th, 2018  12:15PM
 * Purpose:  How big is military budget?
 * Federal Budget ->  4.094 trillion https://en.wikipedia.org/wiki/2018_United_States_federal_budget
 * Military Budget -> 639.1 billion http://comptroller.defense.gov/Portals/45/Documents/defbudget/fy2018/fy2018_Press_Release.pdf
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
    float milBdgt,fedBdgt,mlPrcnt;
    
    //Initialize values here
    milBdgt=639.1e09f;//Military Budget = 639.1 Billion
    fedBdgt=4.094e12f;//Federal Budget  = 4.094 Trillion
    
    //Process/Calculations Here
    mlPrcnt=milBdgt/fedBdgt*PRCNT;//Percentage Military of Total Budget
    
    //Output Located Here
    cout<<fixed<<setprecision(1)<<showpoint;
    cout<<"The Military Budget = $"<<setw(8)
            <<milBdgt/BLLN<<" billion"<<endl;
    cout<<setprecision(3);
    cout<<"The Federal Budget  = $"<<setw(8)
            <<fedBdgt/TRLLN<<" trillion"<<endl;
    cout<<setprecision(2);
    cout<<"The Military Percentage = "<<
            mlPrcnt<<" percent"<<endl;
    
    //Exit
    return 0;
}