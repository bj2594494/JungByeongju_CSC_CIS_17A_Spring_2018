/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on February 1st, 2018, 10:50 AM
 * Purpose:  Grade Book
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
//                   2-D Array Column Dimension
const int COLS=20;


//Function Prototypes
void  fillAry(float [][COLS],int);
void  prntAry(float [][COLS],int);
float max(float[][COLS],int,int);
void  mxDsply(float[][COLS],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int ROWS=20;
    float grdBook[ROWS][COLS];
    
    //Fill the array
    fillAry(grdBook,ROWS);
    
    //Print the array and maximums
    prntAry(grdBook,ROWS);
    mxDsply(grdBook,ROWS);

    //Exit stage right!
    return 0;
}

void  mxDsply(float array[][COLS],int rows){
    //Separate from Gradebook display
    cout<<endl;
    //Heading for the max row
    cout<<"max     ";
    for(int col=0;col<COLS;col++){
        cout<<max(array,rows,col)<<" ";
    }
    cout<<endl;
}

float max(float a[][COLS],int rows,int col){
    //Declare an initial value
    float mx=a[0][col];
    for(int row=1;row<rows;row++){
        if(a[row][col]>mx)mx=a[row][col];
    }
    return mx;
}

void  prntAry(float array[][COLS],int rows){
    //Heading
    cout<<setw(COLS+8)<<" "<<"Assignments"<<endl;
    cout<<"        ";
    for(int col=0;col<COLS;col++){
         cout<<setw(2)<<col+1<<" ";
    }
    cout<<endl;
    //Grade table with students in first column
    for(int row=0;row<rows;row++){
        cout<<"Stu "<<setw(2)<<row+1<<"  ";
        for(int col=0;col<COLS;col++){
            cout<<array[row][col]<<" ";
        }
        cout<<endl;
    }
}

void  fillAry(float array[][COLS],int rows){
    for(int row=0;row<rows;row++){
        for(int col=0;col<COLS;col++){
            array[row][col]=rand()%30+70;//[70-100]
        }
    }
}