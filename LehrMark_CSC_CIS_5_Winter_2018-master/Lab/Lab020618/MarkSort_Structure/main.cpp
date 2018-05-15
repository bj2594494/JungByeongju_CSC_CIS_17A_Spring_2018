/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 6th, 2018, 10:40 AM
 * Purpose:  Structure and Dynamic Memory Use
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Contains srand
#include <ctime>     //Time Library
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries
#include "Array.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void  fillStr(Array &);
void  prntStr(Array &,int);
void  mrkSort(Array &);


//Execution Begins Here
int main(int argc, char** argv) {
    //Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    Array x;
    
    //Fill the array
    x.size=200;
    fillStr(x);
    
    //Print the results
    prntStr(x,10);
    
    //Sort
    mrkSort(x);
    
    //Print the results
    prntStr(x,10);
    
    //Deallocate memory
    delete []x.data;

    //Exit stage right!
    return 0;
}

void  mrkSort(Array &a){
    for(int j=0;j<a.size-1;j++){
        for(int i=j+1;i<a.size;i++){
            if(a.data[j]>a.data[i]){
                float temp=a.data[j];
                a.data[j]=a.data[i];
                a.data[i]=temp;
            }
        }
    }
}

void  prntStr(Array &a,int nCols){
    cout<<endl;
    for(int i=0;i<a.size;i++){
        cout<<a.data[i]<<" ";
        if(i%nCols==(nCols-1))cout<<endl;
    }
    cout<<endl;
}

void  fillStr(Array &a){
    //Allocate memory
    a.data=new float[a.size];
    for(int i=0;i<a.size;i++){
        a.data[i]=rand()%90+10;//[10,99]
    }
}