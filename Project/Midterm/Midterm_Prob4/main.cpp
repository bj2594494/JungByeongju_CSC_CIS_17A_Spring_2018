/*
 * File:   main.cpp
 * Author: Byeongju Jung
 * Created on April 2, 2018, 1:20 PM
 * Purpose: Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=6;
    char data[SIZE];
    char value[SIZE];
    char temp;
    int choose;
    //Initialize Variables
    cout<<"This program encrypts/decrypts code."<<endl;
    cout<<"Encrypt or decrypt? (1 for encrypt, 2 for decrypt)"<<endl;
    cin>>choose;
    if(choose==1){
        cout<<"Enter data for encryption. All digits must be between 0~7."<<endl;
        cin>>data;
        for(int i=0;i<4;i++){
            if(data[i]>55){
                cout<<"Invalid Input"<<endl;
                cout<<"Enter data for encryption. All digits must be between 0~7."<<endl;
                cin>>data;
                i=-1;
            }
        }
        //Process/Map inputs to outputs
        for(int i=0;i<4;i++){
            value[i]=(data[i]+5)%8;
        }
        for(int j=0;j<2;j++){
            temp=value[j];
            value[j]=value[j+2];
            value[j+2]=temp;
        } 
    }
    if(choose==2){
        cout<<"Enter data for decryption. All digits must be between 0~7."<<endl;
        cin>>data;
        for(int i=0;i<4;i++){
            if(data[i]>55){
                cout<<"Invalid Input"<<endl;
                cout<<"Enter data for decryption. All digits must be between 0~7."<<endl;
                cin>>data;
                i=-1;
            }
        }
        //Process/Map inputs to outputs
        for(int j=0;j<2;j++){
            temp=data[j];
            data[j]=data[j+2];
            data[j+2]=temp;
        } 
        for(int i=0;i<4;i++){
            if(data[i]<=5){
                value[i]=(data[i]+3)%8;
            }
            else
                value[i]=(data[i]-5)%8;
        }
    }
    
    //Output data
    cout<<"Result:"<<endl;
    for(int n=0;n<4;n++){
        cout<<int(value[n]);
    }
    //Exit stage right!
    return 0;
}

