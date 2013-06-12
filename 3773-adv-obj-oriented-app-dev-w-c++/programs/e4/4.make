# makefile for exercises in Chapter 4
# run: make -f 4.make target
# eg: make -f 4.make all

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

all:  e4.3 e4.9 clean

OBJ3 = e4.3.o e4.3-integer.o 
e4.3:	$(OBJ3)
	$(CC) $(CFLAGS) $(OBJ3) $(CFLAGS) -o e4.3 
e4.3.o:	e4.3.cpp e4.3-integer.h 
	$(CC) $(CFLAGS) -c e4.3.cpp
e4.3-integer.o:	e4.3-integer.cpp e4.3-integer.h
	$(CC) $(CFLAGS) -c e4.3-integer.cpp

OBJ9 = e4.9.o e4.9-student.o e4.9-student-stack.o
e4.9:   $(OBJ9)
	$(CC) $(CFLAGS) $(OBJ9) $(LIB) -o e4.9
e4.9.o: e4.9.cpp e4.9-student.h
	$(CC) $(CFLAGS) -c e4.9.cpp
e4.9-student.o:        e4.9-student.cpp e4.9-student.h
	$(CC) $(CFLAGS) -c e4.9-student.cpp         
e4.9-student-stack.o:        e4.9-student-stack.cpp e4.9-student-stack.h e4.9-student.h
	$(CC) $(CFLAGS) -c e4.9-student-stack.cpp  

clean:
	rm *.o
