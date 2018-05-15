/* 
 * File:   main.cpp
 * Author: Byeongju Jung
 * Created on April 22th, 2018, 11:45 PM
 * Purpose:  Menu
 */

#ifndef ARRAY_H
#define ARRAY_H

using namespace std;

struct Data{
       
    string name;
    string address;
    string account;
    float balance;
    int nmCheck;
    int nmDepot;
    int size;
    float *data;
};

struct Pay{
    string name;
    int hours;
    int pay;
};

#endif /* ARRAY_H */
