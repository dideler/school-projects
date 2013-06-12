# makefile for Chapter 2
# Run: make -f 2.make target
# E.g.: make -f 2.make all
#
# Modified by Dennis Ideler, March 2013

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

all:  ex2.1 ex2.2 ex2.3 ex2.4 ex2.5 ch2-maxMin ch2-index ch2-change clean

ex2.1:	ex2.1.o 
	$(CC) $(CFLAGS) -o ex2.1 $(LIB) ex2.1.o
ex2.1.o:	ex2.1.cpp 
	$(CC) $(CFLAGS) -c ex2.1.cpp

ex2.2:	ex2.2.o 
	$(CC) $(CFLAGS) -o ex2.2 $(LIB) ex2.2.o
ex2.2.o:	ex2.2.cpp 
	$(CC) $(CFLAGS) -c ex2.2.cpp

ex2.3:	ex2.3.o 
	$(CC) $(CFLAGS) -o ex2.3 $(LIB) ex2.3.o
ex2.3.o:	ex2.3.cpp 
	$(CC) $(CFLAGS) -c ex2.3.cpp

ex2.4:	ex2.4.o 
	$(CC) $(CFLAGS) -o ex2.4 $(LIB) ex2.4.o
ex2.4.o:	ex2.4.cpp 
	$(CC) $(CFLAGS) -c ex2.4.cpp

ex2.5:	ex2.5.o 
	$(CC) $(CFLAGS) -o ex2.5 $(LIB) ex2.5.o
ex2.5.o:	ex2.5.cpp 
	$(CC) $(CFLAGS) -c ex2.5.cpp

ch2-maxMin:	ch2-maxMin.o 
	$(CC) $(CFLAGS) -o ch2-maxMin $(LIB) ch2-maxMin.o
ch2-maxMin.o:	ch2-maxMin.cpp 
	$(CC) $(CFLAGS) -c ch2-maxMin.cpp

ch2-index:	ch2-index.o 
	$(CC) $(CFLAGS) -o ch2-index $(LIB) ch2-index.o
ch2-index.o:	ch2-index.cpp 
	$(CC) $(CFLAGS) -c ch2-index.cpp

ch2-change:	ch2-change.o
	$(CC) $(CFLAGS) -o ch2-change $(LIB) ch2-change.o
ch2-change.o:	ch2-change.cpp
	$(CC) $(CFLAGS) -c ch2-change.cpp

clean:
	rm *.o

