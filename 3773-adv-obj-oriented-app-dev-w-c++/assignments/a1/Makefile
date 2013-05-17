# @author Dennis Ideler <ideler.dennis@gmail.com>
#
# The basic syntax of a Makefile entry looks like:
# <target>: [ <dependency > ]*
#    [ <TAB> <command> <endl> ]+
#
# For more info on Makefiles:
# http://www.cs.umd.edu/class/fall2002/cmsc214/Tutorial/makefile.html

CC = g++
STD = -std=c++0x  # Use the C++11 standard.
DEBUG = -g
OPTIMIZE = -O3
WARNINGS = -Wall -Wextra -Werror
CFLAGS = $(STD) $(WARNINGS) -c $(DEBUG) # Compiling flags
LFLAGS = $(STD) $(WARNINGS) $(DEBUG) # Linking flags

# If make is called without a target, it runs the first target, so this one.
all: ex3.3 ex3.9 ex3.9v2 clean

OBJ1 = 3.3-point.o 3.3-line.o 3.3-test.o
ex3.3: $(OBJ1)
	$(CC) $(LFLAGS) $(OBJ1) -o ex3.3
3.3-point.o: 3.3-point.cpp 3.3-point.h
	$(CC) $(CFLAGS) 3.3-point.cpp
3.3-line.o:	3.3-line.cpp 3.3-line.h
	$(CC) $(CFLAGS) 3.3-line.cpp
3.3-line.h: 3.3-point.h
3.3-test.o: 3.3-test.cpp 3.3-line.h
	$(CC) $(CFLAGS) 3.3-test.cpp

OBJ2 = 3.9-book.o 3.9-flower.o 3.9-gift.o 3.9-test.o
ex3.9: $(OBJ2)
	$(CC) $(LFLAGS) $(OBJ2) -o ex3.9
3.9-book.o: 3.9-book.cpp 3.9-book.h
	$(CC) $(CFLAGS) 3.9-book.cpp
3.9-flower.o: 3.9-flower.cpp 3.9-flower.h
	$(CC) $(CFLAGS) 3.9-flower.cpp
3.9-gift.o: 3.9-gift.cpp 3.9-gift.h
	$(CC) $(CFLAGS) 3.9-gift.cpp
3.9-gift.h: 3.9-book.h 3.9-flower.h
3.9-test.o: 3.9-test.cpp 3.9-gift.h
	$(CC) $(CFLAGS) 3.9-test.cpp

# v2 (not part of the assignment) uses some more advanced features like
# inheritance, polymorphism, scoped enums, and operator overloading.
OBJ3 = 3.9v2-item.o 3.9v2-test.o 3.9v2-book.o 3.9v2-flower.o 3.9v2-gift.o
ex3.9v2: $(OBJ3)
	$(CC) $(LFLAGS) $(OBJ3) -o ex3.9v2
3.9v2-item.o: 3.9v2-item.cpp 3.9v2-item.h
	$(CC) $(CFLAGS) 3.9v2-item.cpp
3.9v2-book.o: 3.9v2-book.cpp 3.9v2-book.h
	$(CC) $(CFLAGS) 3.9v2-book.cpp
3.9v2-book.h: 3.9v2-item.h
3.9v2-flower.o: 3.9v2-flower.cpp 3.9v2-flower.h
	$(CC) $(CFLAGS) 3.9v2-flower.cpp
3.9v2-flower.h: 3.9v2-item.h
3.9v2-gift.o: 3.9v2-gift.cpp 3.9v2-gift.h
	$(CC) $(CFLAGS) 3.9v2-gift.cpp
3.9v2-gift.h: 3.9v2-book.h 3.9v2-flower.h
3.9v2-test.o: 3.9v2-test.cpp 3.9v2-gift.h
	$(CC) $(CFLAGS) 3.9v2-test.cpp

clean:
	-rm -f *.o

clean-all:
	-rm -f *.o ex3.3 ex3.9 ex3.9v2
