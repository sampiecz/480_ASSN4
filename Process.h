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
#include <vector>

using std::vector;
using std::string;

struct History 
{
  string letter;
  int value;
};


class Process {
  public:
    Process();
    void setHistory(const string&, int, int);
    void setName(const string&);
    void setArrivalTime(int);
    void setPriority(int);
    void setPID(int);
    void incrementSub();
    virtual ~Process();
    void print();
    int arrivalTime;
    History history [10];
    int sub;
    string processName;
    int priority;
    int processId;
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
