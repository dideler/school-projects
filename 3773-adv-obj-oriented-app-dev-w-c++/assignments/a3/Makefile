# @author Dennis Ideler <ideler.dennis@gmail.com>
#
# The basic syntax of a Makefile entry looks like:
# <target>: [ <dependency > ]*
#    [ <TAB> <command> <endl> ]+
#
# For more info on Makefiles:
# http://www.cs.umd.edu/class/fall2002/cmsc214/Tutorial/makefile.html

CC = clang++
STD = -std=c++0x  # Use the C++11 standard.
DEBUG = -g
OPTIMIZE = -O3
WARNINGS = -Wall -Wextra -Werror
CFLAGS = $(STD) $(WARNINGS) -c $(DEBUG) # Compiling flags
LFLAGS = $(STD) $(WARNINGS) $(DEBUG) # Linking flags

# If make is called without a target, it runs the first target, so this one.
all: ex5.11 ex5.13 clean

OBJ1 = 5.11-queue.o 5.11-test.o
ex5.11: $(OBJ1)
	$(CC) $(LFLAGS) $(OBJ1) -o ex5.11
5.11-queue.o: 5.11-queue.cpp 5.11-queue.h
	$(CC) $(CFLAGS) 5.11-queue.cpp
5.11-test.o: 5.11-test.cpp 5.11-queue.h
	$(CC) $(CFLAGS) 5.11-test.cpp

OBJ2 = 5.13-sort.o 5.13-mergesort.o 5.13-quicksort.o 5.13-test.o
ex5.13: $(OBJ2)
	$(CC) $(LFLAGS) $(OBJ2) -o ex5.13
5.13-sort.o: 5.13-sort.cpp 5.13-sort.h
	$(CC) $(CFLAGS) 5.13-sort.cpp
5.13-mergesort.o: 5.13-mergesort.cpp 5.13-mergesort.h 5.13-sort.h
	$(CC) $(CFLAGS) 5.13-mergesort.cpp
5.13-quicksort.o: 5.13-quicksort.cpp 5.13-quicksort.h 5.13-sort.h
	$(CC) $(CFLAGS) 5.13-quicksort.cpp
5.13-test.o: 5.13-test.cpp 5.13-sort.h 5.13-mergesort.h 5.13-quicksort.h
	$(CC) $(CFLAGS) 5.13-test.cpp

clean:
	-rm -f *.o

clean-all:
	-rm -f *.o ex5.11 ex5.13
