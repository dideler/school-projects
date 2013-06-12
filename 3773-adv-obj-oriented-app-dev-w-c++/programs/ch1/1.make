# makefile for Chapter 1
# run: make -f 1.make target
# For example:
# make -f 1.make ch1-ex1
LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

all: ch1-ex1 ch1-ex2 clean

OBJ1 = example.o intstack.o
ch1-ex1:	$(OBJ1)	
	$(CC) $(CFLAGS) $(OBJ1) $(LIB) -o ch1-ex1 
example.o:	example.cpp intstack.h
	$(CC) $(CFLAGS) -c example.cpp
intstack.o:	intstack.cpp intstack.h
	$(CC) $(CFLAGS) -c intstack.cpp 

OBJ2 = example2.o
ch1-ex2:	$(OBJ2)	
	$(CC) $(CFLAGS) $(OBJ2) $(LIB) -o ch1-ex2
example2.o:	example2.cpp
	$(CC) $(CFLAGS) -c example2.cpp

clean:
	rm *.o

