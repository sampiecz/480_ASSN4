# PROGRAM:    Assign 4 
# PROGRAMMER: Samuel Piecz
# LOGON ID:   Z1732715
# DATE DUE:   10/11/19
#

# Compiler variables
CCFLAGS = -ggdb -Wall -std=c++11

# Rule to link object code files to create executable file
Assign4: Assign4.o
	g++ $(CCFLAGS) -o Assign4 Assign4.o

# Rule to compile source code file to object code
Assign4.o: Assign4.cxx
	g++ $(CCFLAGS) -c Assign4.cxx

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o Assign4
