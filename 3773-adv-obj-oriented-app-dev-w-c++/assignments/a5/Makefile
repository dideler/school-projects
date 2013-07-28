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
all: ex7.11 clean

OBJ1 = 7.11-point.o 7.11-segment.o 7.11-list.o 7.11-test.o
ex7.11: $(OBJ1)
	$(CC) $(LFLAGS) $(OBJ1) -o ex7.11
7.11-point.o: 7.11-point.cpp 7.11-point.h
	$(CC) $(CFLAGS) 7.11-point.cpp
7.11-segment.o: 7.11-segment.cpp 7.11-segment.h
	$(CC) $(CFLAGS) 7.11-segment.cpp
7.11-segment.h: 7.11-point.h
7.11-list.o: 7.11-list.cpp 7.11-list.h
	$(CC) $(CFLAGS) 7.11-list.cpp
7.11-test.o: 7.11-test.cpp 7.11-segment.h 7.11-list.h
	$(CC) $(CFLAGS) 7.11-test.cpp

clean:
	-rm -f *.o

clean-all:
	-rm -f *.o ex7.11
