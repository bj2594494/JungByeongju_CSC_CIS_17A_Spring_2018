/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on January 22, 2018, 11:00 AM
 * Purpose:  Arabic to Roman Numeral Converter
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short nbr2Cnv;
    unsigned char n1000s,n100s,n10s,n1s;
    
    //Initialize Variables
    cout<<"This program converts Arabic to Roman Numerals"<<endl;
    cout<<"Input a number between 1 and 3000"<<endl;
    cin>>nbr2Cnv;
    
    //Process/Map inputs to outputs
    n1000s=(nbr2Cnv-nbr2Cnv%1000)/1000;
    nbr2Cnv%=1000;
    n100s=(nbr2Cnv-nbr2Cnv%100)/100;
    nbr2Cnv%=100;
    n10s=(nbr2Cnv-nbr2Cnv%10)/10;
    nbr2Cnv%=10;
    n1s=nbr2Cnv;
    
    //Display the 1000's place
    switch(n1000s){
        case 3:cout<<"M";
        case 2:cout<<"M";
        case 1:cout<<"M";
    }
    
    //Display the 100's place
    switch(n100s){
        case 9:cout<<"CM";break;
        case 8:cout<<"DCCC";break;
        case 7:cout<<"DCC";break;
        case 6:cout<<"DC";break;
        case 5:cout<<"D";break;
        case 4:cout<<"CD";break;
        case 3:cout<<"C";
        case 2:cout<<"C";
        case 1:cout<<"C";
    }
    
    //Display the 100's place
    switch(n10s){
        case 9:cout<<"XC";break;
        case 8:cout<<"LXXX";break;
        case 7:cout<<"LXX";break;
        case 6:cout<<"LX";break;
        case 5:cout<<"L";break;
        case 4:cout<<"XL";break;
        case 3:cout<<"X";
        case 2:cout<<"X";
        case 1:cout<<"X";
    }
    
    //Display the 100's place
    switch(n1s){
        case 9:cout<<"IX";break;
        case 8:cout<<"VIII";break;
        case 7:cout<<"VII";break;
        case 6:cout<<"VI";break;
        case 5:cout<<"V";break;
        case 4:cout<<"IV";break;
        case 3:cout<<"I";
        case 2:cout<<"I";
        case 1:cout<<"I";
    }
    
    //Output data
    cout<<endl<<"The number you input = "
            <<static_cast<int>(n1000s)
            <<static_cast<int>(n100s)
            <<static_cast<int>(n10s)
            <<static_cast<int>(n1s);
    
    //Exit stage right!
    return 0;
}