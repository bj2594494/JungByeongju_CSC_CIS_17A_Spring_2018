/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 1st, 2018, 10:10 AM
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
void  fillAry(float [],int);
void  prntAry(float [],int,int);
void  swap(float &,float &);
void  smlst2(float [],int,int);
void  smlst3(float [],int,int);
void  mrkSort1(float [],int);
void  mrkSort2(float [],int);
void  mrkSort3(float [],int);
void  copy(float [],float [],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=100;
    float x[SIZE],y[SIZE],z[SIZE];
    
    //Fill the array
    fillAry(x,SIZE);
    copy(x,y,SIZE);
    copy(x,z,SIZE);
    
    //Sort
    int beg=time(0);
    mrkSort1(x,SIZE);
    int end=time(0);
    cout<<"Mark Sort 1 Function took "
            <<end-beg<<" secs"<<endl;

    
    //Sort
    beg=time(0);
    mrkSort2(y,SIZE);
    end=time(0);
    cout<<"Mark Sort 2 Function took "
            <<end-beg<<" secs"<<endl;
    
    //Sort
    beg=time(0);
    mrkSort3(z,SIZE);
    end=time(0);
    cout<<"Mark Sort 3 Function took "
            <<end-beg<<" secs"<<endl;

    //Exit stage right!
    return 0;
}

void  copy(float a[],float b[],int n){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
}

void  mrkSort1(float a[],int n){
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

void  mrkSort3(float a[],int n){
    for(int i=0;i<n-1;i++){
        smlst3(a,n,i);
    }
}

void  mrkSort2(float a[],int n){
    for(int i=0;i<n-1;i++){
        smlst2(a,n,i);
    }
}

void  smlst3(float a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i])swap(a[pos],a[i]);
    }
}

void  smlst2(float a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i]){
            float temp=a[pos];
            a[pos]=a[i];
            a[i]=temp;
        }
    }
}

void  swap(float &a,float &b){
    float temp=a;
    a=b;
    b=temp;
}

void  prntAry(float array[],int n,int nCols){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
        if(i%nCols==(nCols-1))cout<<endl;
    }
    cout<<endl;
}

void  fillAry(float array[],int n){
    for(int i=0;i<n;i++){
        array[i]=rand();//[10,99]
    }
}