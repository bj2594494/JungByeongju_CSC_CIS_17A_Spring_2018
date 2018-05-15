/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 8th, 2018  12:15PM
 * Purpose:  How are federal interest payments tied to the interest rate
 * Federal Debt   -> 20.6   trillion http://www.usdebtclock.org/
 * Federal Budget ->  4.094 trillion https://en.wikipedia.org/wiki/2018_United_States_federal_budget
 * US GDP ->         20.2 trillion https://www.thebalance.com/us-economic-outlook-3305669
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const float TRLLN=1e12f;//1x10^12 = Trillion
const float BLLN=1e09f;//1x10^12 = Trillion
const int   PRCNT=100;  //Conversion to Percent

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float fedDebt,intRate,intPymnt,fedBdgt,pctFed,usGDP;
    
    //Initialize values here
    fedDebt=20.6e12f; //Federal Debt         = 20.6  Trillion as of 1/8/18
    fedBdgt=4.094e12f;//Federal 2018 Budget  = 4.094 Trillion
    usGDP=20.2e12f;   //US GDP 2018          = 20.2  Trillion
    
    //Initial Output and Setup
    cout<<fixed<<showpoint;
    cout<<setprecision(3);
    cout<<"The Federal Budget            = $"<<setw(8)
            <<fedBdgt/TRLLN<<" trillion"<<endl;
    cout<<"The Federal Debt              = $"<<setw(8)
            <<fedDebt/TRLLN<<" trillion"<<endl;
    cout<<"The US Gross Domestic Product = $"<<setw(8)
            <<usGDP/TRLLN<<" trillion"<<endl;
    cout<<"The Federal Debt is "<<fedDebt/fedBdgt<<" times the Budget"<<endl;
    cout<<"The Federal Debt is "<<fedDebt/usGDP*PRCNT<<" % of US GDP"<<endl;
    cout<<setprecision(1);
    
    //Calculate and output the interest payments
    intRate=0.005;//1/2 percent/year interest rate on Federal Debt
    intPymnt=fedDebt*intRate;
    pctFed=intPymnt/fedBdgt*PRCNT;
    cout<<"With interest rate = "<<intRate*PRCNT<<"% the interest payment of $"
            <<intPymnt/BLLN<<" billions = "<<pctFed<<" % of Federal Budget"<<endl;
    
    //Calculate and output the interest payments
    intRate*=2;//1 percent/year interest rate on Federal Debt
    intPymnt=fedDebt*intRate;
    pctFed=intPymnt/fedBdgt*PRCNT;
    cout<<"With interest rate = "<<intRate*PRCNT<<"% the interest payment of $"
            <<intPymnt/BLLN<<" billions = "<<pctFed<<" % of Federal Budget"<<endl;
    
    //Calculate and output the interest payments
    intRate*=2;//2 percent/year interest rate on Federal Debt
    intPymnt=fedDebt*intRate;
    pctFed=intPymnt/fedBdgt*PRCNT;
    cout<<"With interest rate = "<<intRate*PRCNT<<"% the interest payment of $"
            <<intPymnt/BLLN<<" billions = "<<pctFed<<" % of Federal Budget"<<endl;
    
    //Calculate and output the interest payments
    intRate*=2;//2 percent/year interest rate on Federal Debt
    intPymnt=fedDebt*intRate;
    pctFed=intPymnt/fedBdgt*PRCNT;
    cout<<"With interest rate = "<<intRate*PRCNT<<"% the interest payment of $"
            <<intPymnt/BLLN<<" billions = "<<pctFed<<" % of Federal Budget"<<endl;

    
    //Exit
    return 0;
}