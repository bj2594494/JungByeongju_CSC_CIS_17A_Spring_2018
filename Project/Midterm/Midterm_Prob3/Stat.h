/*
 * File:   main.cpp
 * Author: Byeongju Jung
 * Created on April 2, 2018, 1:20 PM
 * Purpose: Create a CSC/CIS 5 Template
 */

#ifndef STAT_H
#define STAT_H

struct Stats
{
    float avg;     //Average value of an integer array
    float median;  //Median value  of an integer array
    int   *mode;   //array containing the modes
    int   nModes;  //number of modes in the array
    int   maxFreq; //max frequency of modes
};

#endif /* STAT_H */

