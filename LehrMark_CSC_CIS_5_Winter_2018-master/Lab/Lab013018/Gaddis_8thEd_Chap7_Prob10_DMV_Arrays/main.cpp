/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 30th, 2018, 10:20 AM
 * Purpose:  Grade a DMV test
 */

//System Libraries Here
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void read(ifstream &,char [],char[],int);
void read(fstream &,string,char [],int);
int  score(char [],char [], int);
void write(ofstream &,string,char [],char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    ifstream answer;
    fstream test;
    ofstream results;
    const int SIZE=20;
    char ans[SIZE],compare[SIZE];
    
    //Input or initialize values Here
    char fileName[]="answerkey.dat";
    string testName="test.dat";
    read(answer,fileName,ans,SIZE);
    read(test,testName,compare,SIZE);
    
    //Process/Calculations and output the result
    int correct=score(ans,compare,SIZE);
    cout<<"Correct Answers = "<<correct
            <<" out of "<<SIZE<<endl;
    cout<<"Percentage score = "
            <<100.0f*correct/SIZE<<"%"
            <<endl;
    
    //Do the same and record to a file
    string resName="result.dat";
    write(results,resName,ans,compare,SIZE);

    //Exit
    return 0;
}

void write(ofstream &output,string fn,char ans[],char test[],int n){
    //Open the file for writing
    output.open(fn.c_str());
    
    //Process/Calculations and output the result
    int correct=score(ans,test,n);
    output<<"Correct Answers = "<<correct
            <<" out of "<<n<<endl;
    output<<"Percentage score = "
            <<100.0f*correct/n<<"%"
            <<endl;
    
    //Close the file
    output.close();
}

int  score(char ans[],char test[], int n){
    //Declare and initialize the sum
    int sum=0;
    //Process the data
    for(int i=0;i<n;i++){
        if(ans[i]==test[i])sum++;
    }
    //Return the score
    return sum;
}

void read(fstream & input,string fn,char ans[],int n){
    //Open the file
    input.open(fn.c_str(),ios::in);
    
    //Read the data from the file
    for(int i=0;i<n;i++){
        input>>ans[i];
        //cout<<ans[i];
    }
            
    //Close the file
    input.close();
}

void read(ifstream & input,char fn[],char ans[],int n){
    //Open the file
    input.open(fn);
    
    //Read the data from the file
    for(int i=0;i<n;i++){
        input>>ans[i];
        //cout<<ans[i];
    }
            
    //Close the file
    input.close();
}