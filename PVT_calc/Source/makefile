#compiler
CC=g++

#flags 
CFLAGS=-std=c++11

#libraries to link 
LIBS=-lm 

#Source files to be included 
SRCS=ComponentLib.cpp EquationOfState.cpp global.cpp LiquidDensity.cpp main.cpp PVT_calc.cpp PVT_Simulation.cpp SRK_EquationOfState.cpp utils.cpp VDW_EquationOfState.cpp

MAIN= fluidity

#simplest makefile possible
all: 
	$(CC) $(CFLAGS) $(SRCS) -o $(MAIN) $(LIBS)

#rules to clean source directory 
.PHONY: clean 

clean: 
	rm *.o $(MAIN)
