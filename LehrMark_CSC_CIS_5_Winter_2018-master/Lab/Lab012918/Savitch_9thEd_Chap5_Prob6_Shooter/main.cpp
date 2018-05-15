/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Created on January 29, 2018, 12:245 PM
 * Purpose:  Shooting Game
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Contains srand
#include <ctime>     //Time Library
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
bool pHit(float);
void shoot(bool,float,bool &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    bool aLive,bLive,cLive;
    float percA,percB,percC;
    int nRounds,howMany;
    int sumA,sumB,sumC;
    
    //Initialize Variables
    sumA=sumB=sumC=0;
    percA=0.3f;
    percB=0.5f;
    percC=1.0f;
    nRounds=100000;
    
    //Loop
    for(int round=1;round<=nRounds;round++){
        aLive=bLive=cLive=true;
        howMany=3;

        //Process/Map inputs to outputs
        do{
            if(aLive&&cLive){
                shoot(aLive,percA,cLive);
            }else if(aLive&&bLive){
                shoot(aLive,percA,bLive);
            }
            if(bLive&&cLive){
                shoot(bLive,percB,cLive);
            }else if(bLive&&aLive){
                shoot(bLive,percB,aLive);
            }
            if(cLive&&bLive){
                shoot(cLive,percC,bLive);
            }else if(cLive&&aLive){
                shoot(cLive,percC,aLive);
            }
            howMany=aLive+bLive+cLive;
        }while(howMany>1);
        sumA+=aLive;
        sumB+=bLive;
        sumC+=cLive;
    }
    
    //Output data
    cout<<"Al      Lived "<<1.0f*sumA/nRounds<<endl;
    cout<<"Bob     Lived "<<1.0f*sumB/nRounds<<endl;
    cout<<"Charlie Lived "<<1.0f*sumC/nRounds<<endl;
    cout<<"Sum = "<<sumA+sumB+sumC<<" = "<<nRounds<<endl;

    //Exit stage right!
    return 0;
}

void shoot(bool shtr,float prShtr,bool &victim){
    if(victim){
        victim=pHit(prShtr)?false:true;
    }
}

bool pHit(float perc){
    static const unsigned int mxRand=(1<<31)-1;
    float random=static_cast<float>(rand())/mxRand;//[0,1]
    return random<perc;
}