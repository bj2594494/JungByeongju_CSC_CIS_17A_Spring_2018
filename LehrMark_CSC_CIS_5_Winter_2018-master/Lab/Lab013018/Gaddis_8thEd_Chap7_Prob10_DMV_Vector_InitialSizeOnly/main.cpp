/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 30th, 2018, 10:20 AM
 * Purpose:  Grade a DMV test
 */

//System Libraries Here
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void read(ifstream &,char[],vector<char> &);
void read(fstream &,string,vector<char> &);
int  score(vector<char> &,vector<char> &);
void write(ofstream &,string,vector<char> &,vector<char> &);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    ifstream answer;
    fstream test;
    ofstream results;
    const int SIZE=20;
    vector<char> ans(SIZE);
    vector<char> compare(SIZE);
    
    //Input or initialize values Here
    char fileName[]="answerkey.dat";
    string testName="test.dat";
    
    read(answer,fileName,ans);
    read(test,testName,compare);
    
    //Process/Calculations and output the result
    int correct=score(ans,compare);
    cout<<"Correct Answers = "<<correct
            <<" out of "<<ans.size()<<endl;
    cout<<"Percentage score = "
            <<100.0f*correct/ans.size()<<"%"
            <<endl;
    
    //Do the same and record to a file
    string resName="result.dat";
    write(results,resName,ans,compare);

    //Exit
    return 0;
}

void write(ofstream &output,string fn,vector<char> &ans,vector<char> &test){
    //Open the file for writing
    output.open(fn.c_str());
    
    //Process/Calculations and output the result
    int correct=score(ans,test);
    output<<"Correct Answers = "<<correct
            <<" out of "<<ans.size()<<endl;
    output<<"Percentage score = "
            <<100.0f*correct/ans.size()<<"%"
            <<endl;
    
    //Close the file
    output.close();
}

int  score(vector<char> &ans,vector<char> &test){
    //Declare and initialize the sum
    int sum=0;
    //Process the data
    for(int i=0;i<ans.size();i++){
        if(ans[i]==test[i])sum++;
    }
    //Return the score
    return sum;
}

void read(fstream & input,string fn,vector<char> &ans){
    //Open the file
    input.open(fn.c_str(),ios::in);
    
    //Read the data from the file
    int i=0;
    while(input>>ans[i++]);
            
    //Close the file
    input.close();
}

void read(ifstream & input,char fn[],vector<char> &ans){
    //Open the file
    input.open(fn);
    
    //Read the data from the file
    int i=0;
    while(input>>ans[i++]);
            
    //Close the file
    input.close();
}