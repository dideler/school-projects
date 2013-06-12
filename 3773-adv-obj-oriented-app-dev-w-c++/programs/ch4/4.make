# makefile for Chapter 4
# run: make -f 4.make target
# eg: make -f 4.make all

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

all:  ex4.1 ex4.1a ex4.2 clean

OBJ1 = ex4.1.point.o ex4.1.point-d.o
ex4.1:	$(OBJ1)	
	$(CC) $(CFLAGS) $(OBJ1) $(LIB) -o ex4.1
ex4.1.point.o:	ex4.1.point.cpp ex4.1.point.h
	$(CC) $(CFLAGS) -c ex4.1.point.cpp 
ex4.1.point-d.o:	ex4.1.point-d.cpp ex4.1.point.h
	$(CC) $(CFLAGS) -c ex4.1.point-d.cpp

OBJ1a = ex4.1a.point.o ex4.1a.point-d.o
ex4.1a:	$(OBJ1a) 
	$(CC) $(CFLAGS) $(LIB) $(OBJ1a) -o ex4.1a
ex4.1a.point.o:	ex4.1a.point.cpp ex4.1a.point.h
	$(CC) $(CFLAGS) -c ex4.1a.point.cpp
ex4.1a.point-d.o:	ex4.1a.point-d.cpp ex4.1a.point.h
	$(CC) $(CFLAGS) -c ex4.1a.point-d.cpp 

OBJ2 = ex4.2.point.o ex4.2.point-d.o
ex4.2:	$(OBJ2) 
	$(CC) $(CFLAGS) $(LIB) $(OBJ2) -o ex4.2
ex4.2.point.o:	ex4.2.point.cpp ex4.2.point.h
	$(CC) $(CFLAGS) -c ex4.2.point.cpp
ex4.2.point-d.o:	ex4.2.point-d.cpp ex4.2.point.h
	$(CC) $(CFLAGS) -c ex4.2.point-d.cpp 

clean:
	rm *.o
