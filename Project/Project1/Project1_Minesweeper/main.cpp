/* 
 * File:   main.cpp
 * Author: Byeongju Jung
 * Created on April 11, 2018, 12:13 PM
 * Purpose:  Minesweeper Version 3
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random number Library
#include <ctime>     //Time Library
#include <iomanip>   //Formatting Library
#include <fstream>   //read/write Library
#include <cctype>    //character testing Library
#include <cstring>   //c-string Library
#include "Array.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, conversions,
//                   2-D Array Dimensions

//Function Prototypes
void level(int &, int &,int&,int&); //function for choosing level of the game
Array *fillAry(int,int,int); //function for filling the board up
void crBoard(Array *); //function for creating the board
bool valid(int, int, Array *); //Function that will check if the given tile is valid or not
//Function that will replace a mine to a normal tile when it is the user's
//first move
void replace(int, int, Array *);
//Function that will check if the tile that the user choose has a mine
bool ckMine(int, int, Array *);
//Function that will check the surrounding tile and give the number of mines
int ckNeigh(int, int, Array *);
//Function that will "pop" the tile surrounding the chosen tile until it 
//reaches a point where the tile is next to the mine
void popTile(int, int, Array *, Array *);
//Function that will check if all mines are flagged
bool ckAllFg(Array *, Array *, int, int);
void gmPlay(Array *, Array *,int,int,int); //function for playing the game
void write(int); //Function to write player info
char cfunc(char []); //Function to change c-string info
void destroy(Array *); //function for deallocating memory
//Execution Begins Here

int main(int argc, char** argv) {
    //Seed the random number function
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    int rows, cols,length,mines;
    //Choose level of the game
    level(rows,cols,mines,length);
    //Fill the array for the board
    Array *rlBoard=fillAry(rows,cols,mines);
    Array *myBoard=fillAry(rows,cols,0);
    //Process/Map inputs to outputs
    gmPlay(rlBoard, myBoard,length,rows,cols);
    //Deallocate memory
    destroy(rlBoard);
    destroy(myBoard);
    //Exit stage right!
    return 0;
}

void level(int &rows, int &cols, int &mines, int &length){
    string input;
    fstream name;
    cout<<"Please choose the difficulty level."<<endl;
    do{
        cout<<"Enter 1 for Beginner (9X9 Board with 10 mines)"<<endl;
        cout<<"Enter 2 for Intermediate (16X16 Board with 40 mines)"<<endl;
        cout<<"Enter 3 for Advanced (24X24 Board with 99 mines)"<<endl;
        cout<<"Enter 4 to show the player list"<<endl; //Option to show the player list
        cout<<"Enter 5 to end the game"<<endl; //Option to end the game
        cin>>length;
    }while(!(length>=1&&length<=5));
    switch(length){
        case 1:rows=cols=9,mines=10;break;
        case 2:rows=cols=15,mines=40;break;
        case 3:rows=cols=24,mines=99;break;
        case 4:name.open("ScoreBoard.txt", ios::in);
        // If the file was open successfully, continue
        if(name){
        //Read from the file
        getline(name,input);
        while(name){
            cout<<input<<endl;
            getline(name,input);
        }
        //Close the file
        name.close();
        exit(0);
        }
        else{
            cout<<"ERROR:Cannot Open File. \n";
        }
        break;
        default:exit(0);break;
    }
}

Array *fillAry(int rows,int cols,int mines){
    //Is the size parameter valid
    if(rows<=0)return 0;
    if(cols<=0)return 0;
    
    //Allocate memory
    Array *array=new Array;
    array->rows=rows;
    array->cols=cols;
    array->data=new char*[rows];
    for(int row=0;row<array->rows;row++){ //testing fix if prob array->
        array->data[row]=new char[cols];
    }
    
    //Filling Board
    for(int i=0;i<array->rows;i++){       //testing fix if prob array->
        for(int j=0;j<array->cols;j++){   //testing fix if prob array->
            array->data[i][j]='-';
        }
    }
    
    //Add mines.
    for(int i=0;i<mines;i++){
        bool minePcd = false; //To check if the tile already has a mine assigned
        do {
          int col = rand()%cols;
          int row = rand()%rows;
          if( array->data[row][col] == '-') {//'-' for tiles not mine
            array->data[row][col] = '*';     //'*' for tiles that are mine
            minePcd = true; 
          }
        } while( ! minePcd ); //Will not place a mine if the tile already has mine
    }
    
    //Return the array
    return array;
}

void crBoard(Array *a){
    cout<<endl;
    cout<<"  ";
    for(int n=0;n<a->cols;n++){//For displaying numbered columns
        cout<<setw(2)<<n+1<<" ";
    }
    cout<<endl;
    for(int i=0;i<a->rows;i++){//For displaying numbered row
        cout<<setw(2)<<i+1<<" ";
        for(int j=0;j<a->cols;j++){
            cout<<a->data[i][j]<<"  ";
        }
    cout<<endl;
    }
}

bool valid(int row, int col, Array *a){//Check to see if the given tile is inside the
                              //game boundaries
    bool valid=false;         //Created problems when not checked 
    if((row>=0)&&(col>=0)&&(row<a->rows)&&(col<a->cols)){
        valid=true;
    }
    else{
        valid=false;
    }
    return valid;
}

void replace(int row, int col, Array *rlBoard){//Replacing mine
    rlBoard->data[row][col]='-';                     //if stepped on first move
    int colp,rowp;
    do{
        colp=rand()%9;
        rowp=rand()%9;
    }while(!(rlBoard->data[rowp][colp]=='-'));
    rlBoard->data[rowp][colp]='*';
}

bool ckMine(int row, int col,Array *a){
    if (a->data[row][col]=='*'){
        return true;
    }
    else if (!(a->data[row][col]=='*')){
        return false;
    }
}

int ckNeigh(int row, int col, Array *a){
    int count=0;
    //Top-Left from tile chosen
    if (valid(row+1,col-1,a)==true) {
        if(a->data[row+1][col-1]=='*')
          count++;
    }
    //Top from tile chosen
    if (valid(row+1,col,a)==true) {
        if (a->data[row+1][col]=='*'){
            count++;
        }
    }
    //Top-Right from tile chosen
    if (valid(row+1,col+1,a)==true) {
        if (a->data[row+1][col+1]=='*'){
            count++;
        }
    }
    //Left from tile chosen
    if (valid(row,col-1,a)==true) {
        if (a->data[row][col-1]=='*'){
            count++;
        }
    }
    //Right from tile chosen
    if (valid(row,col+1,a)==true) {
        if (a->data[row][col+1]=='*'){
            count++;
        }
    }
    //Down-Left from tile chosen
    if (valid(row-1,col-1,a)==true) {
        if (a->data[row-1][col-1]=='*'){
            count++;
        }
    }
    //Down from tile chosen
    if (valid(row-1,col,a)==true) {
        if (a->data[row-1][col]=='*'){
            count++;
        }
    }
    //Down-Right from tile chosen
    if (valid(row-1,col+1,a)==true) {
        if (a->data[row-1][col+1]=='*'){
            count++;
        }
    }
    return count;
}

void popTile(int row, int col, Array *rlBoard, Array *myBoard){
    int neiBor; //checking and popping the 8 neighboring tiles
    //Top-Left from tile chosen
    if (valid(row+1,col-1,rlBoard)==true) {
        if(!(rlBoard->data[row+1][col-1] =='*')){
            neiBor=ckNeigh(row+1,col-1,rlBoard);
            rlBoard->data[row+1][col-1] = '0' + neiBor;
        }
        if(rlBoard->data[row+1][col-1]=='0' + neiBor){
            myBoard->data[row+1][col-1]='0' + neiBor;
        if(rlBoard->data[row+1][col-1]=='-')
          myBoard->data[row+1][col-1]='0';
        }
    }
    //Top from tile chosen
    if (valid(row+1,col,rlBoard)==true) {
        if(!(rlBoard->data[row+1][col] =='*')){
            neiBor=ckNeigh(row+1,col,rlBoard);
            rlBoard->data[row+1][col] = '0' + neiBor;
        }
        if(rlBoard->data[row+1][col]=='0' + neiBor){
            myBoard->data[row+1][col]='0' + neiBor;
        if(rlBoard->data[row+1][col]=='-')
          myBoard->data[row+1][col]='0';
        }
    }
    //Top-Right from tile chosen
    if (valid(row+1,col+1,rlBoard)==true) {
        if(!(rlBoard->data[row+1][col+1] =='*')){
            neiBor=ckNeigh(row+1,col+1,rlBoard);
            rlBoard->data[row+1][col+1] = '0' + neiBor;
        }
        if(rlBoard->data[row+1][col+1]=='0' + neiBor){
            myBoard->data[row+1][col+1]='0' + neiBor;
        if(rlBoard->data[row+1][col+1]=='-')
          myBoard->data[row+1][col+1]='0';
        }
    }
    //Left from tile chosen
    if (valid(row,col-1,rlBoard)==true) {
        if(!(rlBoard->data[row][col-1] =='*')){
            neiBor=ckNeigh(row,col-1,rlBoard);
            rlBoard->data[row][col-1] = '0' + neiBor;
        }
        if(rlBoard->data[row][col-1]=='0' + neiBor){
            myBoard->data[row][col-1]='0' + neiBor;
        if(rlBoard->data[row][col-1]=='-')
          myBoard->data[row][col-1]='0';
        }
    }
    //Right from tile chosen
    if (valid(row,col+1,rlBoard)==true) {
        if(!(rlBoard->data[row][col+1] =='*')){
            neiBor=ckNeigh(row,col+1,rlBoard);
            rlBoard->data[row][col+1] = '0' + neiBor;
        }
        if(rlBoard->data[row][col+1]=='0' + neiBor){
            myBoard->data[row][col+1]='0' + neiBor;
        if(rlBoard->data[row][col+1]=='-')
          myBoard->data[row][col+1]='0';
        }
    }
    //Down-Left from tile chosen
    if (valid(row-1,col-1,rlBoard)==true) {
        if(!(rlBoard->data[row-1][col-1] =='*')){
            neiBor=ckNeigh(row-1,col-1,rlBoard);
            rlBoard->data[row-1][col-1] = '0' + neiBor;
        }
        if(rlBoard->data[row-1][col-1]=='0' + neiBor){
            myBoard->data[row-1][col-1]='0' + neiBor;
        if(rlBoard->data[row-1][col-1]=='-')
          myBoard->data[row-1][col-1]='0';
        }
    }
    //Down from tile chosen
    if (valid(row-1,col,rlBoard)==true) {
        if(!(rlBoard->data[row-1][col] =='*')){
            neiBor=ckNeigh(row-1,col,rlBoard);
            rlBoard->data[row-1][col] = '0' + neiBor;
        }
        if(rlBoard->data[row-1][col]=='0' + neiBor){
            myBoard->data[row-1][col]='0' + neiBor;
        if(rlBoard->data[row-1][col]=='-')
          myBoard->data[row-1][col]='0';
        }
    }    //Down-Right from tile chosen
    if (valid(row-1,col+1,rlBoard)==true) {
        if(!(rlBoard->data[row-1][col+1] =='*')){
            neiBor=ckNeigh(row-1,col+1,rlBoard);
            rlBoard->data[row-1][col+1] = '0' + neiBor;
        }
        if(rlBoard->data[row-1][col+1]=='0' + neiBor){
            myBoard->data[row-1][col+1]='0' + neiBor;
        if(rlBoard->data[row-1][col+1]=='-')
          myBoard->data[row-1][col+1]='0';
        }
    }
}

bool ckAllFg(Array *rlBoard, Array *myBoard, int rows, int cols){
    bool brdClrd = true; //Check to see if all mines are flagged
    for( int r = 0; r < rows && brdClrd; r++ ) {
        for( int c = 0; c < cols && brdClrd; c++ ) {
            if( rlBoard->data[r][c] == '*' ) {
                if( myBoard->data[r][c] != 'F' )
                    brdClrd = false;
            }
        }
    }
    
    return brdClrd;
}

void gmPlay(Array *rlBoard, Array *myBoard, int length, int rows, int cols){
    bool gameOvr = false;
    int fstPlay=0; //Number of moves taken set to 0
    int score=0; //score
    //Main Game-play Loop
    do {
      //Display the board
      //To see the mines, uncomment it
      crBoard(rlBoard);
      crBoard(myBoard);
      //Get input from user.
      int col, row; //Input row and columns for the user
      char move; //Input user's move
      int neiBor; //Checking/Counting the neighboring tiles
      cout<<"Enter your move. (Row and Column followed by "
          <<"'c' for clicking, and 'f' for flagging)"<<endl;
      cin >> row >> col >> move;
      cin.ignore();
      //Input Validation
      if(length==1){
          while(row<1&&row>=10&&col<1&&col>=10
                  &&(!(move=='c')||!(move=='f'))){
          cout<<"Enter your move. (Row and Column followed by "
          <<"'c' for clicking, and 'f' for flagging)"<<endl;
          cin >> row >> col >> move;
          }
      }
      if(length==2){
          while(row<1&&row>=17&&col<1&&col>=17
                  &&(!(move=='c')||!(move=='f'))){
          cout<<"Enter your move. (Row and Column followed by "
          <<"'c' for clicking, and 'f' for flagging)"<<endl;
          cin >> row >> col >> move;
          }
      }
      if(length==3){
          while(row<1&&row>=25&&col<1&&col>=25
                  &&(!(move=='c')||!(move=='f'))){
          cout<<"Enter your move. (Row and Column followed by "
          <<"'c' for clicking, and 'f' for flagging)"<<endl;
          cin >> row >> col >> move;
          }
      }
      //Check if the tile that the user clicked is mine or not.
      if(move=='c'){ 
          //To ensure that the first tile chosen is not a mine
          if(fstPlay==0){
              if (ckMine(row-1,col-1,rlBoard)){
                replace(row-1,col-1,rlBoard);
              }
              fstPlay++;//Add 1 to avoid the loop
          } 
          if ((ckMine(row-1,col-1,rlBoard)==true)){//Checking if the chosen tile is mine or not
              cout<<"You Stepped on a Mine! You Lose!"<<endl;//Player lose when stepped on mine
              gameOvr=true;
          }
          else if ((ckMine(row-1,col-1,rlBoard)==false)){
              neiBor=ckNeigh(row-1,col-1,rlBoard);  //Checking neighbor tiles for mines
              myBoard->data[row-1][col-1] = '0' + neiBor; //Displaying the number of mines near
              popTile(row-1,col-1,rlBoard,myBoard); //Popping tiles that does not have mine next to it
              score++;
          }
      }
      else if(move=='f'){ //When the move is flag, display "F" on the tile
          if ((ckMine(row-1,col-1,rlBoard)==true)){ //Checking for a mine
              score+=2;
          }
          myBoard->data[row-1][col-1] = 'F';
          
          if( ckAllFg(rlBoard, myBoard, rows, cols) ) { //when all of the mines are flagged
              cout << "You won!" << endl;               //The player will win
              gameOvr = true;
          }
      }
    } while( !gameOvr ); //Ending the loop for the game play
    write(score);
}

void write(int s){
    ofstream data;
    string player;
    int length;
    const int SIZE=6;
    char initial[SIZE];
    data.open("ScoreBoard.txt", ios::out | ios::app);
    cout<<"Enter your name"<<endl;
    getline( cin, player ); //get name from terminal
    cout<<"Enter your initial. (2 English Letters)"<<endl;
    cin>>initial;
    length=strlen(initial);
    while(length!=2){
        cout<<"Invalid entry."<<endl;
        cout<<"Enter your initial. (2 English Letters)"<<endl;
        cin>>initial;
        length=strlen(initial);
    };
    while((!(isalpha(initial[0]))||!(isalpha(initial[1])))){
        cout<<"Invalid entry."<<endl;
        cout<<"Enter your initial. (2 English Letters)"<<endl;
        cin>>initial;
    };
    cfunc(initial);
    data<<player<<", "<<initial<<"'s score:"<<s<<"\r\n"; //store in file
    //Close the file
    data.close();
}

char cfunc(char a[]){
    char temp;
    for(int i=0;i<2;i++){
        temp=toupper(a[i]);
        a[i]=temp;
    }
}

void destroy(Array *a){
    if(!a)return;
    for(int row=0;row<a->rows;row++){
        delete []a->data[row];
    }
    delete []a->data;
    delete a;
}

