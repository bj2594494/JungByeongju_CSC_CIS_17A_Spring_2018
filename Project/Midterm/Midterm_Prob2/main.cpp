/*
 * File:   main.cpp
 * Author: Byeongju Jung
 * Created on April 2, 2018, 1:20 PM
 * Purpose: Create a CSC/CIS 5 Template
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include "Array.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=20;
    Pay workers[SIZE];
    int ttlPay;
    int i=0;
    bool loop;
    unsigned char n1s,n10s,n100s,n1000s;
    //Process/Map inputs to outputs
    cout<<"Prob 2, Paycheck Problem"<<endl;
    while(loop){
        loop=false;
        cout<<"Enter Employee's name."<<endl;
        getline(cin,workers[i].name);
        cout<<"Enter Employee's rate of pay."<<endl;
        cin>>workers[i].pay;
        if(workers[i].pay<0){
            cout<<"Exiting..."<<endl;
            exit(0);
        }
        cout<<"Enter Employee's hours worked."<<endl;
        cin>>workers[i].hours;
        if(workers[i].hours<0){
            cout<<"Exiting..."<<endl;
            exit(0);
        }
        cin.ignore();
        if(workers[i].hours<=30){
            ttlPay=workers[i].hours*workers[i].pay;
        }
        else if(workers[i].hours>30&&workers[i].hours<=50){
            ttlPay=(30*workers[i].pay)+((workers[i].hours-30)*(workers[i].pay*2));
        }
        else if(workers[i].hours>50){
            ttlPay=(30*workers[i].pay)+(20*(workers[i].pay*2))
                    +((workers[i].hours-50)*(workers[i].pay*3));
        }
        cout<<endl;
        cout<<"Hours Worked: "<<workers[i].hours<<endl;
        cout<<"Pay Rate per hour: $"<<workers[i].pay<<endl;
        cout<<endl;
        cout<<"Company: "<<endl;
        cout<<"Address: "<<endl;
        cout<<"Name: "<<workers[i].name<<"        Amount: $"<<ttlPay<<endl;
        cout<<"Amount: ";

        
        n1000s=(ttlPay-ttlPay%1000)/1000;
        ttlPay%=1000;
        n100s=(ttlPay-ttlPay%100)/100;
        ttlPay%=100;
        n10s=ttlPay;
        ttlPay%=10;
        n1s=ttlPay;

        //1000s
        switch(n1000s){
             case 9:cout<<"Nine Thousand ";break;
             case 8:cout<<"Eight Thousand "; break;
             case 7:cout<<"Seven Thousand "; break;
             case 6:cout<<"Six Thousand "; break;
             case 5:cout<<"Five Thousand "; break;
             case 4:cout<<"Four Thousand "; break;
             case 3:cout<<"Three Thousand ";break;
             case 2:cout<<"Two Thousand ";break;
             case 1:cout<<"One Thousand ";break;
        }

        //100s
        switch(n100s){
            case 9:cout<<"Nine Hundred ";break;
            case 8:cout<<"Eight Hundred "; break;
            case 7:cout<<"Seven Hundred "; break;
            case 6:cout<<"Six Hundred "; break;
            case 5:cout<<"Five Hundred "; break;
            case 4:cout<<"Four Hundred "; break;
            case 3:cout<<"Three Hundred "; break;
            case 2:cout<<"Two Hundred "; break;
            case 1:cout<<"One Hundred "; break;
        }

        //10s  
        if(n10s>=20){
            n10s=(n10s-n10s%10)/10;
            switch(n10s){
            case 9:cout<<"Ninety ";break;
            case 8:cout<<"Eighty "; break;
            case 7:cout<<"Seventy "; break;
            case 6:cout<<"Sixty "; break;
            case 5:cout<<"Fifty "; break;
            case 4:cout<<"Forty "; break;
            case 3:cout<<"Thirty "; break;
            case 2:cout<<"Twenty "; break;
            }
            //1s
            switch(n1s){
            case 9:cout<<"Nine ";break;
            case 8:cout<<"Eight ";break;
            case 7:cout<<"Seven ";break;
            case 6:cout<<"Six ";break;
            case 5:cout<<"Five ";break;
            case 4:cout<<"Four ";break;
            case 3:cout<<"Three ";break;
            case 2:cout<<"Two ";break;
            case 1:cout<<"One ";break;
            }
            cout<<"and no/100's Dollars"<<endl;
            cout<<"  Signature:"<<endl<<endl;
        }
        else if(n10s<20){
            if (n10s==19)
                cout<<"Nineteen ";
            if (n10s==18)
                cout<<"Eighteen ";
            if (n10s==17)
                cout<<"Seventeen ";
            if (n10s==16)
                cout<<"Sixteen ";
            if (n10s==15)
                cout<<"Fifteen ";
            if (n10s==14)
                cout<<"Fourteen ";
            if (n10s==13)
                cout<<"Thirteen ";
            if (n10s==12)
                cout<<"Twelve ";
            if (n10s==11)
                cout<<"Eleven ";
            if (n10s==10)
                cout<<"Ten ";
            if (n10s==9)
                cout<<"Nine ";
            if (n10s==8)
                cout<<"Eight ";
            if (n10s==7)
                cout<<"Seven ";
            if (n10s==6)
                cout<<"Six ";
            if (n10s==5)
                cout<<"Five ";
            if (n10s==4)
                cout<<"Four ";
            if (n10s==3)
                cout<<"Three ";
            if (n10s==2)
                cout<<"Two ";
            if (n10s==1)
                cout<<"One ";
            cout<<"and no/100's Dollars"<<endl;
            cout<<"  Signature:"<<endl<<endl;
        }
        loop=true;
    };
    //Output data
    
    //Exit stage right!
    return 0;
}
