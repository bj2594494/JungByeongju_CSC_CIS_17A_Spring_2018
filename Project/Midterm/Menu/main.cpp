/* 
 * File:   main.cpp
 * Author: Byeongju Jung
 * Created on April 22th, 2018, 11:45 PM
 * Purpose:  Menu
 */

//System Libraries Here
#include <iostream>  //I/O Library
#include <cstdlib>   //Random number function
#include <ctime>     //Time Library for random seed
#include <iomanip>   //Format Library
#include <cmath>     //Math Library
#include "Array.h"
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void data(Data &);
Data *check(Data, float &);
Data *deposit(Data, float &);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    int probNum;
    //Output the results
    do{
        cout<<endl<<endl;
        //Menu with input of choice
        cout<<"Choose from the following Menu"<<endl;
        cout<<"Problem 1 -> Checking Account"<<endl;
        cout<<"Problem 2 -> Paycheck"<<endl;
        cout<<"Problem 3 -> Mean,Median,Mode"<<endl;
        cout<<"Problem 4 -> Encryption/Decryption"<<endl;
        cout<<"Problem 5 -> Factorial"<<endl;
        cout<<"Problem 6 -> Conversion"<<endl;
        cout<<"Problem 7 -> Prime Number"<<endl;
        cout<<"Type 1 to 7 only"<<endl;
        cin>>probNum;
        switch(probNum){
            case 1: {
                //Declare Variables
                Data client;
                Data *depot;
                Data *checks;
                float depoSum=0;
                float checSum=0;
                float balance;
                //Initialize Variables

                //Process/Map inputs to outputs
                cout<<"Prob 1, checking account problem."<<endl;
                data(client);
                checks=check(client,checSum);
                depot=deposit(client,depoSum);
                balance=client.balance-checSum+depoSum;
                //Output data
                cout<<endl;
                cout<<"Name: "<<client.name<<endl;
                cout<<"Address: "<<client.address<<endl;
                cout<<"Account Number: "<<client.account<<endl;
                cout<<"Balance at the beginning of the month: $"<<client.balance<<endl;
                cout<<"Total amount of checks: $"<<checSum<<endl;
                cout<<"Total amount of deposit: $"<<depoSum<<endl;
                if(balance<0){
                    cout<<"Your account is overdrawn. Additional $15 is overdrawn"<<endl;
                    balance-=15;
                    cout<<"Current Balance: $"<<balance<<endl;
                }
                else{
                    cout<<"Current Balance: $"<<balance<<endl;
                }
                break;
            }    
            case 2: {
               //Declare Variables
                const int SIZE=20;
                Pay workers[SIZE];
                int ttlPay;
                int i=0;
                bool loop;
                unsigned char n1s,n10s,n100s,n1000s;
                //Process/Map inputs to outputs
                cout<<"Prob 2, Paycheck Problem"<<endl;
                cin.ignore();
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
                break;
            }
            case 3: {
                cout<<"Could not program."<<endl;
                break;
            }
            case 4: {
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
                break;
            }
            case 5: {
                cout<<"Prob 5, factorial problem:"<<endl;
                cout<<"a. largest factorial for char:     5!, unsigned char:     6!"<<endl;
                cout<<endl;
                cout<<"b. largest factorial for short:    7!, unsigned short:    8!"<<endl;
                cout<<"   largest factorial for int:     12!, unsigned int:     12!"<<endl;
                cout<<"   largest factorial for long:    20!, unsigned long:    20!"<<endl;
                cout<<"   largest factorial for float:   34!"<<endl;
                cout<<"   largest factorial for double: 170!"<<endl;
                cout<<"   largest factorial for long double: 1754!"<<endl;
                break;
            }
            case 6: {
                //Declare Variables
                cout<<"Prob 6, converting problem:"<<endl;
                cout<<"a. 2.875(10): 2.E(16),  2.7(8), 0010.1110(2), 5C000002(float rep.)"<<endl;
                cout<<".1796875(10): .2E(16), .134(8), .00101110(2), 5C0000FE(float rep.)"<<endl;
                cout<<endl<<endl;
                cout<<"b. -2.875(10): -2.E(16),  -2.7(8), -0010.1110(2), A4000002(float rep.)"<<endl;
                cout<<"-.1796875(10): -.2E(16), -.134(8), -.00101110(2), A40000FE(float rep.)"<<endl;
                cout<<endl<<endl;
                cout<<"c. 59999901 = 1.4"<<endl;
                cout<<"   59999902 = 2.8"<<endl;
                cout<<"   A66667FE = -.175"<<endl;
                break;
            }
            case 7: {
                cout<<"Could not program."<<endl;break;
            }
            default:cout<<"You choose to exit"<<endl;
        }
    }while(probNum<8);
   
    //Exit
    return 0;
}

void data(Data &a){
    int m;
    cin.ignore();
    cout<<"Enter your name."<<endl;
    getline(cin,a.name);
    cout<<"Enter your address."<<endl;
    getline(cin,a.address);
    cout<<"Enter Account Number."<<endl;
    cin>>a.account;
    m=a.account.length();
    while(m!=5){
        cout<<"Invalid Account."<<endl;
        cout<<"Enter Account Number."<<endl;
        cin>>a.account;
        m=a.account.length();
    }
    cin.ignore();
    cout<<"Enter yout balance at the beginning of the month."<<endl;
    cin>>a.balance;
}

Data *check(Data a, float &sum){
    cout<<"Enter the number of checks you have written this month."<<endl;
    cin>>a.nmCheck;
    //Is the size parameter valid
    if(a.nmCheck<=0)return 0;
    
    //Allocate the Structure pointer
    Data *array=new Data;
    array->size=a.nmCheck;
    
    //Allocate memory
    array->data=new float[array->size];
    
    for(int i=0;i<a.nmCheck;i++){
        cout<<"Enter the amount of money you have written for check "<<i+1<<endl;
        cin>>array->data[i];
        sum+=array->data[i];
    }
    
    //Return the array
    return array;
}

Data *deposit(Data a, float &sum){
    cout<<"Enter the number of deposits you have made this month."<<endl;
    cin>>a.nmDepot;
    //Is the size parameter valid
    if(a.nmDepot<=0)return 0;
    
    //Allocate the Structure pointer
    Data *array=new Data;
    array->size=a.nmDepot;
    
    //Allocate memory
    array->data=new float[array->size];
    
    for(int i=0;i<a.nmDepot;i++){
        cout<<"Enter the amount of money for deposit "<<i+1<<endl;
        cin>>array->data[i];
        sum+=array->data[i];
    }
    
    //Return the array
    return array;
}
