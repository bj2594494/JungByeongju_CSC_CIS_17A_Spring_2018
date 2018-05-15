/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 19, 2016, 9:07 AM
 * Purpose:  Retirement
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
    float salary, invRate, savReqd, percDep;
    float savings;
    int count,year;
    
    //Input or initialize values Here
    salary=100000.0f;//Salary in $'s
    invRate=0.05f;   //Investment rate from Cal-Muni Bonds
    savReqd=salary/invRate;//Savings Required $'s
    percDep=0.10f;//Percentage Salary Deposited each year
    savings=0.0f;//Retirement Savings at the start
    
    //Process/Calculations and Display
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Yearly Salary = $"<<salary<<endl;
    cout<<"Municipal Bond Rate = "<<invRate*PERCENT<<"%"<<endl;
    cout<<"Savings Required = $"<<savReqd<<endl;
    cout<<"Percentage Yearly Deposit = "<<percDep*PERCENT<<"%"<<endl;
    cout<<endl<<"Count Year     Savings  Interest   Deposit"<<endl;
    for(count=0,year=2022;savings<savReqd;count++,year++){
        float inEndYr=savings*invRate;
        float dpEndYr=salary*percDep;
        cout<<setw(5)<<count
                <<setw(5)<<year
                <<setw(12)<<savings
                <<setw(10)<<inEndYr
                <<setw(10)<<dpEndYr<<endl;
        savings+=(inEndYr+dpEndYr);
    }
    cout<<"Your Retirement savings = $"<<savings;
    cout<<" when you retire "<<count<<" years = "<<year<<endl;
    
    //Exit stage right!
    return 0;
}

