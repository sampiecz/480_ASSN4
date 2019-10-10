/***********************************************************
 CSCI 480 - Assignment 4 - Fall 2019
 
 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 2 
 TA: Jingwan Li  
 Date Due: Oct 11, 2019 
 Purpose: Priority Scheduling Simulation. 
 ************************************************************/
#include "Process.h"
#include <iostream>

using std::cout;
using std::endl;

// Constructor that sets the name
Process::Process(const string& processName, int priority, int arrivalTime)
{
    this->processName = processName;
    this->priority = priority;
    this->arrivalTime = arrivalTime;
}

void Process::setHistory(const string& letter, int value)
{
  History* history = new History(letter, value);
  this->history->push_back(*history);
}

Process::~Process()
{
}

void Process::print()
{
  cout << "\n";
  cout << "-name: " << this->processName << endl;
  cout << "-priority: " << this->priority << endl;
  cout << "-arrivalTime: " << this->arrivalTime<< endl;
}
