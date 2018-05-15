/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on January 25, 2018, 1:05 PM
 * Purpose:  Attempt at Rock Paper Scissors
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cmath>     //Math Library
#include <iomanip>   //Formatting Library
#include <cstdlib>   //Random Number Generator
#include <ctime>     //Time to seed Random Number
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
char cmptrGs();
char userGs();
string winner(char,char);
void gameRPS();

//Execution Begins Here
int main(int argc, char** argv) {
    //Generate Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Process/Map inputs to outputs
    gameRPS();

    //Exit stage right!
    return 0;
}

void gameRPS(){
    //Declare variable to end the game
    bool loop=true;
    
    //Start the Game
    cout<<"This is a game of Rock - Paper - Scissors"<<endl;
   
    //Loop the game until over
    do{
        //Begin the game
        char user=userGs();
        if(user!='R'&&user!='S'&&user!='P'){
            loop=false;
        }else{
            char comp=cmptrGs();
            cout<<winner(comp,user)<<endl;
        }
    
    //End the game
    }while(loop);
}

string winner(char c,char u){
    if(c==u)return "Tie";
    if(c=='P'){
        if(u=='R')return "Computer";
        else return "User";
    }
    if(c=='S'){
        if(u=='P')return "Computer";
        else return "User";
    }
    if(c=='R'){
        if(u=='S')return "Computer";
        else return "User";
    }
}

char userGs(){
    char user;
    cout<<"Input your decision"<<endl;
    cout<<"R for Rock, P for Paper, S for Scissors"<<endl;
    cout<<"Anything else ends the Game"<<endl;
    cin>>user;
    return user;
}

char cmptrGs(){
    char cChoice;
    do{
        cChoice=rand()%4+80;//P,Q,R,S
    }while(cChoice=='Q');
    return cChoice;
}