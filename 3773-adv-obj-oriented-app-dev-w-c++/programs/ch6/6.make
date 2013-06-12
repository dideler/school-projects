# makefile for Chapter 6
# run: make -f 6.make target
# eg: make -f 6.make all

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

all:  ex6.1 ex6.2 ex6.4a ex6.4 clean

OBJ1 = ex6.1.abstractfile.o ex6.1.fileops.o ex6.1.cachedfileops.o ex6.1.abstractapplication.o ex6.1.regularapplication.o ex6.1.cachedapplication.o ex6.1.driver.o
ex6.1:	$(OBJ1)	
	$(CC) $(CFLAGS) $(OBJ1) $(LIB) -o ex6.1
ex6.1.abstractfile.o:	ex6.1.abstractfile.cpp ex6.1.abstractfile.h
	$(CC) $(CFLAGS) -c ex6.1.abstractfile.cpp 
ex6.1.fileops.o:	ex6.1.fileops.cpp ex6.1.fileops.h ex6.1.abstractfile.h
	$(CC) $(CFLAGS) -c ex6.1.fileops.cpp 
ex6.1.cachedfileops.o:	ex6.1.cachedfileops.cpp ex6.1.fileops.h ex6.1.abstractfile.h ex6.1.cachedfileops.h
	$(CC) $(CFLAGS) -c ex6.1.cachedfileops.cpp 
ex6.1.abstractapplication.o:	ex6.1.abstractapplication.cpp ex6.1.abstractapplication.h ex6.1.abstractfile.h
	$(CC) $(CFLAGS) -c ex6.1.abstractapplication.cpp 
ex6.1.regularapplication.o:	ex6.1.regularapplication.cpp ex6.1.regularapplication.h ex6.1.abstractapplication.h ex6.1.fileops.h
	$(CC) $(CFLAGS) -c ex6.1.regularapplication.cpp 
ex6.1.cachedapplication.o:	ex6.1.cachedapplication.cpp ex6.1.cachedapplication.h ex6.1.abstractapplication.h ex6.1.cachedapplication.h
	$(CC) $(CFLAGS) -c ex6.1.cachedapplication.cpp 
ex6.1.driver.o:	ex6.1.fileops.h ex6.1.abstractfile.h ex6.1.cachedfileops.h ex6.1.abstractapplication.h ex6.1.regularapplication.h ex6.1.cachedapplication.h
	$(CC) $(CFLAGS) -c ex6.1.driver.cpp

OBJ2 = ex6.2.function.o ex6.2.polynomial.o ex6.2.rational.o ex6.2.functionfactory.o ex6.2.rationalfactory.o ex6.2.polynomialfactory.o ex6.2.driver.o
ex6.2:	$(OBJ2)	
	$(CC) $(CFLAGS) $(OBJ2) $(LIB) -o ex6.2
ex6.2.function.o:	ex6.2.function.cpp ex6.2.function.h
	$(CC) $(CFLAGS) -c ex6.2.function.cpp 
ex6.2.polynomial.o:	ex6.2.polynomial.cpp ex6.2.polynomial.h ex6.2.function.h
	$(CC) $(CFLAGS) -c ex6.2.polynomial.cpp 
ex6.2.rational.o:	ex6.2.rational.cpp ex6.2.polynomial.h ex6.2.function.h ex6.2.rational.h
	$(CC) $(CFLAGS) -c ex6.2.rational.cpp 
ex6.2.functionfactory.o:	ex6.2.functionfactory.cpp ex6.2.functionfactory.h ex6.2.function.h
	$(CC) $(CFLAGS) -c ex6.2.functionfactory.cpp 
ex6.2.rationalfactory.o:	ex6.2.rationalfactory.cpp ex6.2.rationalfactory.h ex6.2.functionfactory.h ex6.2.polynomial.h
	$(CC) $(CFLAGS) -c ex6.2.rationalfactory.cpp 
ex6.2.polynomialfactory.o:	ex6.2.polynomialfactory.cpp ex6.2.polynomialfactory.h ex6.2.functionfactory.h ex6.2.polynomialfactory.h
	$(CC) $(CFLAGS) -c ex6.2.polynomialfactory.cpp 
ex6.2.driver.o:	ex6.2.polynomial.h ex6.2.function.h ex6.2.rational.h ex6.2.functionfactory.h ex6.2.rationalfactory.h ex6.2.polynomialfactory.h
	$(CC) $(CFLAGS) -c ex6.2.driver.cpp

