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
Process::Process(const string& processName)
{
    this->processName = processName;
}

Process::~Process()
{
}

void Process::print()
{
  cout << this->processName << endl;
}
