# makefile for Chapter 7
# run: make -f 7.make target
# eg: make -f 7.make all

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

all:  ch7.1 ch7.2 ch7.3 ex7.1 ex7.2 ex7.3 ex7.4a ex7.4 ex7.5 clean

OBJC1 = ch7-integernamespace-driver.o ch7.integernamespace.o
ch7.1:	$(OBJC1)
	$(CC) $(CFLAGS) $(OBJC1) $(LIB) -o ch7.1  
ch7-integernamespace-driver.o:	ch7-integernamespace-driver.cpp ch7.integernamespace.h
	$(CC) $(CFLAGS) -c ch7-integernamespace-driver.cpp
ch7.integernamespace.o:	ch7.integernamespace.cpp ch7.integernamespace.h
	$(CC) $(CFLAGS) -c ch7.integernamespace.cpp

OBJC2 = ch7-integernamespace-ext-driver.o ch7.integernamespace.o ch7.integernamespace.ext.o
ch7.2:	$(OBJC2)
	$(CC) $(CFLAGS) $(OBJC2) $(LIB) -o ch7.2  
ch7-integernamespace-ext-driver.o:	ch7-integernamespace-ext-driver.cpp ch7.integernamespace.h ch7.integernamespace.ext.h
	$(CC) $(CFLAGS) -c ch7-integernamespace-ext-driver.cpp
ch7.integernamespace.o:	ch7.integernamespace.cpp ch7.integernamespace.h
	$(CC) $(CFLAGS) -c ch7.integernamespace.cpp
ch7.integernamespace.ext.o:	ch7.integernamespace.ext.cpp ch7.integernamespace.h ch7.integernamespace.ext.h
	$(CC) $(CFLAGS) -c ch7.integernamespace.ext.cpp 

OBJC3 = ch7.integer.o ch7.integer-driver.o
ch7.3:	$(OBJC3)
	$(CC) $(CFLAGS) $(OBJC3) $(LIB) -o ch7.3
ch7.integer-driver.o:	ch7.integer-driver.cpp ch7.integer.h
	 $(CC) $(CFLAGS) -c ch7.integer-driver.cpp
ch7.integer.o:	ch7.integer.cpp ch7.integer.h
	$(CC) $(CFLAGS) -c ch7.integer.cpp

OBJ1 = ex7.1.list.o ex7.1.list-driver.o 
ex7.1:	$(OBJ1)	
	$(CC) $(CFLAGS) $(OBJ1) $(LIB) -o ex7.1
ex7.1.list.o:	ex7.1.list.cpp ex7.1.list.h 
	$(CC) $(CFLAGS) -c ex7.1.list.cpp 
ex7.1.list-driver.o:	ex7.1.list-driver.cpp ex7.1.list.h 
	$(CC) $(CFLAGS) -c ex7.1.list-driver.cpp 

OBJ2 = ex7.2.abstractlist.o ex7.2.list-driver.o ex7.2.list.o 
ex7.2:	$(OBJ2)	
	$(CC) $(CFLAGS) $(OBJ2) $(LIB) -o ex7.2
ex7.2.list.o:	ex7.2.list.cpp ex7.2.list.h 
	$(CC) $(CFLAGS) -c ex7.2.list.cpp 
ex7.2.list-driver.o:	ex7.2.list-driver.cpp ex7.2.abstractlist.h ex7.2.list.h  ex7.2.iterator.h
	$(CC) $(CFLAGS) -c ex7.2.list-driver.cpp
ex7.2.abstractlist.o:	ex7.2.abstractlist.cpp ex7.2.abstractlist.h 
	$(CC) $(CFLAGS) -c ex7.2.abstractlist.cpp 

OBJ3 = ex7.3-driver.o 
ex7.3:	$(OBJ3)	
	$(CC) $(CFLAGS) $(OBJ3) $(LIB) -o ex7.3
ex7.3-driver.o:	ex7.3-driver.cpp ex7.3.stack.cpp 
	$(CC) $(CFLAGS) -c ex7.3-driver.cpp 

OBJ4 = ex7.4-driver.o 
ex7.4:	$(OBJ4)	
	$(CC) $(CFLAGS) $(OBJ4) $(LIB) -o ex7.4
ex7.4-driver.o:	ex7.4-driver.cpp ex7.4.array.cpp 
	$(CC) $(CFLAGS) -c ex7.4-driver.cpp 

OBJ4a = ex7.4-driver.o 
ex7.4a:	$(OBJ4a)	
	$(CC) $(CFLAGS) $(OBJ4a) $(LIB) -o ex7.4a
ex7.4-driver.o:	ex7.4-driver.cpp ex7.4.array1.cpp 
	$(CC) $(CFLAGS) -c ex7.4-driver.cpp 

OBJ5 = ex7.5-driver.o 
ex7.5:	$(OBJ5)	
	$(CC) $(CFLAGS) $(OBJ5) $(LIB) -o ex7.5
ex7.5-driver.o:	ex7.5-driver.cpp  ex7.5.insertiosort.cpp
	$(CC) $(CFLAGS) -c ex7.5-driver.cpp 

clean:
	rm *.o
