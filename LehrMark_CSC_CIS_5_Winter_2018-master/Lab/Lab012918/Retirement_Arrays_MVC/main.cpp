/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 29th, 2018, 10:10 AM
 * Purpose:  Retirement using arrays modeled after MVC
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
    const int SIZE=100;//Maximum number of years to work
    float salary, invRate, savReqd, percDep;
    float savings[SIZE],inEndYr[SIZE],dpEndYr[SIZE];
    int count,year[SIZE];
    
    //Input or initialize values Here
    salary=100000.0f;//Salary in $'s
    invRate=0.05f;   //Investment rate from Cal-Muni Bonds
    savReqd=salary/invRate;//Savings Required $'s
    percDep=0.10f;//Percentage Salary Deposited each year
    savings[0]=0.0f;//Retirement Savings at the start
    
    //Display the Headings
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Yearly Salary = $"<<salary<<endl;
    cout<<"Municipal Bond Rate = "<<invRate*PERCENT<<"%"<<endl;
    cout<<"Savings Required = $"<<savReqd<<endl;
    cout<<"Percentage Yearly Deposit = "<<percDep*PERCENT<<"%"<<endl;
    cout<<endl<<"Count Year     Savings  Interest   Deposit"<<endl;
    
    //Calculate the Parallel Arrays
    for(count=0,year[0]=2022;savings[count]<savReqd;
            count++,year[count]=year[count-1]+1){
        inEndYr[count]=savings[count]*invRate;
        dpEndYr[count]=salary*percDep;
        savings[count+1]=savings[count]+
                (inEndYr[count]+dpEndYr[count]);
    }
    
    //Display the previously Calculated Arrays
    for(count=0;savings[count]<savReqd;count++){
        cout<<setw(5)<<count
                <<setw(5)<<year[count]
                <<setw(12)<<savings[count]
                <<setw(10)<<inEndYr[count]
                <<setw(10)<<dpEndYr[count]<<endl;
    }
    cout<<"Your Retirement savings = $"<<savings[count];
    cout<<" when you retire "<<count<<" years = "<<year[count]<<endl;
    
    //Exit stage right!
    return 0;
}