/*
 * File:   main.cpp
 * Author: Byeongju Jung
 * Created on April 2, 2018, 1:20 PM
 * Purpose: Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>

#include "Array.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, conversions,
//                   2-D Array Dimensions

//Function Prototypes
void data(Data &);
Data *check(Data, float &);
Data *deposit(Data, float &);
//Execution Begins Here

int main(int argc, char** argv) {
    //Declare Variables
    Data client;
    Data *depot;
    Data *checks;
    float depoSum=0;
    float checSum=0;
    float balance;
    //Initialize Variables
    
    //Process/Map inputs to outputs
    cout<<"Prob 1, checking account problem."<<endl;
    data(client);
    checks=check(client,checSum);
    depot=deposit(client,depoSum);
    balance=client.balance-checSum+depoSum;
    //Output data
    cout<<endl;
    cout<<"Name: "<<client.name<<endl;
    cout<<"Address: "<<client.address<<endl;
    cout<<"Account Number: "<<client.account<<endl;
    cout<<"Balance at the beginning of the month: $"<<client.balance<<endl;
    cout<<"Total amount of checks: $"<<checSum<<endl;
    cout<<"Total amount of deposit: $"<<depoSum<<endl;
    if(balance<0){
        cout<<"Your account is overdrawn. Additional $15 is overdrawn"<<endl;
        balance-=15;
        cout<<"Current Balance: $"<<balance<<endl;
    }
    else{
        cout<<"Current Balance: $"<<balance<<endl;
    }
    //Exit stage right!
    return 0;
}

void data(Data &a){
    int m;
    cout<<"Enter your name."<<endl;
    getline(cin,a.name);
    cout<<"Enter your address."<<endl;
    getline(cin,a.address);
    cout<<"Enter Account Number."<<endl;
    cin>>a.account;
    m=a.account.length();
    while(m!=5){
        cout<<"Invalid Account."<<endl;
        cout<<"Enter Account Number."<<endl;
        cin>>a.account;
        m=a.account.length();
    }
    cin.ignore();
    cout<<"Enter yout balance at the beginning of the month."<<endl;
    cin>>a.balance;
}

Data *check(Data a, float &sum){
    cout<<"Enter the number of checks you have written this month."<<endl;
    cin>>a.nmCheck;
    //Is the size parameter valid
    if(a.nmCheck<=0)return 0;
    
    //Allocate the Structure pointer
    Data *array=new Data;
    array->size=a.nmCheck;
    
    //Allocate memory
    array->data=new float[array->size];
    
    for(int i=0;i<a.nmCheck;i++){
        cout<<"Enter the amount of money you have written for check "<<i+1<<endl;
        cin>>array->data[i];
        sum+=array->data[i];
    }
    
    //Return the array
    return array;
}

Data *deposit(Data a, float &sum){
    cout<<"Enter the number of deposits you have made this month."<<endl;
    cin>>a.nmDepot;
    //Is the size parameter valid
    if(a.nmDepot<=0)return 0;
    
    //Allocate the Structure pointer
    Data *array=new Data;
    array->size=a.nmDepot;
    
    //Allocate memory
    array->data=new float[array->size];
    
    for(int i=0;i<a.nmDepot;i++){
        cout<<"Enter the amount of money for deposit "<<i+1<<endl;
        cin>>array->data[i];
        sum+=array->data[i];
    }
    
    //Return the array
    return array;
}
