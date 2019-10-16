/***********************************************************
  CSCI 480 - Assignment 4 - Fall 2019

Progammer: Sam Piecz
Z-ID: Z1732715
Section: 2 
TA: Jingwan Li  
Date Due: Oct 11, 2019 Purpose: Priority Scheduling Simulation. 
 ************************************************************/
#include "Process.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <vector>
#include <queue>

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
using std::queue;
using std::priority_queue;

vector<string> stringToVector(const string& str)
{
  string buf;                 
  stringstream ss(str);
  vector<string> tokens;
  while (ss >> buf)
  {
    tokens.push_back(buf);
  }
  return tokens;
}

vector<Process*> processFile(const string& filename)
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

        // Create new process and set vars
        Process* theProcess = new Process(); 
        theProcess->setName(theName);
        theProcess->setPriority(stoi(thePriority));
        theProcess->setArrivalTime(stoi(theArrivalTime));
        theProcess->setPID(processCount);
        processes.push_back(theProcess);
        processCount++;
        cout << "Process print: " << endl; 
        theProcess->print();
        cout << "Processes print: " << endl; 
        processes[processCount]->print();

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
            trueCount++;
          }
          count1++;
        }

      }
    }

  }

  return processes;

}

queue<Process*> loadQueue(vector<Process*> _processes)
{

  queue<Process*> _queue;
  for (auto x : _processes)
    _queue.push(x);

  return _queue;

}

int main()
{
  // Constants
  int MAX_TIME = 500;
  int IN_PLAY = 6;
  int QUEUE_SIZE = 20;
  int ARRAY_SIZE = 10;
  int HOW_OFTEN = 25;

  // Instantiate vars.
  queue<Process*> entryQueue;
  priority_queue<Process*> Ready;
  priority_queue<Process*> Input;
  priority_queue<Process*> Output;
  Process* Active = NULL;
  Process* IActive = NULL;
  Process* OActive = NULL;
  bool cool = true;
  int timer = 0;
  int processesInUse = 0;


  // Process file, generate processes, and pack into queue.
  entryQueue = loadQueue(processFile("data4.txt"));

  // Iterate over entry queue
  while(timer < MAX_TIME && cool)
  {
    cout << "*************************************" << endl;
    cout << "ITERATION" << endl;
    cout << "*************************************" << endl;

    // a.
    cout << "a." << endl;
    if (processesInUse < IN_PLAY)
    {
      cout << "a.0" << endl;
      if (entryQueue.front()->arrivalTime < timer)
      {
        cout << "a.1" << endl;
        Ready.push(entryQueue.front());
      }
    }

    // b.
    if (Active == NULL)
    {
      cout << "b." << endl;
      if (Ready.empty())
      {
        cout << "b.0" << endl;
        timer++;
        continue;	
      }
      else
      {
        cout << "b.1" << endl;
        Active = Ready.top();
        Ready.pop();
      }
    }
    // c.
    else
    {
      cout << "c." << endl;
      Active->print();
      cout << "c.0" << endl;
      if (Active->history[Active->sub].letter == "I")
      {
        cout << "c.I" << endl;
        Input.push(Active);	
        processesInUse++;
      }
      else if (Active->history[Active->sub].letter == "O")
      {
        cout << "c.O" << endl;
        Output.push(Active);	
        processesInUse++;
      }
      else if (Active->history[Active->sub].letter == "N")
      {
        cout << "c.N" << endl;
        delete Active;
        processesInUse--;
        continue;
      }
      cout << "c.1" << endl;
      Active->incrementSub();
      cout << "c.2" << endl;
    }

    // d.
    if (IActive == NULL)
    {
      cout << "d." << endl;
      if (!Input.empty())
      {
        cout << "d.0" << endl;
        IActive = Input.top();	
      }
    }
    // e.
    else	
    {
      cout << "e." << endl;
      if (IActive->sub == 9)
      {
        cout << "e.0" << endl;
        Ready.push(IActive);
      }
    }

    // f.
    if (OActive == NULL)
    {
      cout << "f." << endl;
      if (!Output.empty())
      {
        cout << "f.0" << endl;
        OActive = Output.top();
      }
    }
    else 
    {
      // g.
      cout << "g." << endl;
      if (OActive->sub == 9)
      {
        cout << "g.0" << endl;
        Ready.push(OActive);
      }
    }

    // Prints all queues and pointers to processes  
    if (timer % HOW_OFTEN == 0)
    {


      cout << "****************" << endl;
      cout << "System Timer: " << timer << endl;
      cout << "****************" << endl;

      cout << "-=-=-=-=-=-=-=-" << endl; 
      cout << "Process Pointers" << endl;
      cout << "-=-=-=-=-=-=-=-" << endl; 

      if (Active != NULL)
      {
        cout << "h.1" << endl;
        Active->print();
      }
      if (IActive != NULL)
      {
        cout << "h.2" << endl;
        IActive->print();
      }
      if (OActive != NULL)
      {
        cout << "h.4" << endl;
        OActive->print();
      }

      cout << "-=-=-=-=-=-=-=-" << endl; 
      cout << "Queues         " << endl;
      cout << "-=-=-=-=-=-=-=-" << endl; 

      queue<Process*> printEntryQueue(entryQueue);
      while (!printEntryQueue.empty())
      {
        cout << "h.5" << endl;
        printEntryQueue.front()->print();
        printEntryQueue.pop();
      }

      priority_queue<Process*> printReadyQueue(Ready);
      while (!printReadyQueue.empty())
      {
        cout << "h.6" << endl;
        printReadyQueue.top()->print();
        printReadyQueue.pop();
      }

      priority_queue<Process*> printInputQueue(Input);
      while (!printInputQueue.empty())
      {
        cout << "h.7" << endl;
        printInputQueue.top()->print();
        printInputQueue.pop();
      }

      priority_queue<Process*> printOutputQueue(Output);
      while (!printOutputQueue.empty())
      {
        cout << "h.8" << endl;
        printOutputQueue.top()->print();
        printOutputQueue.pop();
      }

    }


    timer++;

    // Stops program
    if (Active == NULL && OActive == NULL && IActive == NULL && entryQueue.empty() && Ready.empty() && Input.empty() && Output.empty())
    {
      cout << "################################" << endl;
      cout << "Final Message. Run has ended." << endl;
      cout << "################################" << endl;
      cool = false;
    }

  }

  return 0;

}
