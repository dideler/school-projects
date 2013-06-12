# makefile for Chapter 3
# run: make -f 3.make target
# e.g.: make -f 3.make all
#
# Modified by D. Ideler, April 2013

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

all:  ex3.1 ex3.2 ex3.3 ex3.4 ex3.5 ch3-account clean

OBJ1 = ex3.1.student.o ex3.1.student-d.o
ex3.1:	$(OBJ1)	
	$(CC) $(CFLAGS) $(OBJ1) $(LIB) -o ex3.1
ex3.1.student.o:	ex3.1.student.cpp ex3.1.student.h
	$(CC) $(CFLAGS) -c ex3.1.student.cpp 
ex3.1.student-d.o:	ex3.1.student-d.cpp ex3.1.student.h
	$(CC) $(CFLAGS) -c ex3.1.student-d.cpp

OBJ2 = ex3.2.student.o ex3.2.student-d.o
ex3.2:	$(OBJ2) 
	$(CC) $(CFLAGS) $(LIB) $(OBJ2) -o ex3.2
ex3.2.student.o:	ex3.2.student.cpp ex3.2.student.h
	$(CC) $(CFLAGS) -c ex3.2.student.cpp
ex3.2.student-d.o:	ex3.2.student-d.cpp ex3.2.student.h
	$(CC) $(CFLAGS) -c ex3.2.student-d.cpp 

# macro D can be used for debugging: make "D =  -DDEB"
OBJ3 = ex3.3.fileops.o ex3.3.fileops-d.o
ex3.3:	$(OBJ3)
	$(CC) $(CFLAGS) $(OBJ3) -o ex3.3 
ex3.3.fileops.o:	ex3.3.fileops.cpp ex3.3.fileops.h
	$(CC) $(D) $(CFLAGS) -c ex3.3.fileops.cpp
ex3.3.fileops-d.o:	ex3.3.fileops-d.cpp ex3.3.fileops.h
	$(CC) $(CFLAGS) -c ex3.3.fileops-d.cpp

OBJ4 = ex3.4.integer.o ex3.4.integer-d.o
ex3.4:	$(OBJ4)
	$(CC) $(CFLAGS) $(LIB) $(OBJ4) -o ex3.4
ex3.4.o:	ex3.4.integer.cpp ex3.4.integer.h
	$(CC) $(CFLAGS) -c ex3.4.integer.cpp
ex3.4.integer-d.o:      ex3.4.integer-d.cpp ex3.4.integer.h
	$(CC) $(CFLAGS) -c ex3.4.integer-d.cpp

OBJ5 = ex3.5.intstack.o ex3.5.intstack-d.o
ex3.5:	$(OBJ5)
	$(CC) $(CFLAGS) $(LIB) $(OBJ5) -o ex3.5 
ex3.5.intstack.o:	ex3.5.intstack.cpp ex3.5.intstack.h
	$(CC) $(CFLAGS) -c ex3.5.intstack.cpp
ex3.5.intstack-d.o:	ex3.5.intstack-d.cpp ex3.5.intstack.h
	$(CC) $(CFLAGS) -c ex3.5.intstack-d.cpp

OBJA = ch3-account.o ex3.1.student.o ch3-account-d.o
ch3-account:	$(OBJA)
	$(CC) $(CFLAGS) $(LIB) $(OBJA) -o ch3-account
ch3-account.o:	ch3-account.cpp ch3-account.h
	$(CC) $(CFLAGS) -c ch3-account.cpp
#ex3.1.student.o:	ex3.1.student.cpp ex3.1.student.h
#	$(CC) $(CFLAGS) -c ex3.1.student.cpp
ch3-account-d.o:	ch3-account-d.cpp 
	$(CC) $(CFLAGS) -c ch3-account-d.cpp 

clean:
	rm *.o
