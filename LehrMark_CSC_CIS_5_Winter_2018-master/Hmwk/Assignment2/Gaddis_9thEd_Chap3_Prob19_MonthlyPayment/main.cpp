/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on January 9, 2018, 10:50 AM
 * Purpose:  Monthly Payment
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
const float HLFPNY=5e-3f;//Half a penny
const int   SHIFT =100;//Shift 2 places

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float loan,   //Loan Amount in $'s
          mnPymnt,//Monthly Payment in $'s
          intRate,//Interest Rate/month
          totAmt, //Total Amount Paid for Loan in $'s
          intPaid;//Interest Paid in $'s
    char nPymnt;  //Number of Payments in months
    
    //Initialize Variables
    loan   =1e4f; //$10,000 Loan
    nPymnt =36;   //Number of payments
    intRate=1e-2f;//1%/month is the interest rate
    
    //Process/Map inputs to outputs
    float util=pow(1+intRate,nPymnt);//Utility variable to make code faster
    mnPymnt=util*intRate*loan/(util-1);
    int iPymnt=(mnPymnt+HLFPNY)*SHIFT;//Half Penny,Shift left,truncate;
    mnPymnt=static_cast<float>(iPymnt)/SHIFT;//Shift result back right
    totAmt=nPymnt*mnPymnt;
    intPaid=totAmt-loan;
    
    //Output Loan Parameters
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Loan Calculator"<<endl;
    cout<<"Loan amount          = $"<<loan<<endl;
    cout<<"Interest rate        = "<<setw(9)<<intRate*1200<<"%/year"<<endl;
    cout<<"Number of months     = "<<setw(6)<<static_cast<int>(nPymnt)<<endl;
    cout<<"Monthly Loan Payment = $"<<setw(8)<<mnPymnt<<endl;
    cout<<"Total Amount Paid    = $"<<totAmt<<endl;
    cout<<"Interest Paid        = $"<<setw(8)<<intPaid<<endl;
    
    //Exit stage right!
    return 0;
}