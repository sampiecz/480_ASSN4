# PROGRAM:    Assign 4 
# PROGRAMMER: Samuel Piecz
# LOGON ID:   Z1732715
# DATE DUE:   10/11/19
#

CCFLAGS = -ggdb -Wall -std=c++11

Assign4: Assign4.o Process.o Queue.o 
	g++ $(CCFLAGS) -o Assign4 Assign4.o Process.o Queue.o 

Assign4.o: Assign4.cxx Process.h Queue.h 
	g++ $(CCFLAGS) -c Assign4.cxx

Process.o: Process.cxx Process.h
	g++ $(CCFLAGS) -c Process.cxx

Queue.o: Queue.cxx Queue.h
	g++ $(CCFLAGS) -c Queue.cxx

#PriorityQueue.o: PriorityQueue.cxx PriorityQueue.h
#	g++ $(CCFLAGS) -c PriorityQueue.cxx

#PriorityQueue.h: Queue.h

clean:
	-rm *.o Assign4
