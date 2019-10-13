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
#include <fstream>
#include <sstream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <vector>

using std::string;
using std::vector;
using std::endl;
using std::cout;
using std::cerr;
using std::getline;
using std::istringstream;
using std::ifstream;
using std::stringstream;
using std::stoi;

vector<string> stringToVector(const string& str)
{
  string buf;                 // Have a buffer string
  stringstream ss(str);       // Insert the string into a stream
  vector<string> tokens; // Create vector to hold our words
  while (ss >> buf)
  {
    tokens.push_back(buf);
  }

  return tokens;
}

void processFile(const string& filename)
{
  // Instantiate infile and line parser.
  vector<Process*> processes;
  ifstream infile(filename);
  int processCount = -1;
  bool stopHere = false;
  string line;

  // While we have a line in the file iterate. 
  while (getline(infile, line) && !stopHere)
  {

    // Stop when loudly asked to stop.
    if (line.find("STOPHERE") != string::npos)
    {
      stopHere = true;
    }

    // Variables to help process loop
    bool cpuBurstData;

    // Get the line, that pesky bugger.
    istringstream iss(line);

    // Process name or cpu burst data? 
    if (line.length() >= 20)
    {
      cpuBurstData = true;
    }
    else
    {
      cpuBurstData = false;
    }


    // Loop line by line.
    if (!stopHere)
    {

      string theName, thePriority, theArrivalTime;
      // if not burst then new process create it
      if (!cpuBurstData)
      {
        cout << "not burst data" << endl;
        int count = 0;
        for (auto x : stringToVector(line)) 
        {
          if (count == 0)
          {
            theName = x;
          }
          if (count == 1)
          {
            thePriority = x;
          }
          if (count == 2)
          {
            theArrivalTime = x;
          }
          count++;
        }
        Process* theProcess = new Process(theName, stoi(thePriority), stoi(theArrivalTime)); 
        processes.push_back(theProcess);
      }
      // if burst data assign data to most recent process
      else 
      {
        cout << "cpu burst data" << endl;
        string letter;
        int value;
        int count1 = 0;
        int trueCount = 0;

        for (string x : stringToVector(line)) 
        {
          if (count1 == 0)
          {
            letter = x;
            cout << "Letter: " << letter << endl;
          }
          else if (count1 == 1)
          {
            value = stoi(x);
            cout << "Value: " << value << endl;
            count1 = -1;
            processes[processCount]->setHistory(letter, value, trueCount);
          }
          count1++;
          trueCount++;
        }

      }
    }

    processCount++;

  }

  // Print out processes for testing purposes
  // need to move this into queue class print method
  for (auto x : processes)
  {
    cout << "Process: ";
    x->print();
    cout << "\n";
  }


}

int main()
{
  // Program requires 4 queues 
  //
  // This Queue is FIFO.
  //
  // new Queue(Entry);
  //
  //
  // These are priority Queues when a process is popped off
  // it is the highest priority process. If two processes
  // are equallly important, the older process should go first.
  //
  // new PriorityQueue(Ready);
  // new PriorityQueue(Input);
  // new PriorityQueue(Output);
  //
  // process * Active;
  // process * IActive;
  // process * OActive;

  processFile("data4.txt");

  return 0;

}
