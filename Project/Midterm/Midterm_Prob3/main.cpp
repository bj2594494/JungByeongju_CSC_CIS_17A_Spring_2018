/*
 * File:   main.cpp
 * Author: Byeongju Jung
 * Created on April 22, 2018, 1:20 PM
 * Purpose: Midterm Prob 3
 */

//System Libraries
#include <iostream>

#include "Stat.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, conversions,
//                   2-D Array Dimensions

//Function Prototypes
Stats *avgMedMode(int *,int); 
//Execution Begins Here

int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=100;
    int x[SIZE];
    int n;
    cout<<"Midterm Prob 3, Mode Problem"<<endl;
    cout<<"Enter the number of inputs."<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the input number "<<i+1<<endl;
        cin>>x[i];
    }
    Stats *z=avgMedMode(x,n);
    //Initialize Variables
    
    //Process/Map inputs to outputs
    
    //Output data
    
    //Exit stage right!
    return 0;
}

Stats *avgMedMode(int *x,int n){
    Stats temp;
    temp.mode=new int[n];
    int sum=0;
    int count=0;
    for(int i=0;i<n;i++){
        sum+=x[i];
    }
    temp.avg=sum/n;
    if(n%2!=0){
        temp.median=x[(n/2)];
    }
    if(n%2==0){
        temp.median=((x[n/2]+x[(x/2)-1])/2);
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(x[i]==x[j]){
                temp.mode[i]=x[i];
                count++;
            }
        }
    }
}