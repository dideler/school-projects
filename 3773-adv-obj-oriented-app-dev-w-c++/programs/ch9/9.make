# makefile for Chapter 6
# run: make -f 6.make target
# eg: make -f 6.make all

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

all:  ex9.1 ex9.2 ex9.3 clean

OBJ1 = ex9.1.o 
ex9.1:	$(OBJ1)	
	$(CC) $(CFLAGS) $(OBJ1) $(LIB) -o ex9.1
ex9.1.o:	ex9.1.cpp 
	$(CC) $(CFLAGS) -c ex9.1.cpp 

OBJ2 = ex9.2.o ex9.2.math.o
ex9.2:	$(OBJ2)	
	$(CC) $(CFLAGS) $(OBJ2) $(LIB) -o ex9.2
ex9.2.o:	ex9.2.cpp ex9.2.math.h ex9.2.mathifc.h
	$(CC) $(CFLAGS) -c ex9.2.cpp 
ex9.2.math.o:	ex9.2.math.cpp ex9.2.math.h ex9.2.mathifc.h
	$(CC) $(CFLAGS) -c ex9.2.math.cpp

OBJ3 =  ch9-regularfile.o ch9-file.o ch9-directoryfile.o ch9-specialfile.o ch9-countingvisitor.o ch9-showingvisitor.o ch9-driver.o
ex9.3:	$(OBJ3)	
	$(CC) $(CFLAGS) $(OBJ3) $(LIB) -o ex9.3

ch9-file.o:	ch9-file.cpp ch9-file.h	
	$(CC) $(CFLAGS) -c ch9-file.cpp

ch9-specialfile.o:	ch9-specialfile.cpp ch9-specialfile.h	
	$(CC) $(CFLAGS) -c ch9-specialfile.cpp

ch9-directoryfile.o:	ch9-directoryfile.cpp ch9-directoryfile.h	
	$(CC) $(CFLAGS) -c ch9-directoryfile.cpp

ch9-countingvisitor.o:	ch9-countingvisitor.cpp ch9-countingvisitor.h	
	$(CC) $(CFLAGS) -c ch9-countingvisitor.cpp

ch9-showingvisitor.o:	ch9-showingvisitor.cpp ch9-showingvisitor.h	
	$(CC) $(CFLAGS) -c ch9-showingvisitor.cpp

ch9-regularfile.o:	ch9-regularfile.cpp ch9-regularfile.h	
	$(CC) $(CFLAGS) -c ch9-regularfile.cpp

ch9-driver.o:	ch9-driver.cpp 
	$(CC) $(CFLAGS) -c ch9-driver.cpp

clean:
	rm *.o
