# makefile for Chapter 8
# run: make -f 8.make target
# eg: make -f 8.make all

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic -std=c++0x

all:  ex8.1 ex8.2 ex8.3 ex8.4 clean # removed ex8.5

OBJ1 = ex8.1.o 
ex8.1:	$(OBJ1)	
	$(CC) $(CFLAGS) $(OBJ1) $(LIB) -o ex8.1
ex8.1.o:	ex8.1.cpp ex8.1.shellsort.cpp
	$(CC) $(CFLAGS) -c ex8.1.cpp 

OBJ2 = ex8.2.o 
ex8.2:	$(OBJ2)	
	$(CC) $(CFLAGS) $(OBJ2) $(LIB) -o ex8.2
ex8.2.o:	ex8.2.cpp ex8.2.isprime.cpp
	$(CC) $(CFLAGS) -c ex8.2.cpp 

OBJ3 = ex8.3.o 
ex8.3:	$(OBJ3)	
	$(CC) $(CFLAGS) $(OBJ3) $(LIB) -o ex8.3
ex8.3.o:	ex8.3.cpp 
	$(CC) $(CFLAGS) -c ex8.3.cpp 

OBJ4 = ex8.4.o 
ex8.4:	$(OBJ4)	
	$(CC) $(CFLAGS) $(OBJ4) $(LIB) -o ex8.4
ex8.4.o:	ex8.4.cpp 
	$(CC) $(CFLAGS) -c ex8.4.cpp 

# This program has big issues and I'm not sure what it's supposed to do.
OBJ5 = ex8.5.o 
ex8.5:	$(OBJ5)	
	$(CC) $(CFLAGS) $(OBJ5) $(LIB) -o ex8.5
ex8.5.o:	ex8.5.cpp  ex8.5.property.cpp
	$(CC) $(CFLAGS) -c ex8.5.cpp 

clean:
	rm *.o
