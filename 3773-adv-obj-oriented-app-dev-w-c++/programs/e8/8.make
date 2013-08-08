# makefile for exercises in Chapter 8
# run: make -f 8.make target
# eg: make -f 8.make all

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

all:  e8.1 e8.14 clean

OBJ8 = e8.1.o e8.1-employee.o e8.1-company1.o e8.1-collection-ifc.o e8.1-company2.o e8.1-collection-list.o e8.1-collection-vector.o e8.1-collection-deque.o
e8.1: $(OBJ8)
	$(CC) $(CFLAGS) $(OBJ8) $(LIB) -o e8.1
e8.1.o: e8.1.cpp e8.1-employee.h e8.1-company1.h e8.1-collection-ifc.h e8.1-company2.h e8.1-collection-list.h e8.1-collection-vector.h e8.1-collection-deque.h
	$(CC) $(CFLAGS) -c e8.1.cpp
e8.1-employee.o: e8.1-employee.cpp e8.1-employee.h
	$(CC) $(CFLAGS) -c e8.1-employee.cpp         
e8.1-collection-ifc.o: e8.1-collection-ifc.cpp e8.1-collection-ifc.h
	$(CC) $(CFLAGS) -c e8.1-collection-ifc.cpp
e8.1-collection-list.o:	e8.1-collection-list.cpp e8.1-collection-list.h e8.1-collection-ifc.h
	 $(CC) $(CFLAGS) -c e8.1-collection-list.cpp
e8.1-collection-vector.o:	e8.1-collection-vector.cpp e8.1-collection-vector.h e8.1-employee.h
	$(CC) $(CFLAGS) -c e8.1-collection-vector.cpp
e8.1-collection-deque.o: e8.1-collection-deque.cpp e8.1-collection-deque.h e8.1-employee.h
	$(CC) $(CFLAGS) -c e8.1-collection-deque.cpp  
e8.1-company2.o: e8.1-company2.cpp e8.1-employee.h e8.1-collection-ifc.h e8.1-collection-list.h e8.1-collection-vector.h e8.1-collection-deque.h
	$(CC) $(CFLAGS) -c e8.1-company2.cpp
e8.1-company1.o: e8.1-company1.cpp e8.1-company1.h e8.1-employee.h e8.1-collection-ifc.h e8.1-collection-list.h e8.1-collection-vector.h e8.1-collection-deque.h
	$(CC) $(CFLAGS) -c e8.1-company1.cpp

OBJ14 = e8.14.o
e8.14:	$(OBJ14)
	$(CC) $(CFLAGS) $(OBJ14) $(LIB) -o e8.14
e8.14.o:	e8.14.cpp 
	$(CC) $(CFLAGS) -c e8.14.cpp 

clean:
	rm *.o
