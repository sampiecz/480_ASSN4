/***********************************************************
 CSCI 480 - Assignment 4 - Fall 2019
 
 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 2 
 TA: Jingwan Li  
 Date Due: Oct 11, 2019 
 Purpose: Priority Scheduling Simulation. 
 ************************************************************/
#ifndef PROCESS_H
#define PROCESS_H

#include <string>
using std::string;

class Process
{
    public:
        Process(const string&);

    private:
				string processName;
        int priority;
        int processId;
        int arrivalTime;
        string history[10];
        int sub;
        int cpuTimer;
        int IOTimer;
        int CPUTotal;
        int ITotal;
        int OTotal;
        int CPUCount;
        int ICount;
        int OCount;
};

#endif
