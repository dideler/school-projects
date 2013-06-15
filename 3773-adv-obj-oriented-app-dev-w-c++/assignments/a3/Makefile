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
	-rm -f *.o ex5.11 ex5.13
