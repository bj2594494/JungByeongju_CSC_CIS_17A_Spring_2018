/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 11th, 2018, 1:15 PM
 * Purpose:  Menu
 */

//System Libraries Here
#include <iostream>  //I/O Library
#include <cstdlib>   //Random number function
#include <ctime>     //Time Library for random seed
#include <iomanip>   //Format Library
#include <cmath>     //Math Library
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int probNum;
    
    //Menu with input of choice
    cout<<"Choose from the following Menu"<<endl;
    cout<<"Problem 1 -> Gaddis_9thEd_Chap4_Prob11_MathTutor"<<endl;
    cout<<"Problem 2 -> Savitch_9thEd_Chap3_Prob6_Fibonacci"<<endl;
    cout<<"Problem 3 -> Savitch_9thEd_Chap3_Prob7_etox"<<endl;
    cout<<"Problem 4 -> Author_Edition_Chapter_Problem_Description 4"<<endl;
    cout<<"Problem 5 -> Author_Edition_Chapter_Problem_Description 5"<<endl;
    cout<<"Problem 6 -> Author_Edition_Chapter_Problem_Description 6"<<endl;
    cout<<"Problem 7 -> Author_Edition_Chapter_Problem_Description 7"<<endl;
    cout<<"Problem 8 -> Author_Edition_Chapter_Problem_Description 8"<<endl;
    cout<<"Problem 9 -> Author_Edition_Chapter_Problem_Description 9"<<endl;
    cout<<"Type 1 to 9 only"<<endl;
    cin>>probNum;
    
    //Output the results
    switch(probNum){
        case 1: {
            
            break;
        }    
        case 2: {
           
            break;
        }
        case 3: {
            
            break;
        }
        case 4: {
            cout<<"Put problem 4 here "<<endl;break;
        }
        case 5: {
            cout<<"Put problem 5 here "<<endl;break;
        }
        case 6: {
            cout<<"Put problem 6 here "<<endl;break;
        }
        case 7: {
            cout<<"Put problem 7 here "<<endl;break;
        }
        case 8: {
            cout<<"Put problem 8 here "<<endl;break;
        }
        case 9: {
            cout<<"Put problem 9 here "<<endl;break;
        }
        default:cout<<"You choose to exit"<<endl;
    }
   
    //Exit
    return 0;
}