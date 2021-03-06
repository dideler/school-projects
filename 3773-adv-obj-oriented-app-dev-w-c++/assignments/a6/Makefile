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
WARNINGS = -Wall -Wextra -Werror -Weffc++
CFLAGS = $(STD) -c $(DEBUG) # Compiling flags
LFLAGS = $(STD) $(WARNINGS) $(DEBUG) # Linking flags

# If make is called without a target, it runs the first target, so this one.
all: ex8.5 ex8.9 clean

OBJ1 = 8.5-test.o
ex8.5: $(OBJ1)
	$(CC) $(LFLAGS) $(OBJ1) -o ex8.5
8.5-test.o: 8.5-test.cpp 8.5-safelist.h
	$(CC) $(CFLAGS) 8.5-test.cpp

OBJ2 = 8.9-point.o 8.9-test.o
ex8.9: $(OBJ2)
	$(CC) $(LFLAGS) $(OBJ2) -o ex8.9
8.9-point.o: 8.9-point.cpp 8.9-point.h
	$(CC) $(CFLAGS) 8.9-point.cpp
8.9-pointlist.h: 8.5-safelist.h
8.9-test.o: 8.9-test.cpp 8.9-point.h 8.9-pointlist.h
	$(CC) $(CFLAGS) 8.9-test.cpp

clean:
	-rm -f *.o

clean-all:
	-rm -f *.o ex8.5 ex8.9
