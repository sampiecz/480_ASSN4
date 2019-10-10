/***********************************************************
 CSCI 480 - Assignment 4 - Fall 2019
 
 Progammer: Sam Piecz
 Z-ID: Z1732715
 Section: 2 
 TA: Jingwan Li  
 Date Due: Oct 11, 2019 
 Purpose: Priority Scheduling Simulation. 
 ************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include "Queue.h"

using std::string;

class PriorityQueue : public Queue
{
    public:
        PriorityQueue(const string&);
        void print();
    private:
};

#endif
