/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on January 31, 2018, 10:20 AM
 * Purpose:  Fill a 2-D Array with Random Numbers and Display
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
const int COLSMAX=80;//Maximum Columns in a 2-D Array

//Function Prototypes
void  fillAry(float [][COLSMAX],int,int);
void  prntAry(float [][COLSMAX],int,int);


//Execution Begins Here
int main(int argc, char** argv) {
    //Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int ROWSMAX=100;
    float x[ROWSMAX][COLSMAX];
    int size;
    
    //Input the size of the array
    cout<<"Choose the size of a 2-D Array"<<endl;
    cout<<"Type 1 for 9x9"<<endl;
    cout<<"Type 2 for 15x15"<<endl;
    cout<<"Type 3 for 24x24"<<endl;
    cin>>size;
    
    //Set rows and cols
    int rows,cols;
    switch(size){
        case 1:rows=cols=9;break;
        case 2:rows=cols=15;break;
        case 3:rows=cols=24;break;
        default:rows=cols=5;
    }
    
    //Fill the array
    fillAry(x,rows,cols);
    
    //Print the results
    prntAry(x,rows,cols);

    //Exit stage right!
    return 0;
}

void  prntAry(float array[][COLSMAX],int rows,int cols){
    cout<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void  fillAry(float array[][COLSMAX],int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            array[i][j]=rand()%90+10;//[10,99]
        }
    }
}