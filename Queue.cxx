/***********************************************************
 CSCI 480 - Assignment 4 - Fall 2019
 
 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 2 
 TA: Jingwan Li  
 Date Due: Oct 11, 2019 
 Purpose: Priority Scheduling Simulation. 
 ************************************************************/
#include "Queue.h"
#include <iostream>

using std::cout;
using std::endl;

// Constructor that sets the name
Queue::Queue(const string& queueName)
{
  this->queueName = queueName;
}

void Queue::print()
{
  cout << "Name: " << this->queueName << endl;
}
