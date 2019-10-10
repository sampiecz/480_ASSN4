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

using std::string;

class Queue
{
    public:
        Queue(const string&);
        void print();

    private:
				string queueName;
        int MAX_TIME = 500;
        int IN_PLAY = 6;
        int QUEUE_SIZE = 20;
        int ARRAY_SIZE = 10;
        int HOW_OFTEN = 25;
};

#endif
