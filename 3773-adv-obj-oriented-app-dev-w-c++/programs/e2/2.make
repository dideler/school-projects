# makefile for exercises in Chapter 2
# run: make -f 2.make target
# eg: make -f 2.make all

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

all:  e2.3 e2.9 clean

e2.3:	e2.3.o 
	$(CC) $(CFLAGS) -o e2.3 $(LIB) e2.3.o
e2.3.o:	e2.3.cpp 
	$(CC) $(CFLAGS) -c e2.3.cpp

e2.9:	e2.9.o 
	$(CC) $(CFLAGS) -o e2.9 $(LIB) e2.9.o
e2.9.o:	e2.9.cpp 
	$(CC) $(CFLAGS) -c e2.9.cpp

clean:
	rm *.o
