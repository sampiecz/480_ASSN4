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

using std::string;
using std::endl;
using std::cout;
using std::cerr;
using std::getline;
using std::istringstream;
using std::ifstream;

int main()
{

    // Instantiate infile and line parser.
    ifstream infile("data4.txt");
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
        bool freshLine = true;
        string processName;

        // Get the line, that pesky bugger.
				istringstream iss(line);

        // Process name or cpu burst data? 
        if (line.length() >= 17)
        {
          cpuBurstData = true;
        }
        else
        {
          cpuBurstData = false;
        }

        cout << "It's a line!" << endl;

        // Loop line by line.
        if (!stopHere)
        {

          for (auto x : line)
          {

            // If not data, and fresh line generate process
            if (cpuBurstData == false && freshLine == true)
            {
              cout << "New process: " << x << endl;
              new Process(processName);
            }
            // If we have cpuBurstData use process setters 
            else if (cpuBurstData)
            {
              // Switch case for each char? 
              cout << "Burst data: " << x << endl;
            }
            // If cpuBurstData isn't true must be process name
            else if (cpuBurstData == false)
            {
              cout << "Process name: " << x << endl;
              processName += x; 
            }
            // Something is broken
            else
            {
              cerr << "ERROR" << endl; 
              exit(-1);
            }

            // Reset fresh line, not first char anymore
            freshLine = false;

          }

        }

		}

    return 0;

}
