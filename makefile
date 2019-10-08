# PROGRAM:    Assign 4 
# PROGRAMMER: Samuel Piecz
# LOGON ID:   Z1732715
# DATE DUE:   10/11/19
#

CCFLAGS = -ggdb -Wall -std=c++11

Assign4: Assign4.o Process.o
	g++ $(CCFLAGS) -o Assign4 Assign4.o Process.o

Assign4.o: Assign4.cxx Process.h
	g++ $(CCFLAGS) -c Assign4.cxx

Process.o: Process.cxx Process.h
	g++ $(CCFLAGS) -c Process.cxx

clean:
	-rm *.o Assign4
