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
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void Process::setHistory(const string& letter, int value, int index)
{
  History* theHistory = new History(letter, value);
  history[index] = *theHistory;
}

void Process::setName(const string& name)
{
  this->processName = name;
}

void Process::setPriority(int priority)
{
  this->priority = priority;
}

void Process::setArrivalTime(int arrivalTime)
{
  this->arrivalTime = arrivalTime;
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
