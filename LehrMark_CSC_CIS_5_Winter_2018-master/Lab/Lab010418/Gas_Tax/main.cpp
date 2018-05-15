/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 4th, 2018  12:15PM
 * Purpose:  Gasoline Taxes
 * Oil Company Profit -> 7cents/gallon to 6.5% https://www.forbes.com/2011/05/10/oil-company-earnings.html#6c3f9a9f2dc8
 * Taxes -> http://www.latimes.com/politics/essential/la-pol-ca-essential-politics-updates-california-s-increased-gas-tax-goes-into-1509552219-htmlstory.html
 *          Fed Tax -> 18.4 cents/gallon
 *          State Tax -> 41.7 cents/gallon
 *          State Sales Tax -> 2.25%
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float base,slsTax,caTax,usTax,regGas,totTax;
    
    //Initialize values here
    slsTax=2.25e-2f;//California sales tax on gas -> 2.25%
    caTax =4.17e-1f;//41.7 cents/gallon
    usTax =1.84e-1f;//18.4 cents/gallon
    regGas=2.75;    //$2.75/gallon
    
    //Process/Calculations Here
    base=(regGas-usTax-caTax)/(1+slsTax);//Base price of a gallon of gas
    totTax=usTax+caTax+base*slsTax;      //Total tax on a gallon of gas
    
    //Output Located Here
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"The total tax on a gallon of gas   = $"<<setw(6)
            <<totTax<<endl;
    cout<<"The base price for a gallon of gas = $"<<setw(6)
            <<base<<endl;
    cout<<"Percentage price due to gas tax    =  "<<setw(6)
            <<totTax/base*100<<"%"<<endl;
    cout<<"Oil Company profit range           =  "<<setw(6)
            <<.07/base*100<<"% to 6.5%"<<endl;

    //Exit
    return 0;
}