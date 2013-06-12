# makefile for Chapter 7
# run: make -f 7.make target
# eg: make -f 7.make all

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

all:  e7.5 e7.13 clean

OBJ1 = e7.5-list.o e7.5.o 
e7.5:	$(OBJ1)	
	$(CC) $(CFLAGS) $(OBJ1) $(LIB) -o e7.5
e7.5-list.o:	e7.5-list.cpp e7.5-list.h 
	$(CC) $(CFLAGS) -c e7.5-list.cpp 
e7.5.o:	e7.5.cpp e7.5-list.h 
	$(CC) $(CFLAGS) -c e7.5.cpp 

OBJ2 = e7.13.o 
e7.13:	$(OBJ2)	
	$(CC) $(CFLAGS) $(OBJ2) $(LIB) -o e7.13
e7.13.o:	e7.13.cpp  e7.13-sort.cpp
	$(CC) $(CFLAGS) -c e7.13.cpp 

clean:
	rm *.o
