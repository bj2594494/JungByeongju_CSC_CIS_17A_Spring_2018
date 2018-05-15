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
string rmnCnvt(unsigned short);//Function to convert Arabic to Roman

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short nbr2Cnv;
    
    //Initialize Variables
    cout<<"This program converts Arabic to Roman Numerals"<<endl;
    cout<<"Input a number between 1 and 3000"<<endl;
    cin>>nbr2Cnv;
    
    //Display the result
    cout<<rmnCnvt(nbr2Cnv)<<endl;
    
    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         rmnCnvt
//Purpose:  Input an Arabic Number return a Roman Number
//Input:  nbr2Cnv -> Integer in the range of 1 to 3000
//Output: roman -> String representing the Roman Number
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
string rmnCnvt(unsigned short nbr2Cnv){
    //Validate the input
    if(nbr2Cnv<1||nbr2Cnv>3000){
        return "Out of Range";
    }
    //Declare Variables
    unsigned char n1000s,n100s,n10s,n1s;
    string roman;
    //Process/Map inputs to outputs
    n1000s=(nbr2Cnv-nbr2Cnv%1000)/1000;
    nbr2Cnv%=1000;
    n100s=(nbr2Cnv-nbr2Cnv%100)/100;
    nbr2Cnv%=100;
    n10s=(nbr2Cnv-nbr2Cnv%10)/10;
    nbr2Cnv%=10;
    n1s=nbr2Cnv;
    
    //Append the string with the number
    roman+=(n1000s+48);//Convert to character digits 48-57 or 0-9
    roman+=(n100s+'0');//Convert to character digits 48-57 or 0-9
    roman+=(n10s+48);  //Convert to character digits 48-57 or 0-9
    roman+=(n1s+'0');  //Convert to character digits 48-57 or 0-9
    roman+=" = ";
    
    //Display the 1000's place
    switch(n1000s){
        case 3:roman+="M";
        case 2:roman+="M";
        case 1:roman+="M";
    }
    
    //Display the 100's place
    switch(n100s){
        case 9:roman+="CM";break;
        case 8:roman+="DCCC";break;
        case 7:roman+="DCC";break;
        case 6:roman+="DC";break;
        case 5:roman+="D";break;
        case 4:roman+="CD";break;
        case 3:roman+="C";
        case 2:roman+="C";
        case 1:roman+="C";
    }
    
    //Display the 100's place
    switch(n10s){
        case 9:roman+="XC";break;
        case 8:roman+="LXXX";break;
        case 7:roman+="LXX";break;
        case 6:roman+="LX";break;
        case 5:roman+="L";break;
        case 4:roman+="XL";break;
        case 3:roman+="X";
        case 2:roman+="X";
        case 1:roman+="X";
    }
    
    //Display the 100's place
    switch(n1s){
        case 9:roman+="IX";break;
        case 8:roman+="VIII";break;
        case 7:roman+="VII";break;
        case 6:roman+="VI";break;
        case 5:roman+="V";break;
        case 4:roman+="IV";break;
        case 3:roman+="I";
        case 2:roman+="I";
        case 1:roman+="I";
    }
    return roman;
}