OBJ4a = ex6.4a.addition.o ex6.4a.binarynode.o ex6.4a.exponent.o ex6.4a.node.o ex6.4a.expression.o ex6.4a.operator.o ex6.4a.driver.o ex6.4a.operatorfactory.o ex6.4a.unarynode.o ex6.4a.valuenode.o ex6.4a.extandedoperatorfactory.o ex6.4a.multiplication.o ex6.4a.subtraction.o ex6.4a.division.o
ex6.4a:	$(OBJ4a)	
	$(CC) $(CFLAGS) $(OBJ4a) $(LIB) -o ex6.4a
ex6.4a.addition.o:	ex6.4a.addition.cpp ex6.4a.addition.h
	$(CC) $(CFLAGS) -c ex6.4a.addition.cpp 
ex6.4a.division.o:	ex6.4a.division.cpp ex6.4a.division.h 
	$(CC) $(CFLAGS) -c ex6.4a.division.cpp
ex6.4a.multiplication.o:	ex6.4a.multiplication.cpp ex6.4a.multiplication.h 
	$(CC) $(CFLAGS) -c ex6.4a.multiplication.cpp
ex6.4a.subtraction.o:	ex6.4a.subtraction.cpp ex6.4a.subtraction.h 
	$(CC) $(CFLAGS) -c ex6.4a.subtraction.cpp
ex6.4a.binarynode.o:	ex6.4a.binarynode.cpp ex6.4a.binarynode.h ex6.4a.addition.h
	$(CC) $(CFLAGS) -c ex6.4a.binarynode.cpp 
ex6.4a.exponent.o:	ex6.4a.exponent.cpp ex6.4a.binarynode.h ex6.4a.addition.h ex6.4a.exponent.h
	$(CC) $(CFLAGS) -c ex6.4a.exponent.cpp 
ex6.4a.node.o:	ex6.4a.node.cpp ex6.4a.node.h ex6.4a.addition.h
	$(CC) $(CFLAGS) -c ex6.4a.node.cpp 
ex6.4a.expression.o:	ex6.4a.expression.cpp ex6.4a.expression.h ex6.4a.node.h ex6.4a.binarynode.h
	$(CC) $(CFLAGS) -c ex6.4a.expression.cpp 
ex6.4a.operator.o:	ex6.4a.operator.cpp ex6.4a.operator.h ex6.4a.node.h ex6.4a.operator.h
	$(CC) $(CFLAGS) -c ex6.4a.operator.cpp 
ex6.4a.driver.o:	ex6.4a.driver.cpp ex6.4a.binarynode.h ex6.4a.addition.h ex6.4a.exponent.h ex6.4a.node.h ex6.4a.expression.h ex6.4a.operator.h
	$(CC) $(CFLAGS) -c ex6.4a.driver.cpp
ex6.4a.operatorfactory.o:	ex6.4a.operatorfactory.cpp ex6.4a.operatorfactory.h
	$(CC) $(CFLAGS) -c ex6.4a.operatorfactory.cpp 
ex6.4a.unarynode.o:	ex6.4a.unarynode.cpp ex6.4a.unarynode.h 
	$(CC) $(CFLAGS) -c ex6.4a.unarynode.cpp 
ex6.4a.valuenode.o:	ex6.4a.valuenode.cpp ex6.4a.valuenode.h
	$(CC) $(CFLAGS) -c ex6.4a.valuenode.cpp 

OBJ4 = ex6.4.binarynode.o ex6.4.node.o ex6.4.expression.o ex6.4.driver.o ex6.4.unarynode.o ex6.4.valuenode.o 
ex6.4:	$(OBJ4)	
	$(CC) $(CFLAGS) $(OBJ4) $(LIB) -o ex6.4
ex6.4.binarynode.o:	ex6.4.binarynode.cpp ex6.4.binarynode.h 
	$(CC) $(CFLAGS) -c ex6.4.binarynode.cpp 
ex6.4.node.o:	ex6.4.node.cpp ex6.4.node.h
	$(CC) $(CFLAGS) -c ex6.4.node.cpp 
ex6.4.expression.o:	ex6.4.expression.cpp ex6.4.node.h ex6.4.binarynode.h
	$(CC) $(CFLAGS) -c ex6.4.expression.cpp 
ex6.4.driver.o:	ex6.4.driver.cpp ex6.4.binarynode.h ex6.4.node.h ex6.4.expression.h 
	$(CC) $(CFLAGS) -c ex6.4.driver.cpp
ex6.4.unarynode.o:	ex6.4.unarynode.cpp ex6.4.unarynode.h 
	$(CC) $(CFLAGS) -c ex6.4.unarynode.cpp 
ex6.4.valuenode.o:	ex6.4.valuenode.cpp ex6.4.valuenode.h
	$(CC) $(CFLAGS) -c ex6.4.valuenode.cpp 

clean:
	rm *.o
