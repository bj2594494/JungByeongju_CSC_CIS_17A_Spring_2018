/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on January 23, 2018, 10:10 AM
 * Purpose:  Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream> //I/O Library
#include <cmath>    //Math Library
#include <iomanip>  //Formatting Library
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
const int PERCENT=100;//Percentage Conversion

//Function Prototypes
float ftrVal1(float,float,int);//Power Function
float ftrVal2(float,float,int);//Log/Exponential Function
float ftrVal3(float,float,int);//For-Loop Function
float ftrVal4(float,float,int);//Recursion Function
float ftrVal1(float,float,float);//Overloaded
float ftrVal5(float,float,int=12);//Defaulted Parameter
void  ftrVal6(float &,float,int);//Pass By Reference
int   ftrVal7(float &,float,int);//Static Local Variable



//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float pVal, //Present Value in $'s
       invRate; //Investment Rate in decimal
    int nCmpnd; //Number of compounding periods #months, years, etc...
    
    //Initialize Variables
    pVal=100;//100 Dollars in Savings
    nCmpnd=12;//12 years
    invRate=static_cast<float>(72)/nCmpnd/PERCENT;//By rule of 72
    
    //Output data
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Present Value = $"<<pVal<<endl;
    cout<<"Number of compounding Periods = "<<nCmpnd<<" years"<<endl;
    cout<<"Interest Rate = "<<invRate*PERCENT<<"%"<<endl;
    cout<<"Future Value Power Function       = $"
            <<ftrVal1(pVal,invRate,nCmpnd)<<endl;
    cout<<"Future Value Exp/Log Function     = $"
            <<ftrVal2(pVal,invRate,nCmpnd)<<endl;
    cout<<"Future Value For-Loop Function    = $"
            <<ftrVal3(pVal,invRate,nCmpnd)<<endl;
    cout<<"Future Value Recursion Function   = $"
            <<ftrVal4(pVal,invRate,nCmpnd)<<endl;
    float fCmpnd=nCmpnd;
    cout<<"Future Value Overloaded Function  = $"
            <<ftrVal1(pVal,invRate,fCmpnd)<<endl;
    cout<<"Future Value Defaulted Function   = $"
            <<ftrVal5(pVal,invRate)<<endl;
    float fpv=pVal;
    ftrVal6(fpv,invRate,nCmpnd);
    cout<<"Future Value Pass By Reference    = $"
            <<fpv<<endl;
    for(int loop=1;loop<=4;loop++){
        fpv=pVal;
        ftrVal7(fpv,invRate,nCmpnd);
    }
    fpv=pVal;
    int nTime=ftrVal7(fpv,invRate,nCmpnd);
    cout<<"Future Value Static Variable      = $"
            <<fpv<<endl;
    cout<<"Static Function was called "<<nTime<<" times"<<endl;
    
    
    //Exit stage right!
    return 0;
}

int ftrVal7(float &fpv,float i,int n){
    static int count=0;
    for(int years=1;years<=n;years++){
        fpv*=(1+i);
    }
    return ++count;
}

void ftrVal6(float &fpv,float i,int n){
    for(int years=1;years<=n;years++){
        fpv*=(1+i);
    }
}

float ftrVal5(float pv,float i,int n){
    for(int years=1;years<=n;years++){
        pv*=(1+i);
    }
    return pv;
}

float ftrVal1(float pv,float i,float n){
    return pv*pow(1+i,n);
}

float ftrVal4(float pv,float i,int n){
    if(n<=0)return pv;//Base Condition
    return ftrVal4(pv,i,n-1)*(1+i);
}

float ftrVal3(float pv,float i,int n){
    for(int years=1;years<=n;years++){
        pv*=(1+i);
    }
    return pv;
}

float ftrVal2(float pv,float i,int n){
    return pv*exp(n*log(1+i));
}


float ftrVal1(float pv,float i,int n){
    return pv*pow(1+i,n);
}