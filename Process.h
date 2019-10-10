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

  History(string letter, int value)
  {
    this->letter = letter;
    this->value = value;
  }

};


class Process
{

    public:
        Process(const string&, int, int);
        virtual ~Process();
        void print();
    private:
				string processName;
        int priority;
        int processId;
        int arrivalTime;
        vector<History>* history;
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
