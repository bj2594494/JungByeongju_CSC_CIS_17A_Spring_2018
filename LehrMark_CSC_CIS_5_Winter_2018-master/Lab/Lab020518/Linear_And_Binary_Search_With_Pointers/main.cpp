/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 1st, 2018, 10:50 AM
 * Purpose:  Timing 1,2,3 functions
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Contains srand
#include <ctime>     //Time Library
#include <cmath>     //Math Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void  fillAry(float *,int);
void  prntAry(float *,int,int);
void  mrkSort(float *,int);
float max(float *,int);
int   linear(float *,int,float);
int   binary(float *,int,float);

//Execution Begins Here
int main(int argc, char *argv[]) {
    //Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=100;
    float x[SIZE];
    
    //Fill the array
    fillAry(x,SIZE);
    
    //Sort the Array
    mrkSort(x,SIZE);
    
    //Print the array
    prntAry(x,SIZE,10);
    
    //Find a value
    cout<<"Value 101 found at position = "<<linear(x,SIZE,101)<<endl;
    cout<<"Value 101 found at position = "<<binary(x,SIZE,101)<<endl;
    cout<<"Value "<<x[50]<<" found at position = "
            <<linear(x,SIZE,x[50])<<" using Linear Search"<<endl;
    cout<<"Value "<<x[50]<<" found at position = "
            <<binary(x,SIZE,x[50])<<" using Binary Search"<<endl;
    
    //Exit stage right!
    return 0;
}

int binary(float *a,int n,float val){
    //Declare the beginning and end of range with the mid-point
    int begRng=0;
    int endRng=n-1;
    //Take into account float tolerance
    float mx=max(a,n);
    float tol=1e-6f*mx;//Tolerance within 6 significant digits
    //Loop until found
    do{
        int midPnt=(endRng+begRng)/2;
        //if(a[midPnt]==val)return midPnt;
        if(val>(a[midPnt]-tol)&&val<(a[midPnt]+tol))return midPnt;
        else if(val<a[midPnt])endRng=midPnt-1;
        else begRng=midPnt+1;
    }while(endRng>=begRng);
    return -1;
}

int   linear(float *a,int n,float val){
    //Declare a tolerance based on float data type
    //Correct way to find a float
    float mx=max(a,n);
    float tol=1e-6f*mx;//Tolerance within 6 significant digits
    for(int j=0;j<n-1;j++){
        //if(val==a[j])return j;//Correct way to find an integer
        if(val>(a[j]-tol)&&val<(a[j]+tol))return j;
    }
    return -1;
}

float max(float *a,int n){
    //Declare an initial value
    float mx=a[0];
    for(int j=1;j<n;j++){
        if(a[j]>mx)mx=a[j];
    }
    return mx;
}

void  mrkSort(float *a,int n){
    for(int j=0;j<n-1;j++){
        for(int i=j+1;i<n;i++){
            if(a[j]>a[i]){
                float temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
}

void  prntAry(float *array,int n,int nCols){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
        if(i%nCols==(nCols-1))cout<<endl;
    }
    cout<<endl;
}

void  fillAry(float *array,int n){
    for(int i=0;i<n;i++){
        *(array+i)=rand()%90+10;//[10,99]
    }
}