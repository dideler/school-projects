# makefile for exercises in Chapter 6
# run: make -f 6.make target
# eg: make -f 6.make all

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

all:  e6.2 e6.9 clean

OBJ2 = e6.2.o e6.2.intstack.o e6.2.der-intstack.o 
e6.2:	$(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) $(CFLAGS) -o e6.2 
e6.2.o:	e6.2.cpp e6.2.intstack.h e6.2.der-intstack.h
	$(CC) $(CFLAGS) -c e6.2.cpp
e6.2.intstack.o:	e6.2.intstack.cpp e6.2.intstack.h
	$(CC) $(CFLAGS) -c e6.2.intstack.cpp
e6.2.der-intstack.o:	e6.2.der-intstack.cpp e6.2.intstack.h e6.2.der-intstack.h
	$(CC) $(CFLAGS) -c e6.2.der-intstack.cpp
 
OBJ6 = e6.9.o e6.9-mystring.o 
e6.9:	$(OBJ6)
	$(CC) $(CFLAGS) $(OBJ6) $(LIB) -o e6.9
e6.9.o:	e6.9.cpp e6.9-mystring.h  e6.9-mystring-ifc.h
	$(CC) $(CFLAGS) -c e6.9.cpp
e6.9-mystring.o:	e6.9-mystring.cpp e6.9-mystring.h  e6.9-mystring-ifc.h  
	$(CC) $(CFLAGS) -c e6.9-mystring.cpp         

clean:
	rm *.o
