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
all: ex4.4 ex4.6 clean

OBJ1 = 4.4-book.o 4.4-flower.o 4.4-gift.o 4.4-test.o
ex4.4: $(OBJ1)
	$(CC) $(LFLAGS) $(OBJ1) -o ex4.4
4.4-book.o: 4.4-book.cpp 4.4-book.h
	$(CC) $(CFLAGS) 4.4-book.cpp
4.4-flower.o: 4.4-flower.cpp 4.4-flower.h
	$(CC) $(CFLAGS) 4.4-flower.cpp
4.4-gift.o: 4.4-gift.cpp 4.4-gift.h
	$(CC) $(CFLAGS) 4.4-gift.cpp
4.4-gift.h: 4.4-book.h 4.4-flower.h
4.4-test.o: 4.4-test.cpp 4.4-gift.h
	$(CC) $(CFLAGS) 4.4-test.cpp

OBJ2 = 4.6-company1.o 4.6-company2.o 4.6-employee.o 4.6-test.o
ex4.6: $(OBJ2)
	$(CC) $(LFLAGS) $(OBJ2) -o ex4.6
4.6-employee.o: 4.6-employee.cpp 4.6-employee.h
	$(CC) $(CFLAGS) 4.6-employee.cpp
4.6-company1.o: 4.6-company1.cpp 4.6-company1.h
	$(CC) $(CFLAGS) 4.6-company1.cpp
4.6-company1.h: 4.6-employee.h
4.6-company2.o: 4.6-company2.cpp 4.6-company2.h
	$(CC) $(CFLAGS) 4.6-company2.cpp
4.6-test.o: 4.6-test.cpp 4.6-company1.h 4.6-company2.h
	$(CC) $(CFLAGS) 4.6-test.cpp

clean:
	-rm -f *.o

clean-all:
	-rm -f *.o ex4.4 ex4.6
