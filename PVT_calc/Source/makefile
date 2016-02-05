#compiler
CC=g++

#flags 
CFLAGS=-std=c++11

#libraries to link 
LIBS=-lm 

#Source files to be included 
SRCS=*.cpp

MAIN= fluidity

#simplest makefile possible
all: 
	$(CC) $(CFLAGS) $(SRCS) -o $(MAIN) $(LIBS)

#rules to clean source directory 
.PHONY: clean 

clean: 
	rm *.o $(MAIN)
