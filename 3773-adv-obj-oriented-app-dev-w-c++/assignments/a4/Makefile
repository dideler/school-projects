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
all: ex6.3 ex6.10 clean

OBJ1 = 6.3-factory.o 6.3-encryption1_factory.o 6.3-encryption2_factory.o \
			 6.3-product.o 6.3-encryption1_product.o 6.3-encryption2_product.o \
			 6.3-test.o
ex6.3: $(OBJ1)
	$(CC) $(LFLAGS) $(OBJ1) -o ex6.3
6.3-factory.o: 6.3-factory.cpp 6.3-factory.h 6.3-product.h
	$(CC) $(CFLAGS) 6.3-factory.cpp
6.3-encryption1_factory.o: 6.3-encryption1_factory.cpp 6.3-encryption1_factory.h 6.3-factory.h
	$(CC) $(CFLAGS) 6.3-encryption1_factory.cpp
6.3-encryption2_factory.o: 6.3-encryption2_factory.cpp 6.3-encryption2_factory.h 6.3-factory.h
	$(CC) $(CFLAGS) 6.3-encryption2_factory.cpp
6.3-product.o: 6.3-product.cpp 6.3-product.h
	$(CC) $(CFLAGS) 6.3-product.cpp
6.3-encryption1_product.o: 6.3-encryption1_product.cpp 6.3-encryption1_product.h 6.3-product.h
	$(CC) $(CFLAGS) 6.3-encryption1_product.cpp
6.3-encryption2_product.o: 6.3-encryption2_product.cpp 6.3-encryption2_product.h 6.3-product.h
	$(CC) $(CFLAGS) 6.3-encryption2_product.cpp
6.3-test.o: 6.3-test.cpp 6.3-encryption1_product.h
	$(CC) $(CFLAGS) 6.3-test.cpp

OBJ2 = 5.13-sort.o 5.13-mergesort.o 5.13-quicksort.o 5.13-test.o
ex6.10: $(OBJ2)
	$(CC) $(LFLAGS) $(OBJ2) -o ex6.10
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
	-rm -f *.o ex6.3 ex6.10
