/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 19, 2016, 9:07 AM
 * Purpose:  Home Calculator
*/

//System Libraries Here
#include <iostream>  //I/O Library
#include <iomanip>   //Format Currency
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const char PERCENT=100;//Percent Conversion

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float purcPrc, intRate, percDep, loanAmt, mthPay;
    float blonPay, lstPay, sumInt, totPd1,totPd2;
    float savings;
    
    //Input or initialize values Here
    purcPrc=250000.0f;           //Purchase price of the home in $'s
    intRate=0.04f,               //Interest Rate/Year
    percDep=0.10f,               //Percentage Deposit
    loanAmt=purcPrc*(1-percDep); //Loan amount in $'s
    mthPay=1074.19f;             //Monthly Payment
    
    
    //Process/Calculations and Display
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Calculate the Home Loan Payment"<<endl;
    cout<<"Purchase Price     = $"<<purcPrc<<endl;
    cout<<"Interest Rate      = "<<intRate*PERCENT<<"%"<<endl;
    cout<<"Percentage Deposit = "<<percDep*PERCENT<<"%"<<endl;
    cout<<"Loan Amount        = $"<<loanAmt<<endl;
    cout<<"Monthly Payment    = $"<<mthPay<<endl;

    cout<<endl<<"Month           Loan       Interest        "
        <<"Payment      Principle"<<endl;
    int nMonths=360;
    for(int month=0;month<nMonths;month++){
        float inEndMn=loanAmt*intRate/12;
        float prnPay=mthPay-inEndMn;
        cout<<setw(5)<<month
                <<setw(15)<<loanAmt
                <<setw(15)<<inEndMn
                <<setw(15)<<mthPay
                <<setw(15)<<prnPay<<endl;
        loanAmt+=(inEndMn-mthPay);
    }
    cout<<"Final Payment at month "<<nMonths<<" = $"<<mthPay+loanAmt<<endl;
    
    //Exit stage right!
    return 0;
}

