# makefile for exercises in Chapter 5
# run: make -f 5.make target
# eg: make -f 5.make all

LIB	= -lm
CC = g++
CFLAGS = -Wall -pedantic

all:  e5.2 e5.6 clean

OBJ2 = e5.2.o e5.2-book.o e5.2-tbook.o e5.2-rbook.o
e5.2:	$(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) $(CFLAGS) -o e5.2 
e5.2.o:	e5.2.cpp e5.2-book.h e5.2-tbook.h e5.2-rbook.h
	$(CC) $(CFLAGS) -c e5.2.cpp
e5.2-book.o:	e5.2-book.cpp e5.2-book.h
	$(CC) $(CFLAGS) -c e5.2-book.cpp
e5.2-tbook.o:	e5.2-tbook.cpp e5.2-book.h e5.2-tbook.h
	$(CC) $(CFLAGS) -c e5.2-tbook.cpp
e5.2-rbook.o:	e5.2-rbook.cpp e5.2-book.h e5.2-rbook.h
	$(CC) $(CFLAGS) -c e5.2-rbook.cpp
 
OBJ6 = e5.6.o e5.6-address.o e5.6-address-extended.o e5.6-address-post.o
e5.6:   $(OBJ6)
	$(CC) $(CFLAGS) $(OBJ6) $(LIB) -o e5.6
e5.6.o: e5.6.cpp e5.6-address.h
	$(CC) $(CFLAGS) -c e5.6.cpp
e5.6-address.o:        e5.6-address.cpp e5.6-address.h
	$(CC) $(CFLAGS) -c e5.6-address.cpp         
e5.6-address-extended.o:        e5.6-address-extended.cpp e5.6-address-extended.h e5.6-address.h
	$(CC) $(CFLAGS) -c e5.6-address-extended.cpp  
e5.6-address-post.o:	e5.6-address-post.cpp e5.6-address-post.h e5.6-address.h
	$(CC) $(CFLAGS) -c e5.6-address-post.cpp

clean:
	rm *.o
