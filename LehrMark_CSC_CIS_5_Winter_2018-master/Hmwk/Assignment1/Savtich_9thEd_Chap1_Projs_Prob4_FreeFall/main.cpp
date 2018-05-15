/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on January 3, 2018, 1:20 PM
 * Purpose:  Free Fall
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
const int GRAVITY=32;//Gravity in ft/sec^2

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short time,   //Time in Seconds
                   dstnce; //Distance in feet
            
    //Input free fall time
    cout<<"This program calculate the distance "
        <<"dropped during free-fall"<<endl;
    cout<<"Input the time in free-fall"<<endl;
    cout<<"Time measured in seconds"<<endl;
    cout<<"In the range of 0 to 40 seconds"<<endl;
    cin>>time;
    
    //Process/Map inputs to outputs
    dstnce=1/2*GRAVITY*time*time;
    
    //Output data
    cout<<"An object dropped for "<<time<<" seconds "
        <<"falls "<<dstnce<<" feet"<<endl;
    
    //Exit stage right!
    return 0;
}