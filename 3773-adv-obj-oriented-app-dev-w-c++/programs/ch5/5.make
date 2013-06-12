# makefile for Chapter 5
# run: make -f 5.make target
# eg: make -f 5.make all

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

all:  ch5.1 ex5.1 ex5.2 ex5.3 ex5.4 ex5.5 clean

OBJ1 = ch5.student.o ch5.studentwithaccount-d.o ch5.studentwithaccount.o
ch5.1:	$(OBJ1)	
	$(CC) $(CFLAGS) $(OBJ1) $(LIB) -o ch5.1
ch5.student.o:	ch5.student.cpp ch5.student.h ch5.studentwithaccount.h
	$(CC) $(CFLAGS) -c ch5.student.cpp 
ch5.studentwithaccount-d.o:	ch5.studentwithaccount-d.cpp ch5.student.h ch5.studentwithaccount.h
	$(CC) $(CFLAGS) -c ch5.studentwithaccount-d.cpp 
ch5.studentwithaccount.o:	ch5.studentwithaccount.cpp ch5.student.h
	$(CC) $(CFLAGS) -c ch5.studentwithaccount.cpp

OBJ2 = ex5.1.bank.o ex5.1.student.o ex5.1.accountforstudent-d.o ex5.1.accountforstudent.o ex5.1.bankaccount.o 
ex5.1:	$(OBJ2)	
	$(CC) $(CFLAGS) $(OBJ2) $(LIB) -o ex5.1
ex5.1.accountforstudent.o:	ex5.1.accountforstudent.cpp ex5.1.student.h ex5.1.accountforstudent.h
	$(CC) $(CFLAGS) -c ex5.1.accountforstudent.cpp 
ex5.1.accountforstudent-d.o:	ex5.1.accountforstudent-d.cpp ex5.1.student.h ex5.1.accountforstudent.h
	$(CC) $(CFLAGS) -c ex5.1.accountforstudent-d.cpp 
ex5.1.bankaccount.o:	ex5.1.bankaccount.cpp ex5.1.accountforstudent.h ex5.1.bankaccount.h ex5.1.student.h
	$(CC) $(CFLAGS) -c ex5.1.bankaccount.cpp
ex5.1.bank.o:	ex5.1.bank.cpp ex5.1.bank.h
	$(CC) $(CFLAGS) -c ex5.1.bank.cpp

OBJ3 = ex5.2.myunderflow.o ex5.2.driver.o ex5.2.myoverflow.o
ex5.2:	$(OBJ3)	
	$(CC) $(CFLAGS) $(OBJ3) $(LIB) -o ex5.2
ex5.2.myunderflow.o:	ex5.2.myunderflow.cpp ex5.2.myunderflow.h 
	$(CC) $(CFLAGS) -c ex5.2.myunderflow.cpp
ex5.2.myoverflow.o:	ex5.2.myoverflow.cpp ex5.2.myoverflow.h
	$(CC) $(CFLAGS) -c ex5.2.myoverflow.cpp
ex5.2.driver.o:	ex5.2.driver.cpp ex5.2.myunderflow.h ex5.2.myoverflow.h
	$(CC) $(CFLAGS) -c ex5.2.driver.cpp 

OBJ4 = ex5.3.intstack.o ex5.3.intstack-d.o 
ex5.3:	$(OBJ4)	
	$(CC) $(CFLAGS) $(OBJ4) $(LIB) -o ex5.3
ex5.3.intstack.o:	ex5.3.intstack.cpp ex5.3.intstack.h 
	$(CC) $(CFLAGS) -c ex5.3.intstack.cpp 
ex5.3.intstack-d.o:	ex5.3.intstack-d.cpp ex5.3.intstack.h 
	$(CC) $(CFLAGS) -c ex5.3.intstack-d.cpp 

OBJ5 = ex5.4.benchmarkclass.o ex5.4.driver.o ex5.4.mybenchmarkclass.o
ex5.4:	$(OBJ5)	
	$(CC) $(CFLAGS) $(OBJ5) $(LIB) -o ex5.4
ex5.4.benchmarkclass.o:	ex5.4.benchmarkclass.cpp ex5.4.benchmarkclass.h ex5.4.mybenchmarkclass.h
	$(CC) $(CFLAGS) -c ex5.4.benchmarkclass.cpp 
ex5.4.driver.o:	ex5.4.driver.cpp ex5.4.benchmarkclass.h ex5.4.mybenchmarkclass.h
	$(CC) $(CFLAGS) -c ex5.4.driver.cpp 
ex5.4.mybenchmarkclass.o:	ex5.4.mybenchmarkclass.cpp ex5.4.benchmarkclass.h

OBJ6 = ex5.5.store.o ex5.5.driver.o ex5.5.downtownstore.o ex5.5.neighborhoodstore.o
ex5.5:	$(OBJ6)	
	$(CC) $(CFLAGS) $(OBJ6) $(LIB) -o ex5.5
ex5.5.store.o:	ex5.5.store.cpp ex5.5.store.h
	$(CC) $(CFLAGS) -c ex5.5.store.cpp 
ex5.5.driver.o:	ex5.5.driver.cpp ex5.5.store.h ex5.5.downtownstore.h ex5.5.neighborhoodstore.h
	$(CC) $(CFLAGS) -c ex5.5.driver.cpp
ex5.5.neighborhoodstore.o:	ex5.5.neighborhoodstore.cpp ex5.5.neighborhoodstore.h ex5.5.store.h
	$(CC) $(CFLAGS) -c ex5.5.neighborhoodstore.cpp
ex5.5.downtownstore.o:	ex5.5.downtownstore.cpp ex5.5.downtownstore.h ex5.5.store.h
	$(CC) $(CFLAGS) -c ex5.5.downtownstore.cpp
ex5.5.downtownstore.o:	ex5.5.downtownstore.cpp ex5.5.store.h

clean:
	rm *.o